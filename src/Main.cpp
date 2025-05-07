#include <cstdint>
#include <memory>
#include <dice/hfe/System.hpp>
#include <dice/hfe/BF2.hpp>

int main(int32_t p_argCount, const char** p_argVariables)
{
    int32_t s_unknown0;

    // Initalize the system
    auto s_system = new dice::hfe::System();

    // Store the system in our global reference
    dice::hfe::g_system = s_system;

    // TODO: Still needs work bf2: 0040b713
    if (1 < p_argCount)
    {
        s_unknown0 = 1;
        do
        {
            
        } while (p_argCount != s_unknown0);
        
    }

    auto s_BF2 = new dice::hfe::BF2();

    std::string s_Unknown1; // This has to be parsed and set by above, but ghidra's a mess
    
    bool s_BF2Initalized = s_BF2->init(s_Unknown1);

    return 0;
}