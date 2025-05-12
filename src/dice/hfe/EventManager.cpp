#include "EventManager.hpp"
#include "Debug.hpp"

using namespace dice::hfe;

EventManager* dice::hfe::g_eventManager = nullptr;

// bf2: 0084d710
IBase* EventManager::create(uint32_t id, IBase* baseClass)
{
    auto eventManager = new EventManager();
    if (eventManager->queryInterface(id) == nullptr)
    {
        eventManager->release();
    }
    baseClass = eventManager;
    return eventManager;
}

EventManager::EventManager() : m_refCount(1)
{
    // TODO: Implement
}

/**
 * @brief Adds a reference to this class
 */
void EventManager::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t EventManager::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t EventManager::release()
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
 * @return EventManager*
 */
IBase* EventManager::queryInterface(uint32_t p_param)
{
    if (p_param == IID_IBase)
        return this;

    if (p_param == IID_IEventManager)
        return this;

    return nullptr;
}

uint32_t EventManager::postEvent(EventCategory, EventNode*, float)
{
    // TODO: Implement
    return 0;
}

uint32_t EventManager::postEvent(EventCategory, uint32_t, void*, float)
{
    // TODO: Implement
    return 0;
}

uint32_t EventManager::postEventNextUpdate(EventCategory, EventNode*)
{
    // TODO: Implement
    return 0;
}

uint32_t EventManager::postEventNextUpdate(EventCategory, uint32_t, void*)
{
    // TODO: Implement
    return 0;
}

bool EventManager::processEvents(float)
{
    // TODO: Implement
    return false;
}

void EventManager::removePendingEvents()
{
    // TODO: Implement
}

bool EventManager::removeEvent(uint32_t)
{
    // TODO: Implement
    return false;
}

bool EventManager::registerEventHandler(EventCategory, IEventListener*, int32_t)
{
    // TODO: Implement
    return false;
}

bool EventManager::unregisterEventHandler(EventCategory, IEventListener*)
{
    // TODO: Implement
    return false;
}

bool EventManager::registerEvent(EventCategory cat, uint32_t eventId, std::string const& eventName)
{
    auto& eventRegistry = m_eventRegistry[static_cast<size_t>(cat)];
    auto it = eventRegistry.find(eventId);
    if (it != eventRegistry.end())
    {
        BF2_ERROR("Event " << eventId << " in cat " << static_cast<size_t>(cat) << " already registered as " << it->second);
        return false;
    }

    eventRegistry.emplace(eventId, eventName);

    return true;
}

bool EventManager::unregisterEvent(EventCategory, uint32_t)
{
    // TODO: Implement
    return false;
}

EventManager::~EventManager()
{
    // TODO: Implement
}
