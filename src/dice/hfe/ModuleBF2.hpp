#pragma once

#include <dice/hfe/IModule.hpp>

namespace dice
{
    namespace hfe
    {
        class ModuleBF2 : public IModule
        {
        public:
            uint32_t m_refCount;

            ModuleBF2() : m_refCount(1) {}
            virtual void addRef() override;
            virtual uint32_t getRef() override;
            virtual uint32_t release() override;
            virtual ModuleBF2* queryInterface(uint32_t) override;
            virtual void getClassList(std::vector<ClassRegInfo>&) override;
            virtual void getSingletonList(std::vector<SingletonRegInfo>&) override;
            virtual bool init() override;
            virtual bool close() override;
        };
    }
}
