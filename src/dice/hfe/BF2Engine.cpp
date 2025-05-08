#include "BF2Engine.hpp"
#include "Demo/Demo.hpp"
#include "TickCalculator.hpp"

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

    // TODO: ClassManager init
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
    return true;
}

// bf2: 004daa10
bool BF2Engine::mainLoop()
{
    // TODO: implement
    return true;
}