#include "SettingsManagerBase.hpp"
#include <dice/hfe/Debug.hpp>
#include <dice/hfe/SettingsRepostitory.hpp>

using namespace dice::hfe::io;

SettingsManagerBase* dice::hfe::io::g_settingsManager =
	new SettingsManagerBase();

// bf2: 007a4db0
bool SettingsManagerBase::registerUserVar(
	const std::string& key, bool setVar, VariableSet var)
{
	{
		auto it = m_keys.find(key);

		if (it != m_keys.end())
		{
			BF2_ERROR("Var " << key << " is already registered.");
			return false;
		}

		m_keys.insert(key);
	}

	if (!setVar)
	{
		return true;
	}

	auto it = m_storage.find(key);

	if (it == m_storage.end())
	{
		// TODO: recheck bf2: 007a4f3e
		m_storage.insert({key, var});
	}

	return true;
}

bool SettingsManagerBase::floatRegisterUserVar(
	const std::string& key, const float& value, bool setVar, VariableSet var)
{
	if (!registerUserVar(key, setVar, var))
	{
		return false;
	}

	if (!g_settings->floatExists(key))
	{
		g_settings->floatSet(key, value);
	}

	g_settingsManager->m_floatStorage.insert({key, value});
	g_settingsManager->m_floatKeys.insert(key);
	return true;
}

bool SettingsManagerBase::U32RegisterUserVar(
	const std::string& key, const uint32_t& value, bool setVar, VariableSet var)
{
	if (!registerUserVar(key, setVar, var))
	{
		return false;
	}

	if (!g_settings->U32Exists(key))
	{
		g_settings->U32Set(key, value);
	}

	g_settingsManager->m_U32Storage.insert({key, value});
	g_settingsManager->m_U32Keys.insert(key);
	return true;
}

// bf2: 004de7a0
bool SettingsManagerBase::boolRegisterUserVar(
	const std::string& key, const bool& value, bool setVar, VariableSet var)
{
	if (!registerUserVar(key, setVar, var))
	{
		return false;
	}

	if (!g_settings->boolExists(key))
	{
		g_settings->boolSet(key, value);
	}

	g_settingsManager->m_boolStorage.insert({key, value});
	g_settingsManager->m_boolKeys.insert(key);
	return true;
}

bool SettingsManagerBase::stringRegisterUserVar(
	const std::string& key, const std::string& value, bool setVar,
	VariableSet var)
{
	if (!registerUserVar(key, setVar, var))
	{
		return false;
	}

	if (!g_settings->stringExists(key))
	{
		g_settings->stringSet(key, value);
	}

	g_settingsManager->m_stringStorage.insert({key, value});
	g_settingsManager->m_stringKeys.insert(key);
	return true;
}
