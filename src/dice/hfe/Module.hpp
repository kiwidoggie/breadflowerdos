#pragma once

#include <dice/hfe/IModule.hpp>

namespace dice
{
    namespace hfe
    {
        class Module : public IModule
        {
        public:
            uint32_t m_refCount;

            Module() : m_refCount(1) {}
            virtual void addRef() override;
            virtual uint32_t getRef() override;
            virtual uint32_t release() override;
            virtual Module* queryInterface(uint32_t p_param) override;
            virtual void getClassList(std::vector<ClassRegInfo>&) override;
            virtual void getSingletonList(std::vector<SingletonRegInfo>&) override;
            virtual bool init() override;
            virtual bool close() override;
        };
    }
}
