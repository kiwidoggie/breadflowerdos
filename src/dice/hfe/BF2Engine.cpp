#include "BF2Engine.hpp"
#include "Demo.hpp"
#include "TickCalculator.hpp"
#include "Mutex.hpp"
#include "ClassManager.hpp"
#include "ISettingsRepostitory.hpp"
#include "io/SettingsManagerBase.hpp"
#include "BF2EngineSetup.hpp"
#include "BF2Log.hpp"
#include "BF2Console.hpp"
#include "EventManager.hpp"
#include "Debug.hpp"
#include "SimpleParser.hpp"
#include "ServerSettings.hpp"
#include "io/FileChangeManager.hpp"
#include "Profiler.hpp"
#include "io/OldConsole.hpp"
#include "GameServer.hpp"

using namespace dice::hfe;

BF2Engine* dice::hfe::g_bf2Engine = nullptr;

// bf2: 004d4100
BF2Engine::BF2Engine(BF2* p_BF2Instance) :
    m_bf2(p_BF2Instance), m_setup(nullptr), m_console(nullptr), m_shouldQuit(false)
{
    // Create a new tick calculator
    m_tickCalculator = new TickCalculator(10, 30.0f);

    // Create a new demo instance
    m_demo = new Demo();

    // Create 2 new Mutex
    m_unknown128 = new Mutex();
    m_unknown130 = new Mutex();

    g_bf2Engine = this;
    g_classManager = new ClassManager();
}

BF2Engine::~BF2Engine()
{

}

void BF2Engine::filterGameInput(dice::hfe::io::GameInput* p_GameInput)
{
    // TODO: Implement
}

// bf2: 004d38a0
void BF2Engine::filterPlayerInput(dice::hfe::io::PlayerInput* p_PlayerInput)
{
    // TODO: Implement
}

// bf2: 004dd790
void BF2Engine::handleEvent(EventCategory p_Category, uint32_t p_Unknown, EventNode* p_EventNode, void*)
{
    // TODO: Implement
    if (p_Category != EventCategory::ECCore)
    {
        return;
    }
}

// bf2: 004dcf20
bool BF2Engine::init(std::string& launchArgs)
{
    // TODO: implement

    m_log = new BF2Log();
    ISettingsRepostitory::createSingleton();
    initDefaultSettings();

    if (!parseParameters(launchArgs))
    {
        return false;
    }

    m_setup = new BF2EngineSetup(this);
    m_console = new BF2Console();
    m_unknownAC = 60;
    // systemInfo()->vtable0x38();

    if (!m_setup->initModules())
    {
        m_setup->shutdownModules();
        return false;
    }

    initSettingsRepostitory();
    g_eventManager->registerEventHandler(EventCategory::ECCore, this, 0);
    g_eventManager->registerEventHandler(EventCategory::ECMainMenu, this, 0);
    g_frameEventManager->registerEventHandler(EventCategory::ECMainMenu, this, 0);
    g_eventManager->registerEventHandler(EventCategory::UnknownB, this, 0);

    if (m_demo == nullptr || !g_eventManager->registerEventHandler(EventCategory::ECHud, m_demo, 100))
    {
        BF2_ERROR("Failed to register Demo as event handler for ECHud.");
    }

    if (!m_setup->initLateModules())
    {
        m_setup->shutdownModules();
        return false;
    }

    if (!initEngine())
    {
        shutdownEngine();
        return false;
    }

    io::g_mainConsole->setExitCallBack(bf2ExitCallback, this);

    bool fileChangeMonitor = false;
    g_settings->boolGet("GSFileChangeMonitor", fileChangeMonitor);
    if (fileChangeMonitor)
    {
        io::g_fileChangeManager->setEnable(true);
    }

    io::g_mainConsole->loadCommandHistory("Logs/BfCommandHistory.con");
    io::g_mainConsole->runFullAccess("Init.con", "", "", "", "", "", "", "", "");

    //PbServerInitialize();
    //io::g_mainConsole->setHandleCommandHook(HandleCommandHookPB);
    // g_debugDraw = new DebugDraw(); // TODO: verify ? cuz size 1

    if (m_thread != nullptr)
    {
        return true;
    }

    /*
    m_thread = new CheckServerAliveThread();

    if (m_thread != nullptr)
    {
        m_thread->start("CheckServerAliveThread", 2);
    }

    g_loadStat->registerAtIncLoadCallback(atIncLoadCallback);
    */
    return true;
}

