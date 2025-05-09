#pragma once
#include <ctime>

struct timeval
{
    long int tv_sec;
    long int tv_nsec;
};

extern struct timeval g_tv;
extern struct timeval g_old;
extern struct timeval g_startTime;

extern double g_frequency;

std::time_t getCurrentTime();