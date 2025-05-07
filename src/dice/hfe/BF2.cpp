#include "BF2.hpp"
#include "BF2Engine.hpp"

using namespace dice::hfe;

// bf2: 0040b330
bool BF2::init(std::string& p_Param1)
{
    // Initialize a new BF2Engine
    auto s_BF2Engine = new BF2Engine(this);
    m_bf2Engine = s_BF2Engine;

    if (s_BF2Engine == nullptr)
        return false;

    bf2Engine = s_BF2Engine;

    if (!m_bf2Engine->init(p_Param1))
        return false;

    // TODO
    /*
    memory::memory_update_modules((memory*)nullptr, p_Param1);
    std::string s_OutGSLoadLevel = "";
    dice::hfe::SettingsRepostitory::stringGet(settings, "GSLoadLevel", &s_OutGSLoadLevel);
    std::string s_OutGSJoinAddress = "";
    dice::hfe::SettingsRepostitory::stringGet(settings, "GSJoinAddress", &s_OutGSJoinAddress);
    int32_t s_OutPlayNow = 0;
    dice::hfe::SettingsRepostitory::intGet(settings, "playNow", &s_OutPlayNow);
    
    BF2Engine::getMenuActive();
    
    bool s_OutGSDedicated = false;
    dice::hfe::SettingsRepostitory::boolGet(settings, "GSDedicated", &s_OutGSDedicated);
    
    bool s_StartGame = s_OutGSDedicated || s_OutPlayNow || !s_OutGSJoinAddress.empty() || !s_OutGSLoadLevel.empty();
    if (s_StartGame)
    {
        m_bf2Engine->startGame(false, true);
    }
    */

    return true;
}

// bf2: 0040b290
bool BF2::run()
{
    return m_bf2Engine->mainLoop();
}