// bf2: 0040b230
bool BF2Engine::shutdown()
{
    // TODO: implement
    return true;
}

// bf2: 004daa10
bool BF2Engine::mainLoop()
{
    if (m_shouldQuit)
    {
        return false;
    }

    // TODO: implement
    return true;
}

// bf2: 004dc600
bool BF2Engine::initEngine()
{
    if (g_profilerClient != nullptr)
    {
        g_profilerClient->getEnable(); // TODO: real code seems missing in bf2 linux server build.
    }

    if (!m_log->initDebugCallback())
    {
        return false;
    }

    io::g_mainConsole->setUseRelativePaths(true);

    if (!BF2EngineSetup::initFileSystem())
    {
        return false;
    }

    std::string modDirectory;
    g_settings->stringGet("GSModDirectory", modDirectory);
    /*
#ifdef BF2142_SPECIFIC
    if (compareIgnoreCase(modDirectory, "mods/bf2142") != 0)
    {
        io::g_fileManager->addPath("mods/bf2142");
    }
#else
    if (compareIgnoreCase(modDirectory, "mods/bf2") != 0)
    {
        io::g_fileManager->addPath("mods/bf2");
    }
#endif

    io::g_fileManager->addPath(modDirectory);
    
    if (!m_log->initLogFiles())
    {
        return false;
    }

    io::g_fileManager->permitMountArchives(true);
    io::g_mainConsole->runFullAccess("ServerArchives.con", "", "", "", "", "", "", "", "");
    io::g_fileManager->permitMountArchives(false);

    if (!initLocalization())
    {
        return false;
    }

    io::g_settingsManager->load("Settings/Usersettings.con");

    if (m_statusMonitor == nullptr)
    {
        bool statusMonitor = true;
        g_settings->boolGet("GSStatusMonitor", statusMonitor);

        if (statusMonitor)
        {
            m_statusMonitor = new StatusMonitor();
        }
    }

    auto modInfo = g_classManager->getSingleton("ModInfo");
    modInfo->init();

    if (m_setup->initRenderer() && !m_setup->initConsole())
    {
        return false;
    }

    if (!m_setup->initNetwork())
    {
        return false;
    }

    SingletonServer::init();
    */
    return true; // TODO
}

bool BF2Engine::shutdownEngine()
{
    return true; // TODO
}

// bf2: 004dc5f0
bool BF2Engine::initLocalization()
{
    // NOTE: This is not implemented on server

    // Implemented (server)
    return true;
}

// bf2: 004d37e0
void BF2Engine::closeLog()
{
    if (m_log != nullptr)
    {
        delete m_log;
    }
    m_log = nullptr;
}

