#pragma once

#include <string>
#include <vector>
#include <dice/hfe/IBase.hpp>

namespace dice
{
    namespace hfe
    {
        class IClassServer;
        struct SingletonRegInfo;

        const uint32_t IID_IClassManager = 0x9C44;

        class IClassManager : public IBase
        {
        public:
            virtual ~IClassManager() {};
            virtual void registerServer(IClassServer*) = 0;
            virtual void unregisterServer(IClassServer*) = 0;
            virtual void setDefaultClass(unsigned int, unsigned int) = 0;
            virtual bool getDefaultClass(unsigned int, unsigned int&) = 0;
            virtual bool getClassName(unsigned int, std::string&) = 0;
            virtual bool getClassID(std::string const&, unsigned int&) = 0;
            virtual bool createInstance(unsigned int, IBase*) = 0;
            virtual bool createInstance(unsigned int, unsigned int, IBase*) = 0;
            virtual bool createInstance(std::string const&, unsigned int, IBase*) = 0;
            virtual bool setSingletonClass(std::string const&, unsigned int) = 0;
            virtual bool getSingletonClass(std::string const&, unsigned int&) = 0;
            virtual void registerSingleton(SingletonRegInfo const&) = 0;
            virtual void unregisterSingleton(std::string const&) = 0;
            virtual void* getSingleton(std::string const&) = 0;
            virtual void* getSingletonAs(std::string const&, unsigned int) = 0;
            virtual void registerSimpleSingleton(std::string const&, void*) = 0;
            virtual void unregisterSimpleSingleton(std::string const&) = 0;
            virtual void* getSimpleSingleton(std::string const&) const = 0;
            virtual void getPrintableSingletonList() const = 0;
            virtual void getAllClassIncludingSubstring(std::string const&, std::vector<std::string>&) const = 0;
            virtual void initSingletons() = 0;
        };
    }
}