#pragma once
#include <cstdint>

#include <dice/hfe/EventCategory.hpp>
#include <dice/hfe/EventNode.hpp>
#include <dice/hfe/IEventListener.hpp>

namespace dice::hfe
{
	class Demo : public IEventListener
	{
	private:
		uint64_t m_unknown08;
		uint64_t m_unknown10;
		uint64_t m_unknown18;
		uint8_t m_unknown20;

	public:
		Demo();
		virtual void handleEvent(
			EventCategory p_Category, uint32_t p_Type, EventNode* p_EventNode,
			void* p_data) override;
	};

	static_assert(sizeof(Demo) == 0x28, "incorrect demo size");
}	 // namespace dice::hfe
