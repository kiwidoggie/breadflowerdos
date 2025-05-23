#include "FileModule.hpp"
#include "FileChangeManager.hpp"

using namespace dice::hfe::io;

/**
 * @brief Adds a reference to this class
 */
void FileModule::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t FileModule::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t FileModule::release()
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
 * @param p_param
 * @return FileModule*
 */
FileModule* FileModule::queryInterface(uint32_t p_param)
{
	if (p_param == IID_IBase)
		return this;

	if (p_param == IID_IClassServer)
		return this;

	if (p_param == IID_IModule)
		return this;

	return nullptr;
}

void FileModule::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
	{
		auto regInfo = ClassRegInfo(CID_FileManager,
	 * "dice.hfe.io.FileManager.Standard", FileManager::create);

	 * regInfos.push_back(regInfo);
	}*/
	{
		auto s_RegInfo = ClassRegInfo(
			CID_FileChangeManager,
			"dice.hfe.io.FileChangeManager.Standard",
			FileChangeManager::create);
		regInfos.push_back(s_RegInfo);
	}
	/*{
		auto regInfo =
	 * ClassRegInfo(CID_UnixFileSystem, "dice.hfe.io.FileSystem.Unix",
	 * UnixFileSystem::create);
		regInfos.push_back(regInfo);
	}
 {

	 * auto regInfo = ClassRegInfo(CID_ZipArchiveHandler,
	 * "dice.hfe.io.ArchiveHandler.ZIP", ZipArchiveHandler::create);

	 * regInfos.push_back(regInfo);
	}
	{
		auto regInfo =
	 * ClassRegInfo(CID_MemStream, "dice.hfe.io.Stream.Memory",
	 * MemStream::create);
		regInfos.push_back(regInfo);
	}
	{

	 * auto regInfo = ClassRegInfo(CID_BufferedStream,
	 * "dice.hfe.io.Stream.Buffered", BufferedStream::create);

	 * regInfos.push_back(regInfo);
	}
	*/
}

void FileModule::getSingletonList(
	[[maybe_unused]] std::vector<SingletonRegInfo>& regInfos)
{
}

bool FileModule::init()
{
	return true;
}

bool FileModule::close()
{
	return true;
}
