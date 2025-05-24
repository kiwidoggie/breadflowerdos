#pragma once

#include <cstdint>
#include <dice/hfe/ISettingsRepostitory.hpp>
#include <dice/hfe/VariableStorage.hpp>
#include <string>

namespace dice::hfe
{
	const uint32_t CID_SettingsRepostitory = 0x9C76;

	class SettingsRepostitory : public ISettingsRepostitory
	{
	public:
		uint32_t m_refCount;
		VariableStorage<std::string, int32_t> m_intStorage;
		VariableStorage<std::string, float> m_floatStorage;
		VariableStorage<std::string, uint32_t> m_U32Storage;
		VariableStorage<std::string, std::string> m_stringStorage;
		VariableStorage<std::string, bool> m_boolStorage;
		VariableStorage<std::string, Vec3> m_Vec3Storage;
		VariableStorage<std::string, Vec4> m_Vec4Storage;

	public:
		virtual void addRef() override;
		virtual uint32_t getRef() override;
		virtual uint32_t release() override;
		virtual SettingsRepostitory* queryInterface(uint32_t p_param) override;
		virtual void intGet(const std::string&, int32_t&) override;
		virtual void intSet(const std::string&, const int32_t&) override;
		virtual bool intExists(const std::string&) override;
		virtual void intErase(const std::string&) override;
		virtual void floatGet(const std::string&, float&) override;
		virtual void floatSet(const std::string&, const float&) override;
		virtual bool floatExists(const std::string&) override;
		virtual void floatErase(const std::string&) override;
		virtual void U32Get(const std::string&, uint32_t&) override;
		virtual void U32Set(const std::string&, const uint32_t&) override;
		virtual bool U32Exists(const std::string&) override;
		virtual void U32Erase(const std::string&) override;
		virtual void stringGet(const std::string&, std::string&) override;
		virtual void stringSet(const std::string&, const std::string&) override;
		virtual bool stringExists(const std::string&) override;
		virtual void stringErase(const std::string&) override;
		virtual void boolGet(const std::string&, bool&) override;
		virtual void boolSet(const std::string&, const bool&) override;
		virtual bool boolExists(const std::string&) override;
		virtual void boolErase(const std::string&) override;
		virtual void Vec3Get(const std::string&, Vec3&) override;
		virtual void Vec3Set(const std::string&, const Vec3&) override;
		virtual bool Vec3Exists(const std::string&) override;
		virtual void Vec3Erase(const std::string&) override;
		virtual void Vec4Get(const std::string&, Vec4&) override;
		virtual void Vec4Set(const std::string&, const Vec4&) override;
		virtual bool Vec4Exists(const std::string&) override;
		virtual void Vec4Erase(const std::string&) override;
	};
#if defined(WIN32)
	// TODO: Win32 static_assert
#else
	static_assert(sizeof(SettingsRepostitory) == 0x198);	// bf2: 0074518a
	static_assert(sizeof(VariableStorage<std::string, int32_t>) == 0x38);
#endif
}	 // namespace dice::hfe
