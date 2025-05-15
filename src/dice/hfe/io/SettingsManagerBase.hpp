#pragma once
#include <set>
#include <map>
#include <string>
#include <cstdint>
#include <dice/hfe/Vec3.hpp>

namespace dice
{
	namespace hfe
	{
		namespace io
		{
			typedef uint32_t VariableSet;

			class SettingsManagerBase
			{
			public:
				std::set<std::string> m_intKeys;
				std::map<std::string, int32_t> m_intStorage;
				std::set<std::string> m_floatKeys;
				std::map<std::string, float> m_floatStorage;
				std::set<std::string> m_U32Keys;
				std::map<std::string, uint32_t> m_U32Storage;
				std::set<std::string> m_boolKeys;
				std::map<std::string, bool> m_boolStorage;
				std::set<std::string> m_stringKeys;
				std::map<std::string, std::string> m_stringStorage;
				std::set<std::string> m_Vec3Keys;
				std::map<std::string, Vec3> m_Vec3Storage;

				std::set<std::string> m_keys;
				std::map<std::string, VariableSet> m_storage;

			public:
				bool registerUserVar(std::string const&, bool, VariableSet);
				bool floatRegisterUserVar(std::string const&, float const&, bool, VariableSet);
				bool U32RegisterUserVar(std::string const&, uint32_t const&, bool, VariableSet);
				bool boolRegisterUserVar(std::string const&, bool const&, bool, VariableSet);
				bool stringRegisterUserVar(std::string const&, std::string const&, bool, VariableSet);
			};

			extern SettingsManagerBase* g_settingsManager;
#if defined(WIN32)
// TODO: Win32 static_assert
#else
			static_assert(sizeof(SettingsManagerBase) == 0x2a0); // bf2: 007a51ca
#endif
		}
	}
}
