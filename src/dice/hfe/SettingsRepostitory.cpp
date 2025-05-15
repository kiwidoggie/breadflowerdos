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

void SettingsRepostitory::intGet(std::string const& key, int32_t& value)
{
    m_intStorage.get(key, value);
}

void SettingsRepostitory::intSet(std::string const& key, int32_t const& value)
{
    m_intStorage.set(key, value);
}

bool SettingsRepostitory::intExists(std::string const& key)
{
    return m_intStorage.exists(key);
}

void SettingsRepostitory::intErase(std::string const& key)
{
    m_intStorage.erase(key);
}

void SettingsRepostitory::floatGet(std::string const& key, float& value)
{
    m_floatStorage.get(key, value);
}

void SettingsRepostitory::floatSet(std::string const& key, float const& value)
{
    m_floatStorage.set(key, value);
}

bool SettingsRepostitory::floatExists(std::string const& key)
{
    return m_floatStorage.exists(key);
}

void SettingsRepostitory::floatErase(std::string const& key)
{
    m_floatStorage.erase(key);
}

void SettingsRepostitory::U32Get(std::string const& key, uint32_t& value)
{
    m_U32Storage.get(key, value);
}

void SettingsRepostitory::U32Set(std::string const& key, uint32_t const& value)
{
    m_U32Storage.set(key, value);
}

bool SettingsRepostitory::U32Exists(std::string const& key)
{
    return m_U32Storage.exists(key);
}

void SettingsRepostitory::U32Erase(std::string const& key)
{
    m_U32Storage.erase(key);
}

void SettingsRepostitory::stringGet(std::string const& key, std::string& value)
{
    m_stringStorage.get(key, value);
}

void SettingsRepostitory::stringSet(std::string const& key, std::string const& value)
{
    m_stringStorage.set(key, value);
}

bool SettingsRepostitory::stringExists(std::string const& key)
{
    return m_stringStorage.exists(key);
}

void SettingsRepostitory::stringErase(std::string const& key)
{
    m_stringStorage.erase(key);
}

void SettingsRepostitory::boolGet(std::string const& key, bool& value)
{
    m_boolStorage.get(key, value);
}

void SettingsRepostitory::boolSet(std::string const& key, bool const& value)
{
    m_boolStorage.set(key, value);
}

bool SettingsRepostitory::boolExists(std::string const& key)
{
    return m_boolStorage.exists(key);
}

void SettingsRepostitory::boolErase(std::string const& key)
{
    m_boolStorage.erase(key);
}

void SettingsRepostitory::Vec3Get(std::string const& key, Vec3& value)
{
    m_Vec3Storage.get(key, value);
}

void SettingsRepostitory::Vec3Set(std::string const& key, Vec3 const& value)
{
    m_Vec3Storage.set(key, value);
}

bool SettingsRepostitory::Vec3Exists(std::string const& key)
{
    return m_Vec3Storage.exists(key);
}

void SettingsRepostitory::Vec3Erase(std::string const& key)
{
    m_Vec3Storage.erase(key);
}

void SettingsRepostitory::Vec4Get(std::string const& key, Vec4& value)
{
    m_Vec4Storage.get(key, value);
}

void SettingsRepostitory::Vec4Set(std::string const& key, Vec4 const& value)
{
    m_Vec4Storage.set(key, value);
}

bool SettingsRepostitory::Vec4Exists(std::string const& key)
{
    return m_Vec4Storage.exists(key);
}

void SettingsRepostitory::Vec4Erase(std::string const& key)
{
    m_Vec4Storage.erase(key);
}
