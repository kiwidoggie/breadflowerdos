#pragma once

#include <string>
#include <cstdint>
#include <dice/hfe/ISettingsRepostitory.hpp>
#include <dice/hfe/VariableStorage.hpp>

namespace dice
{
    namespace hfe
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
            virtual void intGet(std::string const&, int32_t&) override;
            virtual void intSet(std::string const&, int32_t const&) override;
            virtual bool intExists(std::string const&) override;
            virtual void intErase(std::string const&) override;
            virtual void floatGet(std::string const&, float&) override;
            virtual void floatSet(std::string const&, float const&) override;
            virtual bool floatExists(std::string const&) override;
            virtual void floatErase(std::string const&) override;
            virtual void U32Get(std::string const&, uint32_t&) override;
            virtual void U32Set(std::string const&, uint32_t const&) override;
            virtual bool U32Exists(std::string const&) override;
            virtual void U32Erase(std::string const&) override;
            virtual void stringGet(std::string const&, std::string&) override;
            virtual void stringSet(std::string const&, std::string const&) override;
            virtual bool stringExists(std::string const&) override;
            virtual void stringErase(std::string const&) override;
            virtual void boolGet(std::string const&, bool&) override;
            virtual void boolSet(std::string const&, bool const&) override;
            virtual bool boolExists(std::string const&) override;
            virtual void boolErase(std::string const&) override;
            virtual void Vec3Get(std::string const&, Vec3&) override;
            virtual void Vec3Set(std::string const&, Vec3 const&) override;
            virtual bool Vec3Exists(std::string const&) override;
            virtual void Vec3Erase(std::string const&) override;
            virtual void Vec4Get(std::string const&, Vec4&) override;
            virtual void Vec4Set(std::string const&, Vec4 const&) override;
            virtual bool Vec4Exists(std::string const&) override;
            virtual void Vec4Erase(std::string const&) override;
        };
#if defined(WIN32)
        // TODO: Win32 static_assert
#else
        static_assert(sizeof(SettingsRepostitory) == 0x198); // bf2: 0074518a
        static_assert(sizeof(VariableStorage<std::string, int32_t>) == 0x38);
#endif
    }
}
