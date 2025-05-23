#pragma once

#include "IFileSystem.hpp"
#include <vector>

namespace dice::hfe::io
{
	class IArchiveHandler;
	class IArchive;
	enum class FileResolveMode;

	const uint32_t IID_IFileManager = 0xCC0146FB;

	class IFileManager : public IFileSystem
	{
	public:
		virtual void setBaseSystem(IFileSystem*) = 0;
		virtual IFileSystem* getBaseSystem() = 0;
		virtual IStream*
		openwin32(const std::string&, FileMode, FileAccess, uint32_t) = 0;
		virtual void addArchiveHandler(IArchiveHandler*) = 0;
		virtual void removeArchiveHandler(IArchiveHandler*) = 0;
		virtual bool
		addPathOverload(const std::string&, const std::string&) = 0;
		virtual bool
		removePathOverload(const std::string&, const std::string&) = 0;
		virtual bool
		addMergeDirectory(const std::string&, const std::string&) = 0;
		virtual bool removeMergeDirectory(const std::string&) = 0;
		virtual uint32_t openArchive(const std::string&, bool) = 0;
		virtual void permitMountArchives(bool) = 0;
		virtual IArchive*
		mountArchive(const std::string&, const std::string&, bool) = 0;
		virtual bool unmountArchive(const std::string&) = 0;
		virtual void unmountAllArchives() = 0;
		virtual void getAllArchives(std::vector<IArchive*>*) = 0;
		virtual bool hasMountedArchives() const = 0;
		virtual const std::string& stripModPath(const std::string&) = 0;
		virtual void* getPathList() const = 0;
		virtual void addPath(const std::string&) = 0;
		virtual void removePath(const std::string&) = 0;
		virtual void removeAllPaths() = 0;
		virtual void getWritePath(const std::string&, std::string&) = 0;
		virtual FileResolveMode getFileResolveMode() const = 0;
		virtual void setFileResolveMode(FileResolveMode) = 0;
		virtual const std::string& fileExistsEx(const std::string&, bool) = 0;
		virtual const std::string& fileExistsEx2(const std::string&) = 0;
	};
}	 // namespace dice::hfe::io
