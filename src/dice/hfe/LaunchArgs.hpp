#pragma once
#include <cstdint>

namespace dice::hfe
{
	enum LaunchArgs : int32_t
	{
		LaunchArg_Dedicated,
		LaunchArg_Multi,
		LaunchArg_JoinServer,
		LaunchArg_HostServer,
		LaunchArg_PlayerName,
		LaunchArg_Password,
#if defined(BF_2)
		LaunchArg_CheckForAvailablePatch,	 // only bf2
		LaunchArg_CheckForPatch,			 // only bf2
#endif
		LaunchArg_Config,
		LaunchArg_MapList,
		LaunchArg_LowPriority,
		LaunchArg_LoadLevel,
		LaunchArg_AIDll,	// TODO: disabled on server
		LaunchArg_UseAI,
		LaunchArg_WX,
		LaunchArg_WY,
		LaunchArg_SzX,
		LaunchArg_SzY,
		LaunchArg_Refresh,			 // TODO: disabled on server
		LaunchArg_LoadObfuscated,	 // TODO: disabled on server
		LaunchArg_Fullscreen,
		LaunchArg_NoSound,
		LaunchArg_LateLoading,					// TODO: disabled on server
		LaunchArg_RenderMode,					// TODO: disabled on server
		LaunchArg_RenderPath,					// TODO: disabled on server
		LaunchArg_DeviceType,					// TODO: disabled on server
		LaunchArg_DeviceBehavior,				// TODO: disabled on server
		LaunchArg_SkipMipLevels,				// TODO: disabled on server
		LaunchArg_SkipMeshLods,					// TODO: disabled on server
		LaunchArg_MergeMaterials,				// TODO: disabled on server
		LaunchArg_KeepTemplates,				// TODO: disabled on server
		LaunchArg_ManagedTextures,				// TODO: disabled on server
		LaunchArg_LoadedTextureDetailedInfo,	// TODO: disabled on server
		LaunchArg_LoadDebugMeshes,				// TODO: disabled on server
		LaunchArg_ConvertCollisionMeshes,		// TODO: disabled on server
		LaunchArg_SetMaxAllocSize,				// TODO: disabled on server
		LaunchArg_DebugNetwork,					// TODO: disabled on server
		LaunchArg_DebugGhostManager,			// TODO: disabled on server
		LaunchArg_DebugCallbackActive,			// TODO: disabled on server
		LaunchArg_Demo,
		LaunchArg_CompileConFiles,		   // TODO: disabled on server
		LaunchArg_UseCompiledConFiles,	   // TODO: disabled on server
		LaunchArg_NoEffectTextureAtlas,	   // TODO: disabled on server
		LaunchArg_PyVerboseFlag,		   // TODO: disabled on server
		LaunchArg_MaxPlayers,
		LaunchArg_GameMode,
		LaunchArg_ModPath,
		LaunchArg_MenuActive,	 // TODO: disabled on server
		LaunchArg_NoStatusMonitor,
		LaunchArg_HackIgnoreAssets,		 // TODO: disabled on server
		LaunchArg_DisableShaderCache,	 // TODO: disabled on server
#if defined(BF_2)
		LaunchArg_QuickShaderPermutation,		// only bf2 // TODO: disabled
												// on server
		LaunchArg_DeferredShaderPermutation,	// only bf2 // TODO:
												// disabled on server
		LaunchArg_MaxValidation,				// only bf2 // TODO: disabled on server
		LaunchArg_LowSpecEmulation,				// only bf2 // TODO: disabled on
												// server
#endif
		LaunchArg_DumpAllConFiles,	  // TODO: disabled on server
		LaunchArg_CustomConFile,	  // TODO: disabled on server
		LaunchArg_Help,
		LaunchArg_Help2,
		LaunchArg_Ranked,
		LaunchArg_FileChangeMonitor,	// TODO: disabled on server
#if defined(BF_2142)
		LaunchArg_OverlayPath,	  // only bf2142
#endif
#if defined(BF_2)
		LaunchArg_PlayerPassword,	 // only bf2
#endif
		LaunchArg_Developer,	   // TODO: disabled on server
		LaunchArg_DisableSwiff,	   // TODO: disabled on server
		LaunchArg_SwiffDebug,	   // TODO: disabled on server
#if defined(BF_2)
		LaunchArg_PlayNow,	  // only bf2
#endif
		LaunchArg_Port,
		LaunchArg_PbPath,
		LaunchArg_KeepAINav,	// TODO: disabled on server
		LaunchArg_GameName,		// TODO: disabled on server
#if defined(BF_2142)
		LaunchArg_MenuName,	   // only bf2142 // TODO: disabled on server
#endif
#if defined(BF_2)
		LaunchArg_Restart,				// only bf2
		LaunchArg_RSConfig,				// only bf2
		LaunchArg_SkipDXCheck,			// only bf2
		LaunchArg_DropDynamicSpawns,	// only bf2
#endif
#if defined(BF_2142)
		LaunchArg_VideoOptions,			// only bf2142 // TODO: disabled on
										// server
		LaunchArg_QuickPermutation,		// only bf2142 // TODO: disabled on
										// server
		LaunchArg_NVPerfHUD,			// only bf2142 // TODO: disabled on server
		LaunchArg_EAAccountName,		// only bf2142
		LaunchArg_EAAccountPassword,	// only bf2142
		LaunchArg_SoldierName,			// only bf2142
		LaunchArg_Provider,				// only bf2142
		LaunchArg_Region,				// only bf2142
		LaunchArg_ServerInfoType		// only bf2142
#endif
	};
}	 // namespace dice::hfe
