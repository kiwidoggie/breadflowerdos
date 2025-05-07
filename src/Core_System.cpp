#include "Core_System.hpp"

#include <cerrno>
#include <string>
#include <cstdint>
#include <string.h> // strerror_r

struct timeval g_tv = { 0, 0 };
struct timeval g_old = { 0, 0 };
struct timeval g_startTime = { 0, 0 };

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

    std::string s_errorBuffer;
    s_errorBuffer.reserve(0x100);

    auto s_ret = gettimeofday(&g_tv, nullptr);
    if (s_ret != -1)
    {
        g_old.tv_sec = g_tv.tv_sec * c_timeConst + g_tv.tv_usec;
        return g_old.tv_sec;
    }

    auto s_error = errno;
    strerror_r(s_error, s_errorBuffer.data(), s_errorBuffer.capacity());

    g_old.tv_sec = g_tv.tv_sec * c_timeConst + g_tv.tv_usec;

    return g_old.tv_sec;
}