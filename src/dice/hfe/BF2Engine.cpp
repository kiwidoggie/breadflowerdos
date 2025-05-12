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

using namespace dice::hfe;

BF2Engine* dice::hfe::g_bf2Engine = nullptr;

// bf2: 004d4100
BF2Engine::BF2Engine(BF2* p_BF2Instance) :
    m_bf2(p_BF2Instance)
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

}

// bf2: 004d38a0
void BF2Engine::filterPlayerInput(dice::hfe::io::PlayerInput* p_PlayerInput)
{
    // TODO: Implement
}

// bf2: 004dd790 (unconfirmed)
void BF2Engine::handleEvent(EventCategory p_Category, uint32_t p_Unknown, EventNode* p_EventNode, void*)
{
    // TODO: Implement
}

// bf2: 004dcf20
bool BF2Engine::init(std::string& p_Param1)
{
    // TODO: implement

    m_log = new BF2Log();
    ISettingsRepostitory::createSingleton();
    initDefaultSettings();

    if (!parseParameters(p_Param1))
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
    //g_frameEventManager->registerEventHandler(EventCategory::ECMainMenu, this, 0);
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

    return true;
}

// bf2: 004daa10
bool BF2Engine::mainLoop()
{
    // TODO: implement
    return true;
}

// bf2: 004dc600
bool BF2Engine::initEngine()
{
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
    // TODO: Implement

    /*
    if ((long *)this->field39_0xa0 != (long *)0x0) {
        (**(code **)(*(long *)this->field39_0xa0 + 8))();
    }
    this->field39_0xa0 = 0;
  */
}

// bf2: 004db530
bool BF2Engine::startGame(bool, bool)
{
    // TODO: Implement
    return true;
}

// bf2: 004d3830
bool BF2Engine::getMenuActive() const
{
    // NOTE: This is not implemented on server

    // Implemented (server)
    return false;
}

// bf2: 004d47b0
void BF2Engine::initDefaultSettings()
{
    g_settings->boolSet("GSMenu", false);
    g_settings->stringSet("GSModDirectory", "mods/bf2");
    g_settings->stringSet("GSLevelDirectory", "Levels/");

    io::g_settingsManager->U32RegisterUserVar("GSPerfLogAtPlayerCount", 30, true, 0);
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
}

bool BF2Engine::parseParameters(std::string const&)
{
    return true;
}

void dice::hfe::initSettingsRepostitory()
{
    g_eventManager->registerEvent(EventCategory::ECCore, 1, "ECCoreCEChangedSetting");
}
