#include "ClassManager.hpp"
#include "IClassServer.hpp"
#include "ClassRegInfo.hpp"
#include "Debug.hpp"

using namespace dice::hfe;

ClassManager* dice::hfe::g_classManager = nullptr;

/**
 * @brief Adds a reference to this class
 */
void ClassManager::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t ClassManager::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ClassManager::release()
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
 * @return System*
 */
ClassManager* ClassManager::queryInterface(uint32_t p_param)
{
    if (p_param == IID_IBase)
        return this;

    if (p_param == IID_IClassManager)
        return this;

    return nullptr;
}

ClassManager::~ClassManager()
{
    // TODO: Implement
}

// bf2: 00734d80
void ClassManager::registerServer(IClassServer* server)
{
    // TODO: Recheck if done correctly.
    addServer(server);
    std::vector<ClassRegInfo> classRegInfos;
    server->getClassList(classRegInfos);

    for (auto& regInfo : classRegInfos)
    {
        ClassInfo classInfo(regInfo, server);
        if (getClassInfo(regInfo.id, classInfo))
        {
            BF2_ERROR("Duplicate registration of class id " << regInfo.id << ". Already used by:" << classInfo.name << " tried to set new name:" << regInfo.name);
        }
        if (getClassInfo(regInfo.name, classInfo))
        {
            BF2_ERROR("Duplicate registration of class name \"" << regInfo.name << "\" exists already as: " << classInfo.name);
        }
        m_classInfos.push_back(classInfo);
    }

    std::vector<SingletonRegInfo> singletonRegInfos;
    server->getSingletonList(singletonRegInfos);

    for (auto& regInfo : singletonRegInfos)
    {
        registerSingleton(regInfo);
    }
}

void ClassManager::unregisterServer(IClassServer* server)
{
    // TODO: Implement
}

void ClassManager::setDefaultClass(unsigned int iid, unsigned int cid)
{
    m_defaultClasses[iid] = cid;
}

bool ClassManager::getDefaultClass(unsigned int iid, unsigned int& cid)
{
    auto it = m_defaultClasses.find(iid);
    if (it != m_defaultClasses.end()) {
        cid = it->second;
        return true;
    }
    return false;
}

bool ClassManager::getClassName(unsigned int id, std::string& name)
{
    ClassInfo info;
    if (getClassInfo(id, info))
    {
        name = info.name;
        return true;
    }
    return false;
}

bool ClassManager::getClassID(std::string const&, unsigned int&)
{
    // TODO: Implement
    return false;
}

bool ClassManager::createInstance(unsigned int, IBase*)
{
    // TODO: Implement
    return false;
}

IBase* ClassManager::createInstance(unsigned int cid, unsigned int iid, IBase* baseClass)
{
    ClassInfo info;
    if (getClassInfo(cid, info))
    {
        return info.func(iid, baseClass);
    }

    return nullptr;
}

bool ClassManager::createInstance(std::string const&, unsigned int, IBase*)
{
    // TODO: Implement
    return false;
}

bool ClassManager::setSingletonClass(std::string const&, unsigned int)
{
    // TODO: Implement
    return false;
}

bool ClassManager::getSingletonClass(std::string const&, unsigned int&)
{
    // TODO: Implement
    return false;
}

void ClassManager::registerSingleton(SingletonRegInfo const& regInfo)
{
    // TODO: Implement
    SingletonInfo info(regInfo);
    m_singletonInfos.emplace(regInfo.name, info);
    if (info.createOnRegister)
    {
        createSingleton(regInfo.name, info);
    }
}

void ClassManager::unregisterSingleton(std::string const&)
{
    // TODO: Implement
}

void* ClassManager::getSingleton(std::string const&)
{
    // TODO: Implement
    return nullptr;
}

void* ClassManager::getSingletonAs(std::string const&, unsigned int)
{
    // TODO: Implement
    return nullptr;
}

void ClassManager::registerSimpleSingleton(std::string const&, void*)
{
    // TODO: Implement
}

void ClassManager::unregisterSimpleSingleton(std::string const&)
{
    // TODO: Implement
}

void* ClassManager::getSimpleSingleton(std::string const&) const
{
    // TODO: Implement
    return nullptr;
}

void ClassManager::getPrintableSingletonList() const
{
    // TODO: Implement
}

void ClassManager::getAllClassIncludingSubstring(std::string const&, std::vector<std::string>&) const
{
    // TODO: Implement
}

// bf2: 007356e0
void ClassManager::initSingletons()
{
    for (auto& info : m_singletonInfos)
    {
        if (info.second.createOnInit)
        {
            createSingleton(info.first, info.second);
        }
    }

    m_singletonsInitialized = true;
}

bool ClassManager::findServer(IClassServer* server)
{
    auto it = m_servers.find(server);
    return it != m_servers.end();
}

void ClassManager::addServer(IClassServer* server)
{
    findServer(server); // TODO: why is this unused ???
    m_servers.insert(server);
}

bool ClassManager::getClassInfo(uint32_t id, ClassInfo& info)
{
    for (auto& classInfo : m_classInfos)
    {
        if (classInfo.id == id)
        {
            info = classInfo; // TODO: does this work?
            return true;
        }
    }
    return false;
}

bool dice::hfe::ClassManager::getClassInfo(std::string name, ClassInfo& info)
{
    // TODO: Implement
    return false;
}

void ClassManager::createSingleton(std::string const& name, SingletonInfo& info)
{
    if ((*info.singleton) != nullptr)
    {
        (*info.singleton)->release();
    }

    (*info.singleton) = createInstance(info.cid, info.iid, nullptr);
    std::string className;
    if (getClassName(info.cid, className))
    {
        return;
    }

    // TODO: Implement
    // sth with formatString("Unknown ID %d", info.iid);
    // but it looks like nothing gets done with it.
}
