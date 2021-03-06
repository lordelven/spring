
# This list was created using this *nix shell command:
# > find . -name "*.cpp" -or -name "*.c" | sort
# Then Sound/ stuff was removed, because it is now a separate static lib.
SET(sources_engine_System_common
		"${CMAKE_CURRENT_SOURCE_DIR}/AutohostInterface.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/BaseNetProtocol.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Config/ConfigHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Config/ConfigLocater.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Config/ConfigSource.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Config/ConfigVariable.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/CRC.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/EventBatchHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/EventClient.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/EventHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/GlobalConfig.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Info.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Input/InputHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Input/Joystick.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Input/KeyInput.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Input/MouseInput.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LoadSave/CregLoadSaveHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LoadSave/Demo.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LoadSave/DemoReader.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LoadSave/DemoRecorder.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LoadSave/LoadInterface.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LoadSave/LoadSaveHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LoadSave/LoadSaveInterface.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LoadSave/LuaLoadSaveHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LoadSave/SaveInterface.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LogOutput.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Matrix44f.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/MemPool.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Misc/RectangleOptimizer.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/NetProtocol.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Object.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/OffscreenGLContext.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Option.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Clipboard.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/CmdLineParams.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/errorhandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Misc.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/SharedLib.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/ScopedFileLock.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Threading.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Watchdog.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/WindowManagerHelper.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/SafeVector.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/SpringApp.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Sync/FPUCheck.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Sync/Logger.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Sync/SyncChecker.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Sync/SyncDebugger.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Sync/SyncTracer.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Sync/SyncedFloat3.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Sync/backtrace.c"
		"${CMAKE_CURRENT_SOURCE_DIR}/Sync/get_executable_name.c"
		"${CMAKE_CURRENT_SOURCE_DIR}/TdfParser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/TimeProfiler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/TimeUtil.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/UnsyncedRNG.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Util.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Vec2.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/float3.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/float4.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/mmgr.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/myMath.cpp"
	)
SET(sources_engine_System_creg
		"${CMAKE_CURRENT_SOURCE_DIR}/creg/Serializer.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/creg/VarTypes.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/creg/creg.cpp"
	)
SET(sources_engine_System_FileSystem
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/IArchive.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/ArchiveLoader.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/ArchiveScanner.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/BufferedArchive.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/CacheDir.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/DataDirLocater.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/DataDirsAccess.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/DirArchive.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/FileFilter.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/FileHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/FileSystem.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/FileSystemAbstraction.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/FileSystemInitializer.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/PoolArchive.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/SevenZipArchive.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/SimpleParser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/VFSHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/FileSystem/ZipArchive.cpp"
	)
SET(sources_engine_System_Log
		"${CMAKE_CURRENT_SOURCE_DIR}/Log/Backend.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Log/DefaultFilter.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Log/DefaultFormatter.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Log/LogSinkHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Log/LogUtil.c"
	)
SET(sources_engine_System_Log_sinkLogFile
		"${CMAKE_CURRENT_SOURCE_DIR}/Log/LogOutputSink.cpp"
	)
SET(sources_engine_System_Log_sinkStream
		"${CMAKE_CURRENT_SOURCE_DIR}/Log/StreamSink.cpp"
	)
SET(sources_engine_System_Log_sinkConsole
		"${CMAKE_CURRENT_SOURCE_DIR}/Log/ConsoleSink.cpp"
	)
SET(sources_engine_System_Net
		"${CMAKE_CURRENT_SOURCE_DIR}/Net/Connection.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Net/LocalConnection.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Net/PackPacket.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Net/ProtocolDef.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Net/RawPacket.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Net/Socket.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Net/UDPConnection.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Net/UDPListener.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Net/UnpackPacket.cpp"
	)
SET(sources_engine_System_Platform_Linux
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Linux/CrashHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Linux/SoLib.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Linux/X_MessageBox.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Linux/myX11.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Linux/thread_backtrace.cpp"
	)
SET(sources_engine_System_Platform_Mac
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Mac/CrashHandler.cpp"
	)
SET(sources_engine_System_Platform_Windows
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Win/CrashHandler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Win/DllLib.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Win/WinVersion.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Win/seh.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/Platform/Win/wsdl.cpp"
	)

### only use the target platform related directory
IF     (UNIX)
	SET(sources_engine_System
			${sources_engine_System_common}
			${sources_engine_System_creg}
			${sources_engine_System_FileSystem}
			${sources_engine_System_Log}
			${sources_engine_System_Log_sinkLogFile}
			${sources_engine_System_Net}
			${sources_engine_System_Platform_Linux}
		)
ELSEIF (WIN32)
	SET(sources_engine_System
			${sources_engine_System_common}
			${sources_engine_System_creg}
			${sources_engine_System_FileSystem}
			${sources_engine_System_Log}
			${sources_engine_System_Log_sinkLogFile}
			${sources_engine_System_Net}
			${sources_engine_System_Platform_Windows}
		)
ELSE   ()
	SET(sources_engine_System
			${sources_engine_System_common}
			${sources_engine_System_creg}
			${sources_engine_System_FileSystem}
			${sources_engine_System_Log}
			${sources_engine_System_Log_sinkLogFile}
			${sources_engine_System_Net}
		)
ENDIF  ()

MakeGlobal(sources_engine_System_common)
MakeGlobal(sources_engine_System_creg)
MakeGlobal(sources_engine_System_FileSystem)
MakeGlobal(sources_engine_System_Net)
MakeGlobal(sources_engine_System_Log)
MakeGlobal(sources_engine_System_Platform_Linux)
MakeGlobal(sources_engine_System_Platform_Mac)
MakeGlobal(sources_engine_System_Platform_Windows)
MakeGlobal(sources_engine_System)
