#pragma once
#include <cstddef>
#include <cstdint>
#include <dice/hfe/IEventListener.hpp>
#include <dice/hfe/io/IInputFilter.hpp>
#include <string>

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
		LaunchArg_CheckForAvailablePatch,	 // only bf2
		LaunchArg_CheckForPatch,			 // only bf2
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
		LaunchArg_HackIgnoreAssets,				// TODO: disabled on server
		LaunchArg_DisableShaderCache,			// TODO: disabled on server
		LaunchArg_QuickShaderPermutation,		// only bf2 // TODO: disabled
												// on server
		LaunchArg_DeferredShaderPermutation,	// only bf2 // TODO:
												// disabled on server
		LaunchArg_MaxValidation,	   // only bf2 // TODO: disabled on server
		LaunchArg_LowSpecEmulation,	   // only bf2 // TODO: disabled on
									   // server
		LaunchArg_DumpAllConFiles,	   // TODO: disabled on server
		LaunchArg_CustomConFile,	   // TODO: disabled on server
		LaunchArg_Help,
		LaunchArg_Help2,
		LaunchArg_Ranked,
		LaunchArg_FileChangeMonitor,	// TODO: disabled on server
		LaunchArg_OverlayPath,			// only bf2142
		LaunchArg_PlayerPassword,		// only bf2
		LaunchArg_Developer,			// TODO: disabled on server
		LaunchArg_DisableSwiff,			// TODO: disabled on server
		LaunchArg_SwiffDebug,			// TODO: disabled on server
		LaunchArg_PlayNow,				// only bf2
		LaunchArg_Port,
		LaunchArg_PbPath,
		LaunchArg_KeepAINav,	  // TODO: disabled on server
		LaunchArg_GameName,		  // TODO: disabled on server
		LaunchArg_MenuName,		  // only bf2142 // TODO: disabled on server
		LaunchArg_Restart,		  // only bf2
		LaunchArg_RSConfig,		  // only bf2
		LaunchArg_SkipDXCheck,	  // only bf2
		LaunchArg_DropDynamicSpawns,	// only bf2
		LaunchArg_VideoOptions,			// only bf2142 // TODO: disabled on
										// server
		LaunchArg_QuickPermutation,		// only bf2142 // TODO: disabled on
										// server
		LaunchArg_NVPerfHUD,		// only bf2142 // TODO: disabled on server
		LaunchArg_EAAccountName,	// only bf2142
		LaunchArg_EAAccountPassword,	// only bf2142
		LaunchArg_SoldierName,			// only bf2142
		LaunchArg_Provider,				// only bf2142
		LaunchArg_Region,				// only bf2142
		LaunchArg_ServerInfoType		// only bf2142
	};
	class BF2;
	class BF2Console;
	class BF2EngineSetup;
	class BF2Log;
	class Demo;
	class Mutex;
	class TickCalculator;

	// BF2Engine size: 0x160 (validated from bf2: 0040b360)
	class BF2Engine : public io::IInputFilter, public IEventListener
	{
	public:
		BF2* m_bf2;
		BF2EngineSetup* m_setup;
		void* m_unknown20;
		BF2Console* m_console;
		void* m_unknown30;
		void* m_unknown38;
		void* m_unknown40;
		uint32_t m_unknown48;
		uint64_t m_unknown50;
		uint64_t m_unknown58;
		void* m_unknown60;
		uint32_t m_unknown6C;
		void* m_unknown70;
		void* m_unknown78;
		bool m_shouldQuit;
		uint8_t m_unkown81[7];
		std::string m_playerName;
		std::string m_launchArgs;
		bool m_menuActive;
		uint8_t m_unknown99[3];
#if defined(BF2142_SPECIFIC)
		uint8_t m_unknown9C;
#endif
		uint32_t m_unknown9C;
		BF2Log* m_log;
		uint8_t m_unknownA8[4];
		uint32_t m_unknownAC;
		uint8_t m_unknownB0[8];
		TickCalculator* m_tickCalculator;
		uint8_t m_unknownC0[72];
		Demo* m_demo;
		uint64_t m_unknown110;
		uint64_t m_unknown118;
		uint64_t m_unknown120;
		Mutex* m_unknown128;
		Mutex* m_unknown130;
		uint8_t m_unknown138[40];

	public:
		BF2Engine(BF2* p_Instance);
		virtual ~BF2Engine();
		virtual void filterGameInput(io::GameInput* p_GameInput) override;
		virtual void filterPlayerInput(io::PlayerInput* p_PlayerInput) override;
		virtual void handleEvent(
			EventCategory p_Category, uint32_t p_Unknown,
			EventNode* p_EventNode, void*) override;

	public:
		bool init(std::string& p_Param1);
		bool shutdown();
		bool mainLoop();
		bool initEngine();
		bool shutdownEngine();
		bool initLocalization();

		void closeLog();
		bool startGame(bool, bool);
		bool getMenuActive() const;
		void setMenuActive(bool);
		void initDefaultSettings();
		bool parseParameters(const std::string&);
		bool playDemo(bool, const std::string&);
		void quitNextFrame();
	};

	extern BF2Engine* g_bf2Engine;
	static void bf2ExitCallback(void*);
	static void initSettingsRepostitory();
#if defined(WIN32)
	// TODO
#else
	#if defined(BF2142_SPECIFIC)
	static_assert(sizeof(BF2Engine) == 0x168);
	static_assert(offsetof(dice::hfe::BF2Engine, m_bf2) == 0x10);
	static_assert(offsetof(dice::hfe::BF2Engine, m_log) == 0xA8);
	static_assert(offsetof(dice::hfe::BF2Engine, m_tickCalculator) == 0xC0);
	static_assert(offsetof(dice::hfe::BF2Engine, m_demo) == 0x110);
	#else
	static_assert(sizeof(BF2Engine) == 0x160);
	static_assert(offsetof(dice::hfe::BF2Engine, m_bf2) == 0x10);
	static_assert(offsetof(dice::hfe::BF2Engine, m_log) == 0xA0);
	static_assert(offsetof(dice::hfe::BF2Engine, m_tickCalculator) == 0xB8);
	static_assert(offsetof(dice::hfe::BF2Engine, m_demo) == 0x108);
	#endif
#endif
}	 // namespace dice::hfe
