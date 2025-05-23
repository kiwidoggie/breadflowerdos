#pragma once

#include "IFileSystem.hpp"
#include "FileResolveMode.hpp"
#include <vector>

namespace dice
{
    namespace hfe
    {
        namespace io
        {
            class IArchiveHandler;
            class IArchive;

            const uint32_t IID_IFileManager = 0xCC0146FB;

            class IFileManager : public IFileSystem
            {
            public:
                virtual void setBaseSystem(IFileSystem*) = 0;
                virtual IFileSystem* getBaseSystem() = 0;
                virtual IStream* openwin32(std::string const&, FileMode, FileAccess, uint32_t) = 0;
                virtual void addArchiveHandler(IArchiveHandler*) = 0;
                virtual void removeArchiveHandler(IArchiveHandler*) = 0;
                virtual bool addPathOverload(std::string const&, std::string const&) = 0;
                virtual bool removePathOverload(std::string const&, std::string const&) = 0;
                virtual bool addMergeDirectory(std::string const&, std::string const&) = 0;
                virtual bool removeMergeDirectory(std::string const&) = 0;
                virtual uint32_t openArchive(std::string const&, bool) = 0;
                virtual void permitMountArchives(bool) = 0;
                virtual IArchive* mountArchive(std::string const&, std::string const&, bool) = 0;
                virtual bool unmountArchive(std::string const&) = 0;
                virtual void unmountAllArchives() = 0;
                virtual void getAllArchives(std::vector<IArchive*>*) = 0;
                virtual bool hasMountedArchives() const = 0;
                virtual std::string const& stripModPath(std::string const&) = 0;
                virtual void* getPathList() const = 0;
                virtual void addPath(std::string const&) = 0;
                virtual void removePath(std::string const&) = 0;
                virtual void removeAllPaths() = 0;
                virtual void getWritePath(std::string const&, std::string&) = 0;
                virtual FileResolveMode getFileResolveMode() const = 0;
                virtual void setFileResolveMode(FileResolveMode) = 0;
                virtual std::string const& fileExistsEx(std::string const&, bool) = 0;
                virtual std::string const& fileExistsEx2(std::string const&) = 0;
            };
        }
    }
}