// bf2: 004db530
bool BF2Engine::startGame(bool param1, bool)
{
    // TODO: Implement
    bool isServer = false;
    g_settings->boolGet("GSIsServer", isServer);
    
    if (!isServer)
    {
        /*
        SingletonRegInfo regInfo = SINGLETON_REG_INFO("Game", g_game, IID_IGame, CID_GameClient, 2);
        g_classManager->registerSingleton(regInfo);

        if (!g_game->init())
        {
            return false;
        }

        setGameLogic(CID_ClientGameLogic);
        if (!g_gameLogic->init())
        {
            return false;
        }

        m_log->renameAndReOpenPureLog("", "client");

        IGameClient* igameClient = static_cast<IGameClient*>(g_game->queryInterface(IID_IGameClient));
        if (igameClient == nullptr)
        {
            return true;
        }

        if (param1)
        {
            return true;
        }

        std::string joinAddress("127.0.0.1");
        g_settings->stringGet("GSJoinAddress", joinAddress);
        std::string password("");
        g_settings->stringGet("GSPassword", password);
        int32_t port = 16567;
        g_settings->intGet("GSPort", port);
        bool punkBuster = false;
        g_settings->boolGet("GSClPunkBuster", punkBuster);

        if(!igameClient->function0x38(joinAddress, port, password, punkBuster, 5.f))
        {
            shutdownGame(false);
            return false;
        }
        */

        return true;
    }

    SingletonRegInfo regInfo = SINGLETON_REG_INFO("Game", g_game, IID_IGame, CID_GameServer, 2);
    g_classManager->registerSingleton(regInfo);

    /*if (!g_game->init())
    {
        return false;
    }

    IGameServer* igameServer = static_cast<IGameServer*>(g_game->queryInterface(IID_IGameServer));
    if (igameServer == nullptr)
    {
        return false;
    }

    setGameLogic(CID_ServerGameLogic);

    if (!g_gameLogic->init())
    {
        return false;
    }

    int32_t outPort = 16567;
    g_settings->intGet("GSPort", outPort);

    if (outPort != 16567)
    {
        g_serverSettings->m_serverPort = outPort;
    }

    if(!igameServer->startServer(g_serverSettings->m_serverIP, g_serverSettings->m_serverPort, 0))
    {
        shutdownGame(false);
        return false;
    }
    */
    return true;
}

// bf2: 004d3830
bool BF2Engine::getMenuActive() const
{
    // NOTE: This is not implemented on server
    // return m_menuActive;

    // Implemented (server)
    return false;
}

void dice::hfe::BF2Engine::setMenuActive(bool active)
{
    m_menuActive = active;
}

// bf2: 004d47b0
void BF2Engine::initDefaultSettings()
{
    g_settings->boolSet("GSMenu", false);

#if defined(BF2142_SPECIFIC)
    g_settings->stringSet("GSModDirectory", "mods/bf2142");
#else
    g_settings->stringSet("GSModDirectory", "mods/bf2");
#endif
    g_settings->stringSet("GSLevelDirectory", "Levels/");

    io::g_settingsManager->U32RegisterUserVar("GSPerfLogAtPlayerCount", 30, true, 0);
    io::g_settingsManager->boolRegisterUserVar("GSUseObjectCache", true, true, 0);
    io::g_settingsManager->U32RegisterUserVar("GSInterpolationTime", 100, true, 0);
    io::g_settingsManager->U32RegisterUserVar("GSExtrapolationTime", 1200, true, 0);
    io::g_settingsManager->floatRegisterUserVar("GSDefaultLatencyCompensation", 0.1f, true, 0);
    io::g_settingsManager->boolRegisterUserVar("GSUseLatencyCompensation", false, false, 0);
    io::g_settingsManager->boolRegisterUserVar("GSUseClientSidePrediction", true, false, 0);
    io::g_settingsManager->boolRegisterUserVar("GSDebugBitStream", false, false, 0);
    io::g_settingsManager->stringRegisterUserVar("GSPlayerName", "DefaultPlayerName", true, 0);

    g_settings->intSet("GSViewDistance", 850);
    g_settings->boolSet("GSLoadObfuscated", true);

    io::g_settingsManager->boolRegisterUserVar("GSFullScreen", true, false, 0);
    io::g_settingsManager->boolRegisterUserVar("GSExtrapolateFrame", false, true, 0);
    io::g_settingsManager->boolRegisterUserVar("GSShowNetGraph", false, true, 0);
    io::g_settingsManager->boolRegisterUserVar("GSClPunkBuster", false, true, 0);
#if defined(BF2142_SPECIFIC)
    io::g_settingsManager->boolRegisterUserVar("GSCameraShake", true, true, 0);
#endif
}

