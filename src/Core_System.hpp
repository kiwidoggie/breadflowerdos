#pragma once
#include <ctime>

#if defined(WIN32)
struct timeval
{
    long int tv_sec;
    long int tv_usec;
};
#endif

extern struct timeval g_tv;
extern struct timeval g_old;
extern struct timeval g_startTime;

extern double g_frequency;

std::time_t getCurrentTime();