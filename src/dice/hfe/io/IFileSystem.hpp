#pragma once

#include <dice/hfe/IBase.hpp>
#include <list>
#include <string>

namespace dice::hfe::io
{
	class FileAccess;
	class FileMode;
	class FileInfo;
	class IStream;

	const uint32_t IID_IFileSystem = 0x501611FE;

	class IFileSystem : public IBase
	{
	public:
		virtual void init() { }

		virtual bool isLastFileOpenedFromArchive() const
		{
			return false;
		}

		virtual IStream*
		open(const std::string&, FileMode, FileAccess, uint32_t) = 0;
		virtual bool fileExists(const std::string&) = 0;
		virtual bool deleteFile(const std::string&) = 0;
		virtual bool moveFile(const std::string&, const std::string&) = 0;
		virtual bool copyFile(const std::string&, const std::string&, bool) = 0;
		virtual bool
		readFile(const std::string&, void*, uint32_t, uint32_t&) = 0;
		virtual bool
		writeFile(const std::string&, const void*, uint32_t, bool) = 0;
		virtual uint32_t
		findFiles(const std::string&, bool, std::list<FileInfo>&) = 0;
		virtual bool getFileInfo(const std::string&, FileInfo&) = 0;
		virtual bool
		compareFileTime(const std::string&, const std::string&) = 0;
		virtual bool getFullFileName(std::string&) = 0;
		virtual void update() = 0;
		virtual void getHomeSubstitution() const = 0;
		virtual void getRootSubstitution() const = 0;
	};
}	 // namespace dice::hfe::io
