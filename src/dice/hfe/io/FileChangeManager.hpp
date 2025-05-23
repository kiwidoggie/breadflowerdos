#pragma once

#include <dice/hfe/io/IDirectoryChangeListener.hpp>
#include <dice/hfe/io/IFileChangeManager.hpp>
#include <map>
#include <vector>

namespace dice::hfe::io
{
	const uint32_t CID_FileChangeManager = 0x336976FF;

	class FileChangeManager :
		public IFileChangeManager,
		IDirectoryChangeListener
	{
	public:
		struct File
		{
		};

		struct DirChange
		{
		};

	public:
		uint32_t m_refCount;
		bool m_initialized;
		std::map<std::string, std::vector<File>> m_unknown18;
		std::vector<std::string> m_unknown48;
		bool m_unknown60;
		std::vector<DirChange> m_unknown68;
		float m_delayTime;
		bool m_enabled;

	public:
		static IBase* create(uint32_t, IBase*);
		FileChangeManager();
		void init();

		virtual void addRef() override;
		virtual uint32_t getRef() override;
		virtual uint32_t release() override;
		virtual IBase* queryInterface(uint32_t) override;
		virtual const std::string& addListener(
			IFileChangeListener*, const std::string&, uint32_t) override;
		virtual bool
		removeListener(IFileChangeListener*, const std::string&) override;
		virtual bool
		removeListener(dice::hfe::io::IFileChangeListener*) override;
		virtual void setEnable(bool) override;
		virtual bool getEnable() override;
		virtual void setDelayTime(float) override;
		virtual float getDelayTime() override;
		virtual void update() override;
		virtual ~FileChangeManager() override = default;
		virtual void
		onDirectoryChange(const std::string&, bool, uint32_t) override;
		virtual bool allowFileChange(const std::string&) override;
	};

	extern FileChangeManager* g_fileChangeManager;

#if defined(WIN32)
// TODO: Win32 static_assert
#else
	static_assert(sizeof(FileChangeManager) == 0x88);	 // bf2: 00850503
	static_assert(offsetof(FileChangeManager, m_delayTime) == 0x80);
#endif
}	 // namespace dice::hfe::io
