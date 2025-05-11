#include "BF2Engine.hpp"
#include "Demo/Demo.hpp"
#include "TickCalculator.hpp"
#include "Mutex.hpp"
#include "ClassManager.hpp"
#include "ISettingsRepostitory.hpp"
#include "io/SettingsManagerBase.hpp"
#include "BF2EngineSetup.hpp"

using namespace dice::hfe;

BF2Engine* dice::hfe::g_bf2Engine = nullptr;

// bf2: 004d4100
BF2Engine::BF2Engine(BF2* p_BF2Instance) :
    m_bf2(p_BF2Instance)
{
    // Create a new tick calculator
    m_tickCalculator = new TickCalculator(10, 30.0f);

    // Create a new demo instance
    m_demo = new Demo::Demo();

    // Create 2 new Mutex
    m_unknown128 = new Mutex();
    m_unknown130 = new Mutex();

    g_bf2Engine = this;
    g_classManager = new ClassManager();
}

BF2Engine::~BF2Engine()
{

}

void BF2Engine::filterGameInput([[maybe_unused]] dice::hfe::io::GameInput* p_GameInput)
{
    // TODO: Implement
}

// bf2: 004d38a0
void BF2Engine::filterPlayerInput([[maybe_unused]] dice::hfe::io::PlayerInput* p_PlayerInput)
{
    // TODO: Implement
}

// bf2: 004dd790 (unconfirmed)
void BF2Engine::handleEvent([[maybe_unused]] EventCategory p_Category, [[maybe_unsued]] uint32_t p_Unknown, [[maybe_unused]] EventNode* p_EventNode, void*)
{
    // TODO: Implement
}

// bf2: 004dcf20
bool BF2Engine::init([[maybe_unused]] std::string& p_Param1)
{
    // TODO: implement
    ISettingsRepostitory::createSingleton();
    initDefaultSettings();

    m_setup = new BF2EngineSetup(this);

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
    g_Settings->boolSet("GSMenu", false);
    g_Settings->stringSet("GSModDirectory", "mods/bf2");
    g_Settings->stringSet("GSLevelDirectory", "Levels/");

    io::g_SettingsManager->U32RegisterUserVar("GSPerfLogAtPlayerCount", 30, true, 0);
    io::g_SettingsManager->floatRegisterUserVar("GSDefaultLatencyCompensation", 0.1f, true, 0);
    io::g_SettingsManager->boolRegisterUserVar("GSUseLatencyCompensation", false, false, 0);
    io::g_SettingsManager->boolRegisterUserVar("GSUseClientSidePrediction", true, false, 0);
    io::g_SettingsManager->boolRegisterUserVar("GSDebugBitStream", false, false, 0);
    io::g_SettingsManager->stringRegisterUserVar("GSPlayerName", "DefaultPlayerName", true, 0);

    g_Settings->intSet("GSViewDistance", 850);
    g_Settings->boolSet("GSLoadObfuscated", true);

    io::g_SettingsManager->boolRegisterUserVar("GSFullScreen", true, false, 0);
    io::g_SettingsManager->boolRegisterUserVar("GSExtrapolateFrame", false, true, 0);
    io::g_SettingsManager->boolRegisterUserVar("GSShowNetGraph", false, true, 0);
    io::g_SettingsManager->boolRegisterUserVar("GSClPunkBuster", false, true, 0);
}
