#pragma once
#include <cstdint>
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
				std::set<std::string> m_IntKeys;
				std::map<std::string, int32_t> m_IntStorage;
				std::set<std::string> m_FloatKeys;
				std::map<std::string, float> m_FloatStorage;
				std::set<std::string> m_UIntKeys;
				std::map<std::string, uint32_t> m_UIntStorage;
				std::set<std::string> m_BoolKeys;
				std::map<std::string, bool> m_BoolStorage;
				std::set<std::string> m_StringKeys;
				std::map<std::string, std::string> m_StringStorage;
				std::set<std::string> m_Vec3Keys;
				std::map<std::string, Vec3> m_Vec3Storage;

				std::set<std::string> m_Keys;
				std::map<std::string, VariableSet> m_Storage;

			public:
				bool registerUserVar(std::string const&, bool, VariableSet);
				bool floatRegisterUserVar(std::string const&, float const&, bool, VariableSet);
				bool U32RegisterUserVar(std::string const&, uint32_t const&, bool, VariableSet);
				bool boolRegisterUserVar(std::string const&, bool const&, bool, VariableSet);
				bool stringRegisterUserVar(std::string const&, std::string const&, bool, VariableSet);
			};

			extern SettingsManagerBase* g_SettingsManager;
#if defined(WIN32)
// TODO: Win32 static_assert
#else
			static_assert(sizeof(SettingsManagerBase) == 0x2a0); // bf2: 007a51ca
#endif
		}
	}
}
