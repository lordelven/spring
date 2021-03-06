/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SoundSource.h"

#include <climits>
#include <alc.h>
#include <SDL_timer.h>

#include "ALShared.h"
#include "EFX.h"
#include "IAudioChannel.h"
#include "OggStream.h"
#include "SoundLog.h"
#include "SoundBuffer.h"
#include "SoundItem.h"

#include "Sound.h" //remove when unified ElmoInMeters

#include "System/float3.h"
#include "System/Util.h"
#include "System/myMath.h"

float CSoundSource::referenceDistance = 200.0f;
float CSoundSource::globalPitch = 1.0;
float CSoundSource::heightRolloffModifier = 1.0f;



CSoundSource::CSoundSource()
	: curPlaying(NULL)
	, curChannel(NULL)
	, curStream(NULL)
	, curVolume(1.f)
	, loopStop(1e9)
	, in3D(false)
	, efxEnabled(false)
	, efxUpdates(0)
	, curHeightRolloffModifier(1)
{
	alGenSources(1, &id);
	if (!CheckError("CSoundSource::CSoundSource")) {
		id = 0;
	} else {
		alSourcef(id, AL_REFERENCE_DISTANCE, referenceDistance * CSound::GetElmoInMeters());
		CheckError("CSoundSource::CSoundSource");
	}
}

CSoundSource::~CSoundSource()
{
	if (efxEnabled) {
		alSource3i(id, AL_AUXILIARY_SEND_FILTER, AL_EFFECTSLOT_NULL, 0, AL_FILTER_NULL);
		alSourcei(id, AL_DIRECT_FILTER, AL_FILTER_NULL);
	}

	Stop();
	alDeleteSources(1, &id);
	CheckError("CSoundSource::~CSoundSource");
}

void CSoundSource::Update()
{
	if (curPlaying) {
		if (in3D && (efxEnabled != efx->enabled)) {
			alSourcef(id, AL_AIR_ABSORPTION_FACTOR, (efx->enabled) ? efx->airAbsorptionFactor : 0);
			alSource3i(id, AL_AUXILIARY_SEND_FILTER, (efx->enabled) ? efx->sfxSlot : AL_EFFECTSLOT_NULL, 0, AL_FILTER_NULL);
			alSourcei(id, AL_DIRECT_FILTER, (efx->enabled) ? efx->sfxFilter : AL_FILTER_NULL);
			efxEnabled = efx->enabled;
			efxUpdates = efx->updates;
		}

		if (heightRolloffModifier != curHeightRolloffModifier) {
			curHeightRolloffModifier = heightRolloffModifier;
			alSourcef(id, AL_ROLLOFF_FACTOR, curPlaying->rolloff * heightRolloffModifier);
		}

		if (!IsPlaying() || ((curPlaying->loopTime > 0) && (loopStop < SDL_GetTicks())))
			Stop();
	}

	if (curStream)
	{
		boost::recursive_mutex::scoped_lock lock(streamMutex);
		if (curStream->IsFinished()) {
			Stop();
		}
		else {
			curStream->Update();
			CheckError("CSoundSource::Update");
		}
	}

	if (efxEnabled && (efxUpdates != efx->updates)) {
		//! airAbsorption & LowPass aren't auto updated by OpenAL on change, so we need to do it per source
		alSourcef(id, AL_AIR_ABSORPTION_FACTOR, efx->airAbsorptionFactor);
		alSourcei(id, AL_DIRECT_FILTER, efx->sfxFilter);
		efxUpdates = efx->updates;
	}
}

int CSoundSource::GetCurrentPriority() const
{
	if (curStream) {
		return INT_MAX;
	}
	else if (!curPlaying) {
		return INT_MIN;
	}
	return curPlaying->priority;
}

bool CSoundSource::IsPlaying() const
{
	CheckError("CSoundSource::IsPlaying");
	ALint state;
	alGetSourcei(id, AL_SOURCE_STATE, &state);
	CheckError("CSoundSource::IsPlaying");
	return (state == AL_PLAYING || curStream);
}

void CSoundSource::Stop()
{
	alSourceStop(id);
	if (curPlaying) {
		curPlaying->StopPlay();
		curPlaying = NULL;
	}
	if (curStream) {
		boost::recursive_mutex::scoped_lock lock(streamMutex);
		delete curStream;
		curStream = NULL;
	}
	if (curChannel) {
		curChannel->SoundSourceFinished(this);
		curChannel = NULL;
	}
	CheckError("CSoundSource::Stop");
}

