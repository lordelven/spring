
# This list was created using this *nix shell command:
# > find . -name "*.cpp"" | sort
SET(sources_engine_Lua
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaBitOps.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaCallInCheck.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaConstCMD.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaConstCMDTYPE.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaConstCOB.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaConstGL.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaConstGame.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaFBOs.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaFeatureDefs.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaFonts.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaGaia.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaHandle.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaHandleSynced.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaIO.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaInputReceiver.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaLobby.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaMaterial.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaMetalMap.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaOpenGL.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaOpenGLUtils.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaParser.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaPathFinder.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaRBOs.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaRules.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaRulesParams.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaScream.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaShaders.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaSyncedCall.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaSyncedCtrl.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaSyncedMoveCtrl.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaSyncedRead.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaSyncedTable.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaTextures.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaUnitDefs.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaUnitRendering.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaUnsyncedCall.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaUnsyncedCtrl.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaUnsyncedRead.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaUtils.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaVFS.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaWeaponDefs.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/LuaZip.cpp"
	)

MakeGlobal(sources_engine_Lua)
