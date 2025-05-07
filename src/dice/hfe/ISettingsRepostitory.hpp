#pragma once

#include <string>
#include <cstdint>
#include <dice/hfe/IBase.hpp>
#include <dice/hfe/Vec3.hpp>
#include <dice/hfe/Vec4.hpp>

namespace dice
{
    namespace hfe
    {
        class ISettingsRepostitory : private IBase
        {
        public:
            virtual void intGet(std::string const&, int32_t const&) = 0;
            virtual void intSet(std::string const&, int32_t const&) = 0;
            virtual bool intExists(std::string const&) = 0;
            virtual void intErase(std::string const&) = 0;
            virtual void floatGet(std::string const&, float const&) = 0;
            virtual void floatSet(std::string const&, float const&) = 0;
            virtual bool floatExists(std::string const&) = 0;
            virtual void floatErase(std::string const&) = 0;
            virtual void U32Get(std::string const&, uint32_t const&) = 0;
            virtual void U32Set(std::string const&, uint32_t const&) = 0;
            virtual bool U32Exists(std::string const&) = 0;
            virtual void U32Erase(std::string const&) = 0;
            virtual void stringGet(std::string const&, std::string const&) = 0;
            virtual void stringSet(std::string const&, std::string const&) = 0;
            virtual bool stringExists(std::string const&) = 0;
            virtual void stringErase(std::string const&) = 0;
            virtual void boolGet(std::string const&, bool const&) = 0;
            virtual void boolSet(std::string const&, bool const&) = 0;
            virtual bool boolExists(std::string const&) = 0;
            virtual void boolErase(std::string const&) = 0;
            virtual void Vec3Get(std::string const&, Vec3 const&) = 0;
            virtual void Vec3Set(std::string const&, Vec3 const&) = 0;
            virtual bool Vec3Exists(std::string const&) = 0;
            virtual void Vec3Erase(std::string const&) = 0;
            virtual void Vec4Get(std::string const&, Vec4 const&) = 0;
            virtual void Vec4Set(std::string const&, Vec4 const&) = 0;
            virtual bool Vec4Exists(std::string const&) = 0;
            virtual void Vec4Erase(std::string const&) = 0;
        };
    }
}
