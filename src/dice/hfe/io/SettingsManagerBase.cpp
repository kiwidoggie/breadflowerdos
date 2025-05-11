#include "SettingsManagerBase.hpp"
#include <dice/hfe/SettingsRepostitory.hpp>

using namespace dice::hfe::io;

SettingsManagerBase* dice::hfe::io::g_SettingsManager = new SettingsManagerBase();

// bf2: 007a4db0
bool SettingsManagerBase::registerUserVar(std::string const& key, bool setVar, VariableSet var)
{
    {
        auto it = m_Keys.find(key);

        if (it != m_Keys.end())
        {
            // TODO: Debug() "var already registered."
            return false;
        }

        m_Keys.insert(key);
    }

    if (!setVar)
    {
        return true;
    }

    auto it = m_Storage.find(key);

    if (it == m_Storage.end())
    {
        // TODO: recheck bf2: 007a4f3e
        m_Storage.insert({ key, var });
    }

    return true;
}

bool SettingsManagerBase::floatRegisterUserVar(std::string const& key, float const& value, bool setVar, VariableSet var)
{
    if (!registerUserVar(key, setVar, var))
    {
        return false;
    }

    if (!g_Settings->floatExists(key))
    {
        g_Settings->floatSet(key, value);
    }

    g_SettingsManager->m_FloatStorage.insert({ key, value });
    g_SettingsManager->m_FloatKeys.insert(key);
    return true;
}

bool SettingsManagerBase::U32RegisterUserVar(std::string const& key, uint32_t const& value, bool setVar, VariableSet var)
{
    if (!registerUserVar(key, setVar, var))
    {
        return false;
    }

    if (!g_Settings->U32Exists(key))
    {
        g_Settings->U32Set(key, value);
    }

    g_SettingsManager->m_UIntStorage.insert({ key, value });
    g_SettingsManager->m_UIntKeys.insert(key);
    return true;
}

// bf2: 004de7a0
bool SettingsManagerBase::boolRegisterUserVar(std::string const& key, bool const& value, bool setVar, VariableSet var)
{
    if (!registerUserVar(key, setVar, var))
    {
        return false;
    }

    if (!g_Settings->boolExists(key))
    {
        g_Settings->boolSet(key, value);
    }

    g_SettingsManager->m_BoolStorage.insert({ key, value });
    g_SettingsManager->m_BoolKeys.insert(key);
    return true;
}

bool SettingsManagerBase::stringRegisterUserVar(std::string const& key, std::string const& value, bool setVar, VariableSet var)
{
    if (!registerUserVar(key, setVar, var))
    {
        return false;
    }

    if (!g_Settings->stringExists(key))
    {
        g_Settings->stringSet(key, value);
    }

    g_SettingsManager->m_StringStorage.insert({ key, value });
    g_SettingsManager->m_StringKeys.insert(key);
    return true;
}
