#include "BF2Engine.hpp"
#include "Demo/Demo.hpp"
#include "TickCalculator.hpp"
#include "Mutex.hpp"
#include "ClassManager.hpp"
#include "ISettingsRepostitory.hpp"

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
    ISettingsRepostitory::createSingleton();
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
