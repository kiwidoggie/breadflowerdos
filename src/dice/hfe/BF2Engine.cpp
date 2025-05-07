#include "BF2Engine.hpp"
#include "Demo/Demo.hpp"
#include "TickCalculator.hpp"

using namespace dice::hfe;

BF2Engine* dice::hfe::bf2Engine = nullptr;

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

bool BF2Engine::init(std::string& p_Param1)
{
    // TODO: bf2: 004dcf20
    return true;
}

bool BF2Engine::mainLoop()
{
    // TODO: bf2: 004daa10
    return true;
}