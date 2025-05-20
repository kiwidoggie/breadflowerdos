#include "FileChangeManager.hpp"

using namespace dice::hfe::io;

FileChangeManager* dice::hfe::io::g_fileChangeManager = nullptr;

// bf2: 008504d0
dice::hfe::IBase* FileChangeManager::create(uint32_t id, IBase* base)
{
    if (base == nullptr)
    { 
        auto fileChangeManager = new FileChangeManager();
        if (fileChangeManager->queryInterface(id) == nullptr)
        {
            fileChangeManager->release();
        }

        base = static_cast<IFileChangeManager*>(fileChangeManager);
    }

    return base;
}

FileChangeManager::FileChangeManager() : m_refCount(1), m_initialized(false), m_unknown60(false), m_delayTime(0.1f), m_enabled(false)
{
    // TODO: Implement
}

void FileChangeManager::init()
{
    m_initialized = true;
}

/**
 * @brief Adds a reference to this class
 */
void FileChangeManager::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t FileChangeManager::getRef()
{
    return m_refCount;
}

/**
 * @brief Removes a reference from this class. Calls the deconstructor if there are no more references.
 * @return uint32_t Current reference count
 */
uint32_t FileChangeManager::release()
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
 * @return FileChangeManager*
 */
dice::hfe::IBase* FileChangeManager::queryInterface(uint32_t iid)
{
    if (iid == IID_IBase)
        return static_cast<IFileChangeManager*>(this);

    if (iid == IID_IFileChangeManager)
        return static_cast<IFileChangeManager*>(this);

    if (iid == IID_IDirectoryChangeListener)
        return static_cast<IDirectoryChangeListener*>(this);

    return nullptr;
}

std::string const& FileChangeManager::addListener(IFileChangeListener*, std::string const& fileName, uint32_t)
{
    if (!m_initialized)
    {
        init();
    }

    if (fileName.empty())
    {
        return "";
    }

    /*g_fileManager->fileExistsEx(fileName, false);

    if (fileName.empty())
    {
        return "";
    }

    fixPathDelimiters(fileName, "/");
    extractFilePath(fileName, "/");
    getFixPath(fileName, "/");

    if (!addPath(fileName))
    {
        return "";
    }*/
    // TODO: Implement

    return fileName;
}

bool FileChangeManager::removeListener(IFileChangeListener*, std::string const&)
{
    // TODO: Implement
    return false;
}

bool FileChangeManager::removeListener(IFileChangeListener*)
{
    // TODO: Implement
    return false;
}

void FileChangeManager::setEnable(bool enable)
{
    m_enabled = enable;
}

bool FileChangeManager::getEnable()
{
    return m_enabled;
}

void FileChangeManager::setDelayTime(float delayTime)
{
    m_delayTime = delayTime;
}

float FileChangeManager::getDelayTime()
{
    return m_delayTime;
}

void FileChangeManager::update()
{
    // TODO: Implement
}

void FileChangeManager::onDirectoryChange(std::string const&, bool, uint32_t)
{
    // TODO: Implement
}

bool FileChangeManager::allowFileChange([[maybe_unused]] std::string const&)
{
    return true;
}
