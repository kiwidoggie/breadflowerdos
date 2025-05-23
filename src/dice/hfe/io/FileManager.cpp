#include "FileManager.hpp"

using namespace dice::hfe::io;
using namespace dice::hfe;

FileManager* dice::hfe::io::g_fileManager = nullptr;

IBase* FileManager::create(uint32_t id, IBase* fileManager)
{
    if (fileManager == nullptr)
    {
        fileManager = new FileManager();
        if (fileManager->queryInterface(id) == nullptr)
        {
            fileManager->release();
        }
    }

    return fileManager;
}

FileManager::FileManager()
{
    // TODO: Implement
}

/**
 * @brief Adds a reference to this class
 */
void FileManager::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t FileManager::getRef()
{
    return m_refCount;
}

/**
 * @brief Removes a reference from this class. Calls the deconstructor if there are no more references.
 * @return uint32_t Current reference count
 */
uint32_t FileManager::release()
{
    m_refCount--;
    if (m_refCount != 0)
    {
        return m_refCount;
    }

    delete this;
    return 0;
}

/**
 * @brief TODO: Documentation
 * @param iid
 * @return FileManager*
 */
IBase* FileManager::queryInterface(uint32_t iid)
{
    if (iid == IID_IBase)
        return this;

    if (iid == IID_IFileSystem)
        return this;

    if (iid == IID_IFileManager)
        return this;

    return nullptr;
}

bool FileManager::isLastFileOpenedFromArchive() const
{
    return m_isLastFileOpenedFromArchive;
}

IStream* FileManager::open(std::string const& fileName, FileMode fileMode, FileAccess fileAccess, uint32_t unknown)
{
    if (fileMode == FileMode::OpenExisting && fileAccess != FileAccess::Write && fileAccess != FileAccess::ReadWrite)
    {
        // TODO: Implement
        return nullptr;
    }

    std::string outPath;
    getWritePath(fileName, outPath);
    //g_loadStat->incLoadCounter(1);
    return m_baseSystem->open(outPath, fileMode, fileAccess, unknown);
}

bool FileManager::fileExists(std::string const& fileName)
{
    auto& outFile = fileExistsEx(fileName, false);
    return !outFile.empty();
}

bool FileManager::deleteFile(std::string const& fileName)
{
    std::string outPath;
    getWritePath(fileName, outPath);
    return m_baseSystem->deleteFile(outPath);
}

bool FileManager::moveFile(std::string const& source, std::string const& destination)
{
    std::string outSourcePath;
    getWritePath(source, outSourcePath);
    std::string outDestinationPath;
    getWritePath(destination, outDestinationPath);

    return m_baseSystem->moveFile(outSourcePath, outDestinationPath);
}

bool FileManager::copyFile(std::string const& source, std::string const& destination, bool skipIfExists)
{
    std::string outSourcePath;
    getWritePath(source, outSourcePath);
    std::string outDestinationPath;
    getWritePath(destination, outDestinationPath);

    return m_baseSystem->copyFile(outSourcePath, outDestinationPath, skipIfExists);
}

bool FileManager::readFile(std::string const&, void*, uint32_t, uint32_t&)
{
    // TODO: Implement
    return false;
}

bool FileManager::writeFile(std::string const&, void const*, uint32_t, bool)
{
    // TODO: Implement
    return false;
}

uint32_t FileManager::findFiles(std::string const&, bool, std::list<FileInfo>&)
{
    // TODO: Implement
    return 0;
}

bool FileManager::getFileInfo(std::string const&, FileInfo&)
{
    // TODO: Implement
    return false;
}

bool FileManager::compareFileTime(std::string const&, std::string const&)
{
    // TODO: Implement
    return false;
}

bool FileManager::getFullFileName(std::string&)
{
    // TODO: Implement
    return false;
}


void FileManager::update()
{
    // TODO: Implement
}

void FileManager::getHomeSubstitution() const
{
    // TODO: Implement
}

void FileManager::getRootSubstitution() const
{
    // TODO: Implement
}

void FileManager::setBaseSystem(IFileSystem* baseSystem)
{
    if (m_baseSystem != nullptr)
    {
        m_baseSystem->release();
    }

    m_baseSystem = baseSystem;

    if (baseSystem != nullptr)
    {
        baseSystem->init();
        m_baseSystem->addRef();
    }
}

IFileSystem* FileManager::getBaseSystem()
{
    return m_baseSystem;
}

IStream* FileManager::openwin32(std::string const&, FileMode, FileAccess, uint32_t)
{
    // TODO: Implement
    return nullptr;
}

void FileManager::addArchiveHandler(IArchiveHandler*)
{
    // TODO: Implement
}

void FileManager::removeArchiveHandler(IArchiveHandler*)
{
    // TODO: Implement
}

bool FileManager::addPathOverload(std::string const&, std::string const&)
{
    // TODO: Implement
    return false;
}

bool FileManager::removePathOverload(std::string const&, std::string const&)
{
    // TODO: Implement
    return false;
}

bool FileManager::addMergeDirectory(std::string const&, std::string const&)
{
    // TODO: Implement
    return false;
}

bool FileManager::removeMergeDirectory(std::string const&)
{
    // TODO: Implement
    return false;
}

uint32_t FileManager::openArchive(std::string const&, bool)
{
    // TODO: Implement
    return 0;
}

void FileManager::permitMountArchives(bool permit)
{
    m_permitMountArchives = permit;
}

IArchive* FileManager::mountArchive(std::string const&, std::string const&, bool)
{
    // TODO: Implement
    return nullptr;
}

bool FileManager::unmountArchive(std::string const&)
{
    // TODO: Implement
    return false;
}

void FileManager::unmountAllArchives()
{
    // TODO: Implement
}

void FileManager::getAllArchives(std::vector<IArchive*>*)
{
    // TODO: Implement
}

bool FileManager::hasMountedArchives() const
{
    // TODO: Implement
    return false;
}

std::string const& FileManager::stripModPath(std::string const&)
{
    // TODO: Implement
    return "";
}

void* FileManager::getPathList() const
{
    // TODO: Implement
    return nullptr;
}

void FileManager::addPath(std::string const&)
{
    // TODO: Implement
}

void FileManager::removePath(std::string const&)
{
}

void FileManager::removeAllPaths()
{
    // TODO: Implement
}

void FileManager::getWritePath(std::string const&, std::string&)
{
    // TODO: Implement
}

FileResolveMode FileManager::getFileResolveMode() const
{
    return m_fileResolveMode;
}

void FileManager::setFileResolveMode(FileResolveMode fileResolveMode)
{
    m_fileResolveMode = fileResolveMode;
}

std::string const& FileManager::fileExistsEx(std::string const&, bool)
{
    // TODO: Implement
    return "";
}

std::string const& FileManager::fileExistsEx2(std::string const&)
{
    // TODO: Implement
    return "";
}
