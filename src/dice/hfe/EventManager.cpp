#include "EventManager.hpp"
#include "Debug.hpp"

using namespace dice::hfe;

EventManager* dice::hfe::g_eventManager = nullptr;
EventManager* dice::hfe::g_frameEventManager = nullptr;

// bf2: 0084d710
IBase* EventManager::create(uint32_t id, IBase* eventManager)
{
	eventManager = new EventManager();
	if (eventManager->queryInterface(id) == nullptr)
	{
		eventManager->release();
	}

	return eventManager;
}

EventManager::EventManager() :
	m_refCount(1),
	m_dispatchCounter(0),
	m_unknown10(0),
	m_currentEvent(nullptr),
	m_currentTime(0.0),
	m_unknownC0(1)
{
	// TODO: Implement

	for (size_t i = 0; i < static_cast<size_t>(EventCategory::ECCount); ++i)
	{
		m_eventHandlerRegistry[i] = nullptr;
	}
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
 * @return uint32_t Current
 * reference count
 */
uint32_t EventManager::getRef()
{
	return m_refCount;
}

/**
 * @brief Removes a reference from this class. Calls the deconstructor if
 * there are no more references.
 * @return uint32_t Current reference count
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
 * @param iid
 * @return EventManager*
 */
IBase* EventManager::queryInterface(uint32_t iid)
{
	if (iid == IID_IBase)
		return this;

	if (iid == IID_IEventManager)
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

bool EventManager::registerEventHandler(
	EventCategory category, IEventListener* listener, int32_t priority)
{
	if (listener == nullptr || category >= EventCategory::ECCount)
	{
		return false;
	}

	auto* node = new EventHandlerRegistryNode;
	node->listener = listener;
	node->next = nullptr;
	node->priority = priority;

	size_t index = static_cast<size_t>(category);
	EventHandlerRegistryNode*& head = m_eventHandlerRegistry[index];

	// Insert in priority order
	if (head == nullptr || head->priority >= priority)
	{
		node->next = head;
		head = node;
		return true;
	}

	EventHandlerRegistryNode* current = head;
	while (current->next && current->next->priority < priority)
	{
		current = current->next;
	}

	node->next = current->next;
	current->next = node;
	return true;
}

bool EventManager::unregisterEventHandler(EventCategory, IEventListener*)
{
	// TODO: Implement
	return false;
}

bool EventManager::registerEvent(
	EventCategory cat, uint32_t eventId, const std::string& eventName)
{
	auto& eventRegistry = m_eventRegistry[static_cast<size_t>(cat)];
	auto it = eventRegistry.find(eventId);
	if (it != eventRegistry.end())
	{
		BF2_ERROR(
			"Event " << eventId << " in cat " << static_cast<size_t>(cat)
					 << " already registered as " << it->second);
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
