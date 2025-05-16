#pragma once

#include "ClassRegInfo.hpp"
#include "SingletonRegInfo.hpp"
#include <dice/hfe/IClassManager.hpp>
#include <map>
#include <set>

namespace dice::hfe
{
	class ClassManager : public IClassManager
	{
	public:
		struct ClassInfo
		{
			using CreateFunc = IBase* (*)(uint32_t, IBase*);
			CreateFunc func;
			uint32_t id;
			std::string name;
			IClassServer* server;

			ClassInfo() { }

			ClassInfo(ClassRegInfo regInfo, IClassServer* classServer) :
				func(regInfo.func),
				id(regInfo.id),
				name(regInfo.name),
				server(classServer)
			{
			}
		};

		struct SingletonInfo
		{
			IBase** singleton;
			uint32_t iid;
			uint32_t cid;

			union
			{
				uint32_t unknown18;

				struct
				{
					bool createOnInit	  : 1;
					bool createOnRegister : 1;
					bool unknownFlag2	  : 1;
				};
			};

			SingletonInfo(SingletonRegInfo regInfo) :
				singleton(regInfo.singleton),
				iid(regInfo.iid),
				cid(regInfo.cid),
				unknown18(regInfo.unknown18)
			{
			}
		};

	public:
		uint32_t m_refCount;
		std::set<IClassServer*> m_servers;
		std::map<uint32_t, uint32_t> m_defaultClasses;
		std::vector<ClassInfo> m_classInfos;
		std::map<std::string, ClassManager::SingletonInfo> m_singletonInfos;
		bool m_singletonsInitialized;
		char m_unknownB9[0x37];

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
		virtual bool getClassID(const std::string&, unsigned int&) override;
		virtual bool createInstance(unsigned int, IBase*) override;
		virtual IBase*
		createInstance(unsigned int, unsigned int, IBase*) override;
		virtual bool
		createInstance(const std::string&, unsigned int, IBase*) override;
		virtual bool
		setSingletonClass(const std::string&, unsigned int) override;
		virtual bool
		getSingletonClass(const std::string&, unsigned int&) override;
		virtual void registerSingleton(const SingletonRegInfo&) override;
		virtual void unregisterSingleton(const std::string&) override;
		virtual void* getSingleton(const std::string&) override;
		virtual void* getSingletonAs(const std::string&, unsigned int) override;
		virtual void
		registerSimpleSingleton(const std::string&, void*) override;
		virtual void unregisterSimpleSingleton(const std::string&) override;
		virtual void* getSimpleSingleton(const std::string&) const override;
		virtual void getPrintableSingletonList() const override;
		virtual void getAllClassIncludingSubstring(
			const std::string&, std::vector<std::string>&) const override;
		virtual void initSingletons() override;

		bool findServer(IClassServer* server);
		void addServer(IClassServer* server);
		bool getClassInfo(uint32_t id, ClassInfo& info);
		bool getClassInfo(std::string name, ClassInfo& info);
		void createSingleton(const std::string& name, SingletonInfo& info);
	};
#if defined(WIN32)
	// TODO: Win32 static_assert
#else
	static_assert(sizeof(ClassManager) == 0xf0);	// bf2: 004d406c
	static_assert(offsetof(ClassManager, m_servers) == 0x10);
	static_assert(offsetof(ClassManager, m_classInfos) == 0x70);
	static_assert(offsetof(ClassManager, m_singletonInfos) == 0x88);
#endif

	extern ClassManager* g_classManager;
}	 // namespace dice::hfe
