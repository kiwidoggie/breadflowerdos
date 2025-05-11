#include "Demo.hpp"
#include "Game_Main_demo.hpp"

using namespace dice::hfe;

Demo::Demo()
{

}

/**
 * @brief 
 * 
 * bf2: 004e6100
 * 
 * @param p_category 
 * @param p_param2 
 * @param p_node 
 * @param p_param4 
 */
void Demo::handleEvent(EventCategory p_category, uint32_t p_param2, EventNode* p_node, void* p_param4)
{
    if (p_param2 != 2)
        return;
    
    auto s_unknownVar0 = 1;

    if ((int32_t)(uint64_t)p_node != 8)
        s_unknownVar0 = g_enableTimeDemoStats;

    g_enableTimeDemoStats = s_unknownVar0;
}