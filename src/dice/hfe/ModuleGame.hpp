#pragma once

#include <dice/hfe/IModule.hpp>
#include <dice/hfe/IEventListener.hpp>

namespace dice
{
    namespace hfe
    {
        class ModuleGame : public IModule, public IEventListener
        {
        public:
            uint32_t m_refCount;
            bool m_initialized;

            ModuleGame() : m_refCount(1), m_initialized(false) {}
            virtual void addRef() override;
            virtual uint32_t getRef() override;
            virtual uint32_t release() override;
            virtual ModuleGame* queryInterface(uint32_t) override;
            virtual void getClassList(std::vector<ClassRegInfo>&) override;
            virtual void getSingletonList(std::vector<SingletonRegInfo>&) override;
            virtual bool init() override;
            virtual bool close() override;
            virtual void handleEvent(EventCategory, uint32_t, EventNode*, void*) override;
        };
    }
}
