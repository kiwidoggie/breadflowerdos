#pragma once

#include <cstdint>
#include <dice/hfe/IBase.hpp>
#include <dice/hfe/Vec3.hpp>
#include <dice/hfe/Vec4.hpp>
#include <string>

namespace dice::hfe
{
	const uint32_t IID_ISettingsRepostitory = 0x9C4B;

	class ISettingsRepostitory : public IBase
	{
	public:
		virtual void intGet(const std::string&, int32_t&) = 0;
		virtual void intSet(const std::string&, const int32_t&) = 0;
		virtual bool intExists(const std::string&) = 0;
		virtual void intErase(const std::string&) = 0;
		virtual void floatGet(const std::string&, float&) = 0;
		virtual void floatSet(const std::string&, const float&) = 0;
		virtual bool floatExists(const std::string&) = 0;
		virtual void floatErase(const std::string&) = 0;
		virtual void U32Get(const std::string&, uint32_t&) = 0;
		virtual void U32Set(const std::string&, const uint32_t&) = 0;
		virtual bool U32Exists(const std::string&) = 0;
		virtual void U32Erase(const std::string&) = 0;
		virtual void stringGet(const std::string&, std::string&) = 0;
		virtual void stringSet(const std::string&, const std::string&) = 0;
		virtual bool stringExists(const std::string&) = 0;
		virtual void stringErase(const std::string&) = 0;
		virtual void boolGet(const std::string&, bool&) = 0;
		virtual void boolSet(const std::string&, const bool&) = 0;
		virtual bool boolExists(const std::string&) = 0;
		virtual void boolErase(const std::string&) = 0;
		virtual void Vec3Get(const std::string&, Vec3&) = 0;
		virtual void Vec3Set(const std::string&, const Vec3&) = 0;
		virtual bool Vec3Exists(const std::string&) = 0;
		virtual void Vec3Erase(const std::string&) = 0;
		virtual void Vec4Get(const std::string&, Vec4&) = 0;
		virtual void Vec4Set(const std::string&, const Vec4&) = 0;
		virtual bool Vec4Exists(const std::string&) = 0;
		virtual void Vec4Erase(const std::string&) = 0;

		static void createSingleton();
	};

	extern ISettingsRepostitory* g_settings;
}	 // namespace dice::hfe
