#include <cstdint>
#include <memory>
#include <sstream>
#include <iostream>
#include <dice/hfe/System.hpp>
#include <dice/hfe/BF2.hpp>

int main(int32_t p_argCount, const char** p_argVariables)
{
    int32_t s_unknown0;

    // Initalize the system
    auto s_system = new dice::hfe::System();

    // Store the system in our global reference
    dice::hfe::g_system = s_system;

    // Stream all the passed variabled
    std::ostringstream s_stream;
    for (int32_t i = 1; i != p_argCount; i++)
    {
        s_stream << p_argVariables[i];
        if (i != p_argCount - 1)
        {
            s_stream << " ";
        }
    }

    auto s_BF2 = new dice::hfe::BF2();

    std::string s_Unknown1; // This has to be parsed and set by above, but ghidra's a mess
    
    bool s_BF2Initalized = s_BF2->init(s_Unknown1);
    int32_t s_ReturnCode;

    // Run the main loop
    if (s_BF2Initalized)
    {
        bool s_Running = true;
        while(s_Running)
        {
            s_Running = s_BF2->run();
        }
        s_ReturnCode = 0;
    }
    else
    {
        s_ReturnCode = 0x2A;
        std::cerr << "fatal error: argument parsing failed" << std::endl;
    }

    return s_ReturnCode;
}