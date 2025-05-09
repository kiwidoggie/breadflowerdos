#include "SettingsRepostitory.hpp"

using namespace dice::hfe;

/**
 * @brief Adds a reference to this class
 */
void SettingsRepostitory::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t SettingsRepostitory::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t SettingsRepostitory::release()
{
    // This looks scuffed
    m_refCount--;
    if (m_refCount == 0)
        delete this;

    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @param p_param
 * @return System*
 */
SettingsRepostitory* SettingsRepostitory::queryInterface(uint32_t p_param)
{
    if (p_param == IID_IBase)
        return this;

    if (p_param == IID_ISettingsRepostitory)
        return this;

    return nullptr;
}

// TODO: Implement all vfunctions below.

void SettingsRepostitory::intGet(std::string const&, int32_t const&)
{
}

void SettingsRepostitory::intSet(std::string const&, int32_t const&)
{
}

bool SettingsRepostitory::intExists(std::string const&)
{
	return false;
}

void SettingsRepostitory::intErase(std::string const&)
{
}

void SettingsRepostitory::floatGet(std::string const&, float const&)
{
}

void SettingsRepostitory::floatSet(std::string const&, float const&)
{
}

bool SettingsRepostitory::floatExists(std::string const&)
{
	return false;
}

void SettingsRepostitory::floatErase(std::string const&)
{
}

void SettingsRepostitory::U32Get(std::string const&, uint32_t const&)
{
}

void SettingsRepostitory::U32Set(std::string const&, uint32_t const&)
{
}

bool SettingsRepostitory::U32Exists(std::string const&)
{
	return false;
}

void SettingsRepostitory::U32Erase(std::string const&)
{
}

void SettingsRepostitory::stringGet(std::string const&, std::string const&)
{
}

void SettingsRepostitory::stringSet(std::string const&, std::string const&)
{
}

bool SettingsRepostitory::stringExists(std::string const&)
{
	return false;
}

void SettingsRepostitory::stringErase(std::string const&)
{
}

void SettingsRepostitory::boolGet(std::string const&, bool const&)
{
}

void SettingsRepostitory::boolSet(std::string const&, bool const&)
{
}

bool SettingsRepostitory::boolExists(std::string const&)
{
	return false;
}

void SettingsRepostitory::boolErase(std::string const&)
{
}

void SettingsRepostitory::Vec3Get(std::string const&, Vec3 const&)
{
}

void SettingsRepostitory::Vec3Set(std::string const&, Vec3 const&)
{
}

bool SettingsRepostitory::Vec3Exists(std::string const&)
{
	return false;
}

void SettingsRepostitory::Vec3Erase(std::string const&)
{
}

void SettingsRepostitory::Vec4Get(std::string const&, Vec4 const&)
{
}

void SettingsRepostitory::Vec4Set(std::string const&, Vec4 const&)
{
}

bool SettingsRepostitory::Vec4Exists(std::string const&)
{
	return false;
}

void SettingsRepostitory::Vec4Erase(std::string const&)
{
}
