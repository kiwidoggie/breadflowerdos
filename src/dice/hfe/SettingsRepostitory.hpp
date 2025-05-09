#pragma once

#include <string>
#include <cstdint>
#include <dice/hfe/ISettingsRepostitory.hpp>

namespace dice
{
    namespace hfe
    {
        class SettingsRepostitory : public ISettingsRepostitory
        {
        public:
            uint32_t m_refCount;
            char m_unknown0C[0x18C];

        public:
            virtual void addRef() override;
            virtual uint32_t getRef() override;
            virtual uint32_t release() override;
            virtual SettingsRepostitory* queryInterface(uint32_t p_param) override;
            virtual void intGet(std::string const&, int32_t const&) override;
            virtual void intSet(std::string const&, int32_t const&) override;
            virtual bool intExists(std::string const&) override;
            virtual void intErase(std::string const&) override;
            virtual void floatGet(std::string const&, float const&) override;
            virtual void floatSet(std::string const&, float const&) override;
            virtual bool floatExists(std::string const&) override;
            virtual void floatErase(std::string const&) override;
            virtual void U32Get(std::string const&, uint32_t const&) override;
            virtual void U32Set(std::string const&, uint32_t const&) override;
            virtual bool U32Exists(std::string const&) override;
            virtual void U32Erase(std::string const&) override;
            virtual void stringGet(std::string const&, std::string const&) override;
            virtual void stringSet(std::string const&, std::string const&) override;
            virtual bool stringExists(std::string const&) override;
            virtual void stringErase(std::string const&) override;
            virtual void boolGet(std::string const&, bool const&) override;
            virtual void boolSet(std::string const&, bool const&) override;
            virtual bool boolExists(std::string const&) override;
            virtual void boolErase(std::string const&) override;
            virtual void Vec3Get(std::string const&, Vec3 const&) override;
            virtual void Vec3Set(std::string const&, Vec3 const&) override;
            virtual bool Vec3Exists(std::string const&) override;
            virtual void Vec3Erase(std::string const&) override;
            virtual void Vec4Get(std::string const&, Vec4 const&) override;
            virtual void Vec4Set(std::string const&, Vec4 const&) override;
            virtual bool Vec4Exists(std::string const&) override;
            virtual void Vec4Erase(std::string const&) override;
        };
    }
}
