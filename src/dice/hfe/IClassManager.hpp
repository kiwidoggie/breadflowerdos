#pragma once

#include <dice/hfe/IBase.hpp>
#include <string>
#include <vector>

namespace dice::hfe
{
	class IClassServer;
	class SingletonRegInfo;

	const uint32_t IID_IClassManager = 0x9C44;

	class IClassManager : public IBase
	{
	public:
		virtual ~IClassManager() { };
		virtual void registerServer(IClassServer*) = 0;
		virtual void unregisterServer(IClassServer*) = 0;
		virtual void setDefaultClass(unsigned int, unsigned int) = 0;
		virtual bool getDefaultClass(unsigned int, unsigned int&) = 0;
		virtual bool getClassName(unsigned int, std::string&) = 0;
		virtual bool getClassID(const std::string&, unsigned int&) = 0;
		virtual bool createInstance(unsigned int, IBase*) = 0;
		virtual IBase* createInstance(unsigned int, unsigned int, IBase*) = 0;
		virtual bool
		createInstance(const std::string&, unsigned int, IBase*) = 0;
		virtual bool setSingletonClass(const std::string&, unsigned int) = 0;
		virtual bool getSingletonClass(const std::string&, unsigned int&) = 0;
		virtual void registerSingleton(const SingletonRegInfo&) = 0;
		virtual void unregisterSingleton(const std::string&) = 0;
		virtual void* getSingleton(const std::string&) = 0;
		virtual void* getSingletonAs(const std::string&, unsigned int) = 0;
		virtual void registerSimpleSingleton(const std::string&, void*) = 0;
		virtual void unregisterSimpleSingleton(const std::string&) = 0;
		virtual void* getSimpleSingleton(const std::string&) const = 0;
		virtual void getPrintableSingletonList() const = 0;
		virtual void getAllClassIncludingSubstring(
			const std::string&, std::vector<std::string>&) const = 0;
		virtual void initSingletons() = 0;
	};
}	 // namespace dice::hfe
