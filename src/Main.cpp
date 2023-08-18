#include <cstdint>
#include <memory>
#include <dice/hfe/System.hpp>

int main(int32_t p_argCount, const char** p_argVariables)
{
    int32_t s_unknown0;

    // Initalize the system
    auto s_system = new dice::hfe::System();

    // Store the system in our global reference
    dice::hfe::g_system = s_system;

    if (1 < p_argCount)
    {
        s_unknown0 = 1;
        do
        {
            
        } while (p_argCount != s_unknown0);
        
    }

    return 0;
}