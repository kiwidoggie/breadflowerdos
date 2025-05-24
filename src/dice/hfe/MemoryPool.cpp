#include "MemoryPool.hpp"

using namespace dice::hfe;

MemoryPool::MemoryPool()
{
	// TODO: Implement
}

/**
 * @brief Adds a reference to this class
 */
void MemoryPool::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t MemoryPool::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t MemoryPool::release()
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
 * @return MemoryPool*
 */
IBase* MemoryPool::queryInterface(uint32_t p_param)
{
	if (p_param == IID_IBase)
		return this;

	if (p_param == IID_IMemoryPool)
		return this;

	return nullptr;
}

void MemoryPool::alloc(uint32_t)
{
	// TODO: Implement
}

void MemoryPool::free(void*)
{
	// TODO: Implement
}

void MemoryPool::alloc(uint32_t, const char*, uint32_t)
{
	// TODO: Implement
}

void MemoryPool::free(void*, const char*, uint32_t)
{
	// TODO: Implement
}

void MemoryPool::init(int32_t, int32_t, bool)
{
	// TODO: Implement
}

MemoryPool::~MemoryPool()
{
	// TODO: Implement
}

IBase* MemoryPool::create(uint32_t id, IBase* memoryPool)
{
	if (memoryPool == nullptr)
	{
		memoryPool = new MemoryPool();
		if (memoryPool->queryInterface(id) == nullptr)
		{
			memoryPool->release();
		}
	}

	return memoryPool;
}