void CSoundSource::Play(IAudioChannel* channel, SoundItem* item, float3 pos, float3 velocity, float volume, bool relative)
{
	assert(!curStream);
	assert(channel);
	if (!item->PlayNow())
		return;
	Stop();
	curVolume = volume;
	curPlaying = item;
	curChannel = channel;
	alSourcei(id, AL_BUFFER, item->buffer->GetId());
	alSourcef(id, AL_GAIN, volume * item->GetGain() * channel->volume);
	alSourcef(id, AL_PITCH, item->GetPitch() * globalPitch);
	velocity *= item->dopplerScale * CSound::GetElmoInMeters();
	alSource3f(id, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
	alSourcei(id, AL_LOOPING, (item->loopTime > 0) ? AL_TRUE : AL_FALSE);
	loopStop = SDL_GetTicks() + item->loopTime;
	if (relative || !item->in3D) {
		in3D = false;
		if (efxEnabled) {
			alSource3i(id, AL_AUXILIARY_SEND_FILTER, AL_EFFECTSLOT_NULL, 0, AL_FILTER_NULL);
			alSourcei(id, AL_DIRECT_FILTER, AL_FILTER_NULL);
			efxEnabled = false;
		}
		alSourcei(id, AL_SOURCE_RELATIVE, AL_TRUE);
		alSourcef(id, AL_ROLLOFF_FACTOR, 0.f);
		alSource3f(id, AL_POSITION, 0.0f, 0.0f, -1.0f * CSound::GetElmoInMeters());
	} else {
		if (item->buffer->GetChannels() > 1) {
			LOG_L(L_WARNING, "Can not play non-mono \"%s\" in 3d.",
					item->buffer->GetFilename().c_str());
		}

		in3D = true;
		if (efx->enabled) {
			efxEnabled = true;
			alSourcef(id, AL_AIR_ABSORPTION_FACTOR, efx->airAbsorptionFactor);
			alSource3i(id, AL_AUXILIARY_SEND_FILTER, efx->sfxSlot, 0, AL_FILTER_NULL);
			alSourcei(id, AL_DIRECT_FILTER, efx->sfxFilter);
			efxUpdates = efx->updates;
		}
		alSourcei(id, AL_SOURCE_RELATIVE, AL_FALSE);
		pos *= CSound::GetElmoInMeters();
		alSource3f(id, AL_POSITION, pos.x, pos.y, pos.z);
		curHeightRolloffModifier = heightRolloffModifier;
		alSourcef(id, AL_ROLLOFF_FACTOR, item->rolloff * heightRolloffModifier);
#ifdef __APPLE__
		alSourcef(id, AL_MAX_DISTANCE, 1000000.0f);
		//! Max distance is too small by default on my Mac...
		ALfloat gain = channel->volume * item->GetGain() * volume;
		if (gain > 1.0f) {
			//! OpenAL on Mac cannot handle AL_GAIN > 1 well, so we will adjust settings to get the same output with AL_GAIN = 1.
			ALint model = alGetInteger(AL_DISTANCE_MODEL);
			ALfloat rolloff = item->rolloff * heightRolloffModifier;
			ALfloat ref = referenceDistance * CSound::GetElmoInMeters();
			if ((model == AL_INVERSE_DISTANCE_CLAMPED) || (model == AL_INVERSE_DISTANCE)) {
				alSourcef(id, AL_REFERENCE_DISTANCE, ((gain - 1.0f) * ref / rolloff) + ref);
				alSourcef(id, AL_ROLLOFF_FACTOR, (gain + rolloff - 1.0f) / gain);
				alSourcef(id, AL_GAIN, 1.0f);
			}
		} else {
			alSourcef(id, AL_REFERENCE_DISTANCE, referenceDistance * CSound::GetElmoInMeters());
		}
#endif
	}
	alSourcePlay(id);

	if (item->buffer->GetId() == 0) {
		LOG_L(L_WARNING,
				"CSoundSource::Play: Empty buffer for item %s (file %s)",
				item->name.c_str(), item->buffer->GetFilename().c_str());
	}
	CheckError("CSoundSource::Play");
}

void CSoundSource::PlayStream(IAudioChannel* channel, const std::string& file, float volume)
{
	boost::recursive_mutex::scoped_lock lock(streamMutex);

	//! stop any current playback
	Stop();

	if (!curStream)
		curStream = new COggStream(id);

	//! setup OpenAL params
	curChannel = channel;
	curVolume = volume;
	in3D = false;
	if (efxEnabled) {
		alSource3i(id, AL_AUXILIARY_SEND_FILTER, AL_EFFECTSLOT_NULL, 0, AL_FILTER_NULL);
		alSourcei(id, AL_DIRECT_FILTER, AL_FILTER_NULL);
		efxEnabled = false;
	}
	alSource3f(id, AL_POSITION,       0.0f, 0.0f, 0.0f);
	alSourcef(id, AL_GAIN,            volume);
	alSource3f(id, AL_VELOCITY,       0.0f,  0.0f,  0.0f);
	alSource3f(id, AL_DIRECTION,      0.0f,  0.0f,  0.0f);
	alSourcef(id, AL_ROLLOFF_FACTOR,  0.0f);
	alSourcei(id, AL_SOURCE_RELATIVE, AL_TRUE);

	//! COggStreams only appends buffers, giving errors when a buffer of another format is still assigned
	alSourcei(id, AL_BUFFER, AL_NONE);
	curStream->Play(file, volume);
	curStream->Update();
	CheckError("CSoundSource::Update");
}

void CSoundSource::StreamStop()
{
	if (!curStream)
		return;

	Stop();
}

void CSoundSource::StreamPause()
{
	if (!curStream)
		return;

	boost::recursive_mutex::scoped_lock lock(streamMutex);
	if (curStream->TogglePause())
		alSourcePause(id);
	else
		alSourcePlay(id);
}

float CSoundSource::GetStreamTime()
{
	if (!curStream)
		return 0;

	boost::recursive_mutex::scoped_lock lock(streamMutex);
	return curStream->GetTotalTime();
}

float CSoundSource::GetStreamPlayTime()
{
	if (!curStream)
		return 0;

	boost::recursive_mutex::scoped_lock lock(streamMutex);
	return curStream->GetPlayTime();
}

void CSoundSource::UpdateVolume()
{
	if (!curChannel)
		return;

	if (curStream) {
		alSourcef(id, AL_GAIN, curVolume * curChannel->volume);
	}
	else if (curPlaying) {
		alSourcef(id, AL_GAIN, curVolume * curPlaying->GetGain() * curChannel->volume);
	}
}
