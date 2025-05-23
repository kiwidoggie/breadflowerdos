#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/io/FileAccess.hpp>
#include <dice/hfe/io/FileMode.hpp>
#include <string>
#include <list>

namespace dice
{
    namespace hfe
    {
        namespace io
        {
            class FileInfo;
            class IStream;

            const uint32_t IID_IFileSystem = 0x501611FE;

            class IFileSystem : public IBase
            {
            public:
                virtual void init() {}
                virtual bool isLastFileOpenedFromArchive() const { return false; }
                virtual IStream* open(std::string const&, FileMode, FileAccess, uint32_t) = 0;
                virtual bool fileExists(std::string const&) = 0;
                virtual bool deleteFile(std::string const&) = 0;
                virtual bool moveFile(std::string const&, std::string const&) = 0;
                virtual bool copyFile(std::string const&, std::string const&, bool) = 0;
                virtual bool readFile(std::string const&, void*, uint32_t, uint32_t&) = 0;
                virtual bool writeFile(std::string const&, void const*, uint32_t, bool) = 0;
                virtual uint32_t findFiles(std::string const&, bool, std::list<FileInfo>&) = 0;
                virtual bool getFileInfo(std::string const&, FileInfo&) = 0;
                virtual bool compareFileTime(std::string const&, std::string const&) = 0;
                virtual bool getFullFileName(std::string&) = 0;
                virtual void update() = 0;
                virtual void getHomeSubstitution() const = 0;
                virtual void getRootSubstitution() const = 0;
            };
        }
    }
}