bool BF2Engine::parseParameters(std::string const& launchArgs)
{
    m_launchArgs = launchArgs;

    std::string joinServerAddress;
    std::string levelToLoad;
    std::string aiDLL("AIDLL.dll");

    uint32_t renderPath = 3;
    uint32_t deviceType = 1;
    uint32_t deviceBehavior = 80;

    // TODO: default on server builds is true, but on client it's false.
    bool isDedicated = true;
    bool isServer = true;
    bool useAI = false;
    bool useEffectTextureAtlas = true;

    if (!launchArgs.empty())
    {
        SimpleParser simpleParser;
        {
        simpleParser.add(LaunchArgs::LaunchArg_Help, "help", "Displays this help");
        simpleParser.add(LaunchArgs::LaunchArg_Help2, "?", "Same as +help");
        simpleParser.add(LaunchArgs::LaunchArg_Dedicated, "dedicated", "Start in dedicated server mode");
        simpleParser.add(LaunchArgs::LaunchArg_Multi, "multi", "Allow starting multiple BF2 instances");
        simpleParser.add(LaunchArgs::LaunchArg_Config, "config", "Sets path to the ServerSettings.con file to use");
        simpleParser.add(LaunchArgs::LaunchArg_RSConfig, "rsconfig", "Sets path to the ReservedSlots.con file to use"); // only bf2
        simpleParser.add(LaunchArgs::LaunchArg_MapList, "mapList", "Sets the path to the MapList.con file to use");
        simpleParser.add(LaunchArgs::LaunchArg_PbPath, "pbPath", "Set the path to use for PunkBuster on multi-instance configurations (defaults to {install_dir}/pb");
        simpleParser.add(LaunchArgs::LaunchArg_JoinServer, "joinServer", "Join a server by ip address or hostname");
        simpleParser.add(LaunchArgs::LaunchArg_Port, "port", "specifies the network port to be used");
        simpleParser.add(LaunchArgs::LaunchArg_Password, "password", "Set the server password when joining a server");
#ifdef BF2142_SPECIFIC
        simpleParser.add(LaunchArgs::LaunchArg_ModPath, "modPath", "Set the mod path (default mods/bf2142)");
#else
        simpleParser.add(LaunchArgs::LaunchArg_ModPath, "modPath", "Set the mod path (default mods/bf2)");
#endif
        simpleParser.add(LaunchArgs::LaunchArg_CheckForAvailablePatch, "checkForAvailablePatch", ""); // only bf2
        simpleParser.add(LaunchArgs::LaunchArg_CheckForPatch, "checkForPatch", ""); // only bf2
        simpleParser.add(LaunchArgs::LaunchArg_UseAI, "ai", "");
        simpleParser.add(LaunchArgs::LaunchArg_Fullscreen, "fullscreen", "Start game in full screen mode");
        simpleParser.add(LaunchArgs::LaunchArg_WX, "wx", "Position game window on the screen at certain x-position");
        simpleParser.add(LaunchArgs::LaunchArg_WY, "wy", "Position game window on the screen at certain y-position");
        simpleParser.add(LaunchArgs::LaunchArg_SzX, "szx", "Set resolution width");
        simpleParser.add(LaunchArgs::LaunchArg_SzY, "szy", "Set resolution height");
        simpleParser.add(LaunchArgs::LaunchArg_NoSound, "noSound", "Start game without sound");
        simpleParser.add(LaunchArgs::LaunchArg_Restart, "restart", "Used when restarting executable."); // only bf2
        simpleParser.add(LaunchArgs::LaunchArg_SkipDXCheck, "skipDXCheck", "Skips DirectX version check. Use with caution."); // only bf2
        simpleParser.add(LaunchArgs::LaunchArg_OverlayPath, "overlayPath", "Start game with a custom path for configuration files"); // only bf2142
        simpleParser.add(LaunchArgs::LaunchArg_Ranked, "ranked", "Allows gamespy snapshot sending");
        simpleParser.add(LaunchArgs::LaunchArg_NoStatusMonitor, "noStatusMonitor", "Start game without status monitor screen");
        simpleParser.add(LaunchArgs::LaunchArg_Demo, "demo", "Sets the con-file with demo options");
        simpleParser.add(LaunchArgs::LaunchArg_LoadLevel, "loadLevel", "Set the level to load");
        simpleParser.add(LaunchArgs::LaunchArg_PlayerName, "playerName", "Set the player name");
        simpleParser.add(LaunchArgs::LaunchArg_EAAccountName, "eaAccountName", "Auto-login with the specified EA Account Name"); // only bf2142
        simpleParser.add(LaunchArgs::LaunchArg_EAAccountPassword, "eaAccountPassword", "Password to the specified EA Account Name"); // only bf2142
        simpleParser.add(LaunchArgs::LaunchArg_SoldierName, "soldierName", "Auto-login to a soldier in the specified EA Account Name"); // only bf2142
        simpleParser.add(LaunchArgs::LaunchArg_PlayerPassword, "playerPassword", "Set the player password"); // only bf2
        simpleParser.add(LaunchArgs::LaunchArg_PlayNow, "playNow", "use playnow functionality"); // only bf2
        simpleParser.add(LaunchArgs::LaunchArg_HostServer, "hostServer", "");
        simpleParser.add(LaunchArgs::LaunchArg_LowPriority, "lowPriority", "Run the game with slightly lower priority");
        simpleParser.add(LaunchArgs::LaunchArg_GameMode, "gameMode", "Sets the game mode.");
        simpleParser.add(LaunchArgs::LaunchArg_MaxPlayers, "maxPlayers", "Sets max players.");
        simpleParser.add(LaunchArgs::LaunchArg_DropDynamicSpawns, "dropDynamicSpawns", "Don\'t re-add dynamic spawn groups as round (re)starts."); // only bf2
        simpleParser.add(LaunchArgs::LaunchArg_Provider, "provider", ""); // only bf2142
        simpleParser.add(LaunchArgs::LaunchArg_Region, "region", ""); // only bf2142
        simpleParser.add(LaunchArgs::LaunchArg_ServerInfoType, "type", ""); // only bf2142
        }

        std::list<std::pair<int32_t, std::string>> paramList;
        if (simpleParser.parseString(launchArgs, paramList))
        {
            for (auto& [id, value] : paramList)
            {
                switch ((LaunchArgs)id)
                {
                case LaunchArgs::LaunchArg_Dedicated:
                    isDedicated = true;
                    break;
                case LaunchArgs::LaunchArg_Multi:
                    g_settings->boolSet("GSAllowMultipleInstances", true);
                    break;
                case LaunchArgs::LaunchArg_JoinServer:
                    isServer = false;
                    joinServerAddress = value;
                    break;
                case LaunchArgs::LaunchArg_HostServer:
                    isServer = true;
                    break;
                case LaunchArgs::LaunchArg_PlayerName:
                    m_playerName = value;
                    break;
                case LaunchArgs::LaunchArg_Password:
                    g_settings->stringSet("GSPassword", value);
                    break;
                case LaunchArgs::LaunchArg_CheckForAvailablePatch:
                    break; // TODO: missing on bf2 server
                case LaunchArgs::LaunchArg_CheckForPatch:
                    break; // TODO: missing on bf2 server
                case LaunchArgs::LaunchArg_Config:
                    g_serverSettings->m_configFile = value;
                    break;
                case LaunchArgs::LaunchArg_MapList:
                    // TODO: fix
                    // g_mapList = value;
                    break;
                case LaunchArgs::LaunchArg_LowPriority:
                    break; // TODO: missing on bf2 server
                case LaunchArgs::LaunchArg_LoadLevel:
                    levelToLoad = value;
                    break;
                case LaunchArgs::LaunchArg_AIDll:
                    if (!value.empty())
                    {
                        aiDLL = value;
                    }
                    break;
                case LaunchArgs::LaunchArg_UseAI:
                    useAI = true;
                    break;
                case LaunchArgs::LaunchArg_WX:
                    // TODO: Vars::set("opt-window-x", value);
                    break;
                case LaunchArgs::LaunchArg_WY:
                    // TODO: Vars::set("opt-window-y", value);
                    break;
                case LaunchArgs::LaunchArg_SzX:
                    g_settings->intSet("GSWindowSizeX", std::stol(value));
                    break;
                case LaunchArgs::LaunchArg_SzY:
                    g_settings->intSet("GSWindowSizeY", std::stol(value));
                    break;
                case LaunchArgs::LaunchArg_Refresh:
                    g_settings->intSet("GSRefresh", std::stol(value));
                    break;
                case LaunchArgs::LaunchArg_LoadObfuscated:
                    g_settings->boolSet("GSLoadObfuscated", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_Fullscreen:
                    g_settings->boolSet("GSFullscreen", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_NoSound:
                    // TODO: Vars::set("opt-nosound", value);
                    break; 
                case LaunchArgs::LaunchArg_LateLoading:
                    // TODO: Vars::set("opt-late-loading", value);
                    break;
                case LaunchArgs::LaunchArg_RenderMode:
                    // TODO: Vars::set("opt-render-mode", value);
                    break;
                case LaunchArgs::LaunchArg_RenderPath:
                    renderPath = std::stol(value);
                    if (renderPath != 2 && renderPath != 3)
                    {
                        renderPath = 3;
                    }
                    break;
                case LaunchArgs::LaunchArg_DeviceType:
                    deviceType = std::stol(value);
                    if (deviceType != 1 && deviceType != 2)
                    {
                        deviceType = 1;
                    }
                    break;
                case LaunchArgs::LaunchArg_DeviceBehavior:
                    deviceBehavior = std::stol(value);
                    if (deviceBehavior != 32 && deviceBehavior != 64 && deviceBehavior != 80)
                    {
                        deviceBehavior = 80;
                    }
                    break;
                case LaunchArgs::LaunchArg_SkipMipLevels:
                    g_settings->intSet("GSSkipMipLevels", std::stol(value));
                    break;
                case LaunchArgs::LaunchArg_SkipMeshLods:
                    g_settings->intSet("GSSkipMeshLods", std::stol(value));
                    break;
                case LaunchArgs::LaunchArg_MergeMaterials:
                    g_settings->boolSet("GSMergeMaterials", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_KeepTemplates:
                    g_settings->boolSet("GSKeepTemplates", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_ManagedTextures:
                    g_settings->boolSet("GSManagedTextures", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_LoadedTextureDetailedInfo:
                    g_settings->boolSet("GSLoadedTextureDetailedInfo", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_LoadDebugMeshes:
                    // TODO: Vars::set("coll-load-debugmeshes", value);
                    break;
                case LaunchArgs::LaunchArg_ConvertCollisionMeshes:
                    // TODO: Vars::set("phy-convert-collision-meshes", "1");
                    break;
                case LaunchArgs::LaunchArg_SetMaxAllocSize:
                    if (std::stol(value) == 1)
                    {
                        // TODO: memory::set_max_alloc_size(26000000);
                    }
                    break;
                case LaunchArgs::LaunchArg_DebugNetwork:
                    g_settings->boolSet("GSDebugNetwork", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_DebugGhostManager:
                    g_settings->boolSet("GSDebugGhostManager", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_DebugCallbackActive:
                    if (std::stol(value) == 0)
                    {
                        // TODO: m_log->setDebugCallbackDisabled(true);
                    }
                    break;
                case LaunchArgs::LaunchArg_Demo:
                    g_settings->stringSet("GSDemo", value);
                    setMenuActive(false);
                    isServer = false;
                    break;
                case LaunchArgs::LaunchArg_CompileConFiles:
                    g_settings->boolSet("GLCompileConFiles", true);
                    break;
                case LaunchArgs::LaunchArg_UseCompiledConFiles:
                    g_settings->boolSet("GLUseCompiledConFiles", true);
                    break;
                case LaunchArgs::LaunchArg_NoEffectTextureAtlas:
                    useEffectTextureAtlas = std::stol(value) != 1;
                    break;
                case LaunchArgs::LaunchArg_PyVerboseFlag:
                    // TODO: Py_VerboseFlag = std::stol(value);
                    break;
                case LaunchArgs::LaunchArg_MaxPlayers:
                    g_settings->intSet("GSMaxNrOfPlayers", std::stol(value));
                    g_settings->intSet("GSCommandLineMaxNrOfPlayers", std::stol(value));
                    break;
                case LaunchArgs::LaunchArg_GameMode:
                    g_settings->stringSet("GSGameMode", value);
                    g_settings->stringSet("GSCommandLineGameMode", value);
                    break;
                case LaunchArgs::LaunchArg_ModPath:
                    g_settings->stringSet("GSModDirectory", value);
                    break;
                case LaunchArgs::LaunchArg_MenuActive:
                    if (std::stol(value) == 0)
                    {
                        setMenuActive(false);
                    }
                    break;
                case LaunchArgs::LaunchArg_NoStatusMonitor:
                    g_settings->boolSet("GSStatusMonitor", std::stol(value) == 0);
                    break;
                case LaunchArgs::LaunchArg_HackIgnoreAssets:
                    // TODO: Vars::set("hack-ignore-asserts", value);
                    break;
                case LaunchArgs::LaunchArg_DisableShaderCache:
                    g_settings->boolSet("GSDisableShaderCache", std::stol(value) != 0);
                    g_settings->boolSet("GSFileChangeMonitor", true);
                    break;
                case LaunchArgs::LaunchArg_QuickShaderPermutation:
                    g_settings->boolSet("GSQuickShaderPermutation", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_DeferredShaderPermutation:
                    g_settings->boolSet("GSDeferredShaderPermutation", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_MaxValidation:
                    g_settings->boolSet("GSMaxValidation", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_LowSpecEmulation:
                    g_settings->boolSet("GSLowSpecEmulation", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_DumpAllConFiles:
                    g_settings->boolSet("GSDumpAllConFiles", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_CustomConFile:
                    g_settings->stringSet("GSCustomConFile", value);
                    break;
                case LaunchArgs::LaunchArg_Help:
                case LaunchArgs::LaunchArg_Help2:
                    // TODO: simpleParser->showHelp("BF2.exe"); // BF2142.exe
                    return false;
                case LaunchArgs::LaunchArg_Ranked:
                    g_settings->boolSet("GSRanked", true);
                    break;
                case LaunchArgs::LaunchArg_FileChangeMonitor:
                    g_settings->boolSet("GSFileChangeMonitor", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_OverlayPath:
                    g_settings->stringSet("GSOverlayPath", value);
                    break;
                case LaunchArgs::LaunchArg_PlayerPassword:
                    g_settings->stringSet("GSPlayerPassword", value);
                    break;
                case LaunchArgs::LaunchArg_Developer:
                    g_settings->boolSet("GSDeveloper", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_DisableSwiff:
                    // TODO: Vars::set("disable-swiff", value);
                    break;
                case LaunchArgs::LaunchArg_SwiffDebug:
                    g_settings->intSet("swiffDebug", std::stol(value));
                    break;
                case LaunchArgs::LaunchArg_PlayNow:
                    g_settings->intSet("playNow", std::stol(value));
                    break;
                case LaunchArgs::LaunchArg_Port:
                    g_settings->intSet("GSPort", std::stol(value));
                    break;
                case LaunchArgs::LaunchArg_PbPath:
                    g_settings->stringSet("GSPunkBusterPath", value);
                    break;
                case LaunchArgs::LaunchArg_KeepAINav:
                    g_settings->boolSet("keepAINav", true);
                    break;
                case LaunchArgs::LaunchArg_GameName:
                    g_settings->stringSet("gameName", value);
                    break;
                case LaunchArgs::LaunchArg_MenuName:
                    if (value.ends_with(".dfm"))
                    { 
                        g_settings->stringSet("menuName", value);
                    }
                    break;
                case LaunchArgs::LaunchArg_Restart:
                    g_settings->boolSet("skipMovies", true);
                    break;
                case LaunchArgs::LaunchArg_RSConfig:
                    // TODO: g_reservedSlots->setConfigFile(value);
                    break;
                case LaunchArgs::LaunchArg_SkipDXCheck:
                    g_settings->boolSet("GSSkipDXCheck", true);
                    break;
                case LaunchArgs::LaunchArg_DropDynamicSpawns:
                    g_settings->boolSet("dropDynamicSpawns", true);
                    break;
                case LaunchArgs::LaunchArg_VideoOptions:
                    g_settings->stringSet("GSVideoOptions", value);
                    break;
                case LaunchArgs::LaunchArg_QuickPermutation:
                    g_settings->boolSet("quickPermutation", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_NVPerfHUD:
                    g_settings->boolSet("NVPerfHUD", std::stol(value) != 0);
                    break;
                case LaunchArgs::LaunchArg_EAAccountName:
                    g_settings->stringSet("eaAccountName", value);
                    break;
                case LaunchArgs::LaunchArg_EAAccountPassword:
                    g_settings->stringSet("eaAccountPassword", value);
                    break;
                case LaunchArgs::LaunchArg_SoldierName:
                    m_playerName = value;
                    break;
                case LaunchArgs::LaunchArg_Provider:
                    g_settings->stringSet("ServerInfoProvider", value);
                    break;
                case LaunchArgs::LaunchArg_Region:
                    g_settings->stringSet("ServerInfoRegion", value);
                    break;
                case LaunchArgs::LaunchArg_ServerInfoType:
                    g_settings->intSet("ServerInfoType", std::stol(value));
                    break;
                default:
                    break;
                }
            }
        }
    }

    std::string path;
    g_settings->stringGet("GSOverlayPath", path);
    if (path.empty())
    {
#ifdef BF2142_SPECIFIC
        std::string modPath("mods/bf2142");
#else
        std::string modPath("mods/bf2");
#endif
        g_settings->stringGet("GSModDirectory", modPath);
        path = modPath + "/";
    }

    if (g_serverSettings->m_configFile.empty())
    {
        g_serverSettings->m_configFile = path + "Settings/serversettings.con";
    }
    /* TODO
    if (g_reservedSlots->getConfigFile().empty())
    {
        g_reservedSlots->setConfigFile(path + "Settings/reservedSlots.con");
    }
    if (g_mapList->m_configFile.empty())
    {
        g_mapList->m_configFile = path + "Settings/maplist.con";
    }*/

    g_settings->boolSet("GSIsServer", isServer);
    g_settings->boolSet("GSDedicated", isDedicated);
    // TODO: Vars::set("opt-nosound", "1"; // TODO: makes no sense on client. Add server check?
    g_settings->intSet("GSRenderPath", renderPath);
    g_settings->intSet("GSDeviceType", deviceType);
    g_settings->intSet("GSDeviceBehavior", deviceBehavior);
    g_settings->boolSet("GSUseEffectTextureAtlas", useEffectTextureAtlas);

    if (!isServer)
    {
        g_settings->stringSet("GSJoinAddress", joinServerAddress);
    }
    else
    {
        g_settings->stringSet("GSJoinAddress", "");
        g_settings->stringSet("GSLoadLevel", levelToLoad);
    }

    g_settings->stringSet("AIDLL", aiDLL);
    g_settings->boolSet("UseAI", useAI);

    return true;
}

// bf2: 004dc0a0
bool BF2Engine::playDemo(bool, std::string const&)
{
    // TODO: Implement
    return true;
}

void BF2Engine::quitNextFrame()
{
    m_shouldQuit = true;
}

void dice::hfe::bf2ExitCallback(void* bf2Engine)
{
    if (bf2Engine != nullptr)
    {
        ((BF2Engine*)bf2Engine)->quitNextFrame();
    }
}

void dice::hfe::initSettingsRepostitory()
{
    g_eventManager->registerEvent(EventCategory::ECCore, 1, "ECCoreCEChangedSetting");
}
