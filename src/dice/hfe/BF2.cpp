#include "BF2.hpp"
#include "BF2Engine.hpp"

using namespace dice::hfe;

// bf2: 0040b330
bool BF2::init(std::string& p_Param1)
{
    // Initialize a new BF2Engine
    auto s_BF2Engine = new BF2Engine(this);
    m_bf2Engine = s_BF2Engine;

    // TODO
    return true;
}

// bf2: 0040b290
bool BF2::run()
{
    return m_bf2Engine->mainLoop();
}
