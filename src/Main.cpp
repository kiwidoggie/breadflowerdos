#include <cstdint>
#include <memory>
#include <dice/hfe/System.hpp>

int main(int32_t p_argCount, const char** p_argVariables)
{
    // Initalize the system
    auto s_system = new dice::hfe::System();

    // Store the system in our global reference
    dice::hfe::g_system = s_system;

    return 0;
}