#pragma once
#include <cstdint>
#include <dice/hfe/Vec3.hpp>
#include <map>
#include <set>
#include <string>

namespace dice::hfe::io
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
		bool registerUserVar(const std::string&, bool, VariableSet);
		bool floatRegisterUserVar(
			const std::string&, const float&, bool, VariableSet);
		bool U32RegisterUserVar(
			const std::string&, const uint32_t&, bool, VariableSet);
		bool
		boolRegisterUserVar(const std::string&, const bool&, bool, VariableSet);
		bool stringRegisterUserVar(
			const std::string&, const std::string&, bool, VariableSet);
	};

	extern SettingsManagerBase* g_settingsManager;
#if defined(WIN32)
// TODO: Win32 static_assert
#else
	static_assert(sizeof(SettingsManagerBase) == 0x2a0);	// bf2: 007a51ca
#endif
}	 // namespace dice::hfe::io
