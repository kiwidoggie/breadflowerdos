#include "Profiler.hpp"

using namespace dice::hfe;

Profiler* dice::hfe::g_profiler = nullptr;
Profiler* dice::hfe::g_profilerClient = nullptr;

Profiler::Profiler(bool enabled) : m_enabled(enabled), m_refCount(1)
{
    // TODO: Implement
}

/**
 * @brief Adds a reference to this class
 */
void Profiler::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t Profiler::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t Profiler::release()
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
 * @param p_param
 * @return Profiler*
 */
IBase* Profiler::queryInterface(uint32_t p_param)
{
    if (p_param == IID_IBase)
        return this;

    if (p_param == IID_IProfilerClient)
        return this;

    return nullptr;
}

void Profiler::startGlobalTimer()
{
}

void Profiler::stopGlobalTimer()
{
}

void Profiler::startTimer(unsigned int&, char const*, float)
{
}

void Profiler::stopTimer(unsigned int)
{
}

void Profiler::getTimerIdByName(char const*, unsigned int&)
{
}

void Profiler::setEnable(bool enable)
{
    //m_enabled = enable;
}

bool Profiler::getEnable()
{
    return m_enabled;
}

void Profiler::pauseVTune()
{
}

bool Profiler::getEnablePageFaults() const
{
    return false;
}

void Profiler::setEnablePageFaults(bool)
{
}

void Profiler::reportToFile(std::string const&)
{
}

Profiler::~Profiler()
{
    // TODO: Implement
}

IBase* Profiler::create(uint32_t id, IBase* profiler)
{
    profiler = new Profiler(false);
    if (profiler->queryInterface(id) == nullptr)
    {
        profiler->release();
    }

    return profiler;
}
