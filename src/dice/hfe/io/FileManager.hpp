#pragma once

#include <dice/hfe/io/IFileManager.hpp>
#include <dice/hfe/StringUtils.hpp>
#include <map>

namespace dice
{
	namespace hfe
	{
		namespace io
		{
			const uint32_t CID_FileManager = 0x9F94B3FC;

			class FileManager : public IFileManager {
			public:
				struct MergeDirectory {};

			public:
				uint32_t m_refCount;
				std::map<std::string, std::vector<IArchive*>, NoCaseStringCompare> m_archiveMap;
				IFileSystem* m_baseSystem;
				std::vector<IArchiveHandler*> m_archiveHandlers;
				std::list<MergeDirectory> m_mergeDirectories;
				std::map<std::string, std::string, NoCaseStringCompare> m_pathOverloads;
				std::string m_archiveExtensions;
				std::list<std::string> m_paths;
				FileResolveMode m_fileResolveMode;
				bool m_isLastFileOpenedFromArchive;
				bool m_permitMountArchives;

			public:
				static IBase* create(uint32_t, IBase*);
				FileManager();

				virtual void addRef() override;
				virtual uint32_t getRef() override;
				virtual uint32_t release() override;
				virtual IBase* queryInterface(uint32_t) override;
				virtual bool isLastFileOpenedFromArchive() const override;
				virtual IStream* open(std::string const&, FileMode, FileAccess, uint32_t) override;
				virtual bool fileExists(std::string const&) override;
				virtual bool deleteFile(std::string const&) override;
				virtual bool moveFile(std::string const&, std::string const&) override;
				virtual bool copyFile(std::string const&, std::string const&, bool) override;
				virtual bool readFile(std::string const&, void*, uint32_t, uint32_t&) override;
				virtual bool writeFile(std::string const&, void const*, uint32_t, bool) override;
				virtual uint32_t findFiles(std::string const&, bool, std::list<FileInfo>&) override;
				virtual bool getFileInfo(std::string const&, FileInfo&) override;
				virtual bool compareFileTime(std::string const&, std::string const&) override;
				virtual bool getFullFileName(std::string&) override;
				virtual void update() override;
				virtual void getHomeSubstitution() const override;
				virtual void getRootSubstitution() const override;
				virtual void setBaseSystem(IFileSystem*) override;
				virtual IFileSystem* getBaseSystem() override;
				virtual IStream* openwin32(std::string const&, FileMode, FileAccess, uint32_t) override;
				virtual void addArchiveHandler(IArchiveHandler*) override;
				virtual void removeArchiveHandler(IArchiveHandler*) override;
				virtual bool addPathOverload(std::string const&, std::string const&) override;
				virtual bool removePathOverload(std::string const&, std::string const&) override;
				virtual bool addMergeDirectory(std::string const&, std::string const&) override;
				virtual bool removeMergeDirectory(std::string const&) override;
				virtual uint32_t openArchive(std::string const&, bool) override;
				virtual void permitMountArchives(bool) override;
				virtual IArchive* mountArchive(std::string const&, std::string const&, bool) override;
				virtual bool unmountArchive(std::string const&) override;
				virtual void unmountAllArchives() override;
				virtual void getAllArchives(std::vector<IArchive*>*) override;
				virtual bool hasMountedArchives() const override;
				virtual std::string const& stripModPath(std::string const&) override;
				virtual void* getPathList() const override;
				virtual void addPath(std::string const&) override;
				virtual void removePath(std::string const&) override;
				virtual void removeAllPaths() override;
				virtual void getWritePath(std::string const&, std::string&) override;
				virtual FileResolveMode getFileResolveMode() const override;
				virtual void setFileResolveMode(FileResolveMode) override;
				virtual std::string const& fileExistsEx(std::string const&, bool) override;
				virtual std::string const& fileExistsEx2(std::string const&) override;
			};

			extern FileManager* g_fileManager;

#if defined(WIN32)
			// TODO: Win32 static_assert
#else
			static_assert(sizeof(FileManager) == 0xC0); // bf2: 00850493
			static_assert(offsetof(FileManager, m_archiveMap) == 0x10); // bf2: 007dfe06
			static_assert(offsetof(FileManager, m_baseSystem) == 0x40); // bf2: 007deeb0
			static_assert(offsetof(FileManager, m_archiveHandlers) == 0x48); // bf2: 007e45d4
			static_assert(offsetof(FileManager, m_mergeDirectories) == 0x60); // bf2: 007def90
			static_assert(offsetof(FileManager, m_pathOverloads) == 0x70); // bf2: 007df987
			static_assert(offsetof(FileManager, m_archiveExtensions) == 0xA0); // bf2: 007e44b0
			static_assert(offsetof(FileManager, m_paths) == 0xA8); // bf2: 007e1740
			static_assert(offsetof(FileManager, m_fileResolveMode) == 0xB8); // bf2: 007e4630
			static_assert(offsetof(FileManager, m_isLastFileOpenedFromArchive) == 0xBC); // bf2: 007e4770
			static_assert(offsetof(FileManager, m_permitMountArchives) == 0xBD); // bf2: 007dee10
#endif
		}
	}
}
