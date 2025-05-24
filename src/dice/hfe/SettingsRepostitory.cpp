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
 * @return uint32_t Current
 * reference count
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

void SettingsRepostitory::intGet(const std::string& key, int32_t& value)
{
	m_intStorage.get(key, value);
}

void SettingsRepostitory::intSet(const std::string& key, const int32_t& value)
{
	m_intStorage.set(key, value);
}

bool SettingsRepostitory::intExists(const std::string& key)
{
	return m_intStorage.exists(key);
}

void SettingsRepostitory::intErase(const std::string& key)
{
	m_intStorage.erase(key);
}

void SettingsRepostitory::floatGet(const std::string& key, float& value)
{
	m_floatStorage.get(key, value);
}

void SettingsRepostitory::floatSet(const std::string& key, const float& value)
{
	m_floatStorage.set(key, value);
}

bool SettingsRepostitory::floatExists(const std::string& key)
{
	return m_floatStorage.exists(key);
}

void SettingsRepostitory::floatErase(const std::string& key)
{
	m_floatStorage.erase(key);
}

void SettingsRepostitory::U32Get(const std::string& key, uint32_t& value)
{
	m_U32Storage.get(key, value);
}

void SettingsRepostitory::U32Set(const std::string& key, const uint32_t& value)
{
	m_U32Storage.set(key, value);
}

bool SettingsRepostitory::U32Exists(const std::string& key)
{
	return m_U32Storage.exists(key);
}

void SettingsRepostitory::U32Erase(const std::string& key)
{
	m_U32Storage.erase(key);
}

void SettingsRepostitory::stringGet(const std::string& key, std::string& value)
{
	m_stringStorage.get(key, value);
}

void SettingsRepostitory::stringSet(
	const std::string& key, const std::string& value)
{
	m_stringStorage.set(key, value);
}

bool SettingsRepostitory::stringExists(const std::string& key)
{
	return m_stringStorage.exists(key);
}

void SettingsRepostitory::stringErase(const std::string& key)
{
	m_stringStorage.erase(key);
}

void SettingsRepostitory::boolGet(const std::string& key, bool& value)
{
	m_boolStorage.get(key, value);
}

void SettingsRepostitory::boolSet(const std::string& key, const bool& value)
{
	m_boolStorage.set(key, value);
}

bool SettingsRepostitory::boolExists(const std::string& key)
{
	return m_boolStorage.exists(key);
}

void SettingsRepostitory::boolErase(const std::string& key)
{
	m_boolStorage.erase(key);
}

void SettingsRepostitory::Vec3Get(const std::string& key, Vec3& value)
{
	m_Vec3Storage.get(key, value);
}

void SettingsRepostitory::Vec3Set(const std::string& key, const Vec3& value)
{
	m_Vec3Storage.set(key, value);
}

bool SettingsRepostitory::Vec3Exists(const std::string& key)
{
	return m_Vec3Storage.exists(key);
}

void SettingsRepostitory::Vec3Erase(const std::string& key)
{
	m_Vec3Storage.erase(key);
}

void SettingsRepostitory::Vec4Get(const std::string& key, Vec4& value)
{
	m_Vec4Storage.get(key, value);
}

void SettingsRepostitory::Vec4Set(const std::string& key, const Vec4& value)
{
	m_Vec4Storage.set(key, value);
}

bool SettingsRepostitory::Vec4Exists(const std::string& key)
{
	return m_Vec4Storage.exists(key);
}

void SettingsRepostitory::Vec4Erase(const std::string& key)
{
	m_Vec4Storage.erase(key);
}
