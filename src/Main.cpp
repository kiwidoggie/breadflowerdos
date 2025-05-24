#include <cstdint>
#include <dice/hfe/BF2.hpp>
#include <dice/hfe/System.hpp>
#include <iostream>
#include <memory>
#include <sstream>

int main(int32_t p_argCount, const char** p_argVariables)
{
	// Initalize the system
	auto s_system = new dice::hfe::System();

	// Store the system in our global reference
	dice::hfe::g_system = s_system;

	// Create one string out of all passed arguments
	std::ostringstream s_stream;
	for (int32_t i = 1; i != p_argCount; i++)
	{
		s_stream << p_argVariables[i];
		if (i != p_argCount - 1)
		{
			s_stream << " ";
		}
	}
	std::string launchArgs = s_stream.str();

	// Initialize the engine
	auto s_BF2 = new dice::hfe::BF2();

	if (!s_BF2->init(launchArgs))
	{
		std::cerr << "fatal error: argument parsing failed" << std::endl;
		return 0x2A;
	}

	// Run the main loop
	while (s_BF2->run()) { }

	return 0;
}
