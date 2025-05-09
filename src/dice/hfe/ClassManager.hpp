#pragma once

#include <dice/hfe/IClassManager.hpp>

namespace dice
{
    namespace hfe
    {
        class ClassManager : public IClassManager {
        public:
            uint32_t m_refCount;
            char m_unknown0C[0xE4];

        public:
            virtual void addRef() override;
            virtual uint32_t getRef() override;
            virtual uint32_t release() override;
            virtual ClassManager* queryInterface(uint32_t p_param) override;
            virtual ~ClassManager() override;
            virtual void registerServer(IClassServer*) override;
            virtual void unregisterServer(IClassServer*) override;
            virtual void setDefaultClass(unsigned int, unsigned int) override;
            virtual bool getDefaultClass(unsigned int, unsigned int&) override;
            virtual bool getClassName(unsigned int, std::string&) override;
            virtual bool getClassID(std::string const&, unsigned int&) override;
            virtual bool createInstance(unsigned int, IBase*) override;
            virtual bool createInstance(unsigned int, unsigned int, IBase*) override;
            virtual bool createInstance(std::string const&, unsigned int, IBase*) override;
            virtual bool setSingletonClass(std::string const&, unsigned int) override;
            virtual bool getSingletonClass(std::string const&, unsigned int&) override;
            virtual void registerSingleton(SingletonRegInfo const&) override;
            virtual void unregisterSingleton(std::string const&) override;
            virtual void* getSingleton(std::string const&) override;
            virtual void* getSingletonAs(std::string const&, unsigned int) override;
            virtual void registerSimpleSingleton(std::string const&, void*) override;
            virtual void unregisterSimpleSingleton(std::string const&) override;
            virtual void* getSimpleSingleton(std::string const&) const override;
            virtual void getPrintableSingletonList() const override;
            virtual void getAllClassIncludingSubstring(std::string const&, std::vector<std::string>&) const override;
            virtual void initSingletons() override;
        };

        extern ClassManager* g_classManager;
    }
}
