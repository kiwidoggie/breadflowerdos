#include "Core_System.hpp"

#include <cerrno>
#include <chrono>
#include <cstdint>
#include <string>

struct timeval g_tv = {0, 0};
struct timeval g_old = {0, 0};
struct timeval g_startTime = {0, 0};

double g_frequency = 0;

/**
 * @brief Get the Current Time object
 *
 * bf2:0074a900
 */
time_t getCurrentTime()
{
	// Assert validating assumptions
	static_assert(sizeof(time_t) == 8, "time_t is incorrect size");

	const uint64_t c_timeConst = 1000000;

	// TODO: Determine if this is equiv of the previous implementation
	auto s_Now = std::chrono::system_clock::now();
	auto s_Usec = std::chrono::duration_cast<std::chrono::microseconds>(
					  s_Now.time_since_epoch())
					  .count();

	g_tv.tv_sec = static_cast<long>(s_Usec / c_timeConst);
	g_tv.tv_usec = s_Usec % c_timeConst;

	g_old.tv_sec = g_tv.tv_sec * c_timeConst + g_tv.tv_usec;
	return g_old.tv_sec;
}
