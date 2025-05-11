#include "System.hpp"

#include "Core_System.hpp"

#include <thread>
#include <chrono>

using namespace dice::hfe;

System* dice::hfe::g_system = nullptr;

/**
 * @brief Construct a new System:: System object
 * 
 * bf2: 0074a3d0
 */
System::System() :
    m_refCount(1),
    m_simulationRate(100),
    m_exactTime(0),
    m_unknown18(0),
    m_unknown20(0),
    m_unknown24(0),
    m_unknown28(0)
{
}

System::~System()
{
    // TODO: Implement
}

/**
 * @brief Adds a reference to this class
 * 
 * bf2: 0074a890
 */
void System::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * 
 * bf2: 0074a8f0
 * 
 * @return uint32_t Current reference count
 */
uint32_t System::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * 
 * bf2: 0074a8a0
 * 
 * @return uint32_t 
 */
uint32_t System::release()
{
    m_refCount--;
    if (m_refCount != 0)
    {
        return m_refCount;
    }

    delete this;
    return 0;
}

/**
 * @brief TODO: Documentation
 * 
 * bf2: 0074a8c0
 * 
 * @param p_param 
 * @return System* 
 */
System* System::queryInterface(uint32_t p_param)
{
    if (p_param == IID_IBase)
        return this;
    
    return nullptr;
}

void System::dtor0()
{
    // TODO: Implement
}

void System::dtor1()
{
    // TODO: Implement
}

/**
 * @brief Gets the exact time
 * 
 * bf2: 0074a530
 * 
 * @return uint64_t 
 */
uint64_t System::getExactTime()
{
    return m_exactTime;
}

/**
 * @brief 
 * 
 * bf2: 0074a640
 * 
 * @return time_t 
 */
time_t System::getWallClockTime()
{
    auto s_currentTime = getCurrentTime();
    auto s_differenceTime = s_currentTime - g_startTime.tv_sec;
    time_t s_unknownTime;
    time_t s_unknownTime2;

    if (s_differenceTime < 0)
    {
        s_unknownTime = (s_differenceTime >> 1 | (s_differenceTime & 1));
        s_unknownTime = s_unknownTime + s_unknownTime;
    }
    else
        s_unknownTime = s_differenceTime;
    
    if (-1 < g_frequency)
        return s_unknownTime / g_frequency;
    
    s_unknownTime2 = (((uint64_t)g_frequency >> 1) | ((uint64_t)g_frequency & 1));

    return s_unknownTime / (s_unknownTime2 + s_unknownTime2);
}

/**
 * @brief Sleeps for specified duration
 * 
 * bf2: 0074a540
 * @param p_duration 
 */
void System::sleep(uint32_t p_duration)
{
#if 0 /* This is Linux only, use STL instead */
    struct timespec s_sleepTime;

    s_sleepTime.tv_sec = (p_duration / 1000);
    s_sleepTime.tv_nsec = (p_duration % 1000) * 1000000;

    nanosleep(&s_sleepTime, nullptr);
#else
    // TODO: Determine if this code is equivalent of the code above
    std::this_thread::sleep_for(std::chrono::milliseconds(p_duration));
#endif
}

/**
 * @brief 
 * 
 * bf2: 0074a5a0
 * @return uint32_t 
 */
uint32_t System::getSimulationRate()
{
    return m_simulationRate;
}

/**
 * @brief 
 * 
 * bf2: 0074a8d0
 * @return float 
 */
float System::getSimulationRatio()
{
    float s_simulationRate = getSimulationRate();

    return s_simulationRate / 100.f;
}

/**
 * @brief Unimplemented
 * 
 * bf2: 0074a5e0
 */
void System::storeAndTurnOffFPUExceptions()
{
    // Not implemented
}

/**
 * @brief Unimplemented
 * 
 * bf2: 0074a5f0
 */
void System::restoreFPUExceptions()
{
    // Not implemented
}