#pragma once
#include <sys/time.h>

extern struct timeval g_tv;
extern struct timeval g_old;
extern struct timeval g_startTime;

extern double g_frequency;

time_t getCurrentTime();