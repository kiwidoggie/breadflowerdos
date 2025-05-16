#pragma once

#include <cstdint>

namespace dice::hfe
{
	class EventNode
	{
	public:
		virtual ~EventNode() { }

		virtual void release()
		{
			delete this;
		}

		virtual int32_t getType() = 0;

	public:
		EventCategory m_category;
		double m_eventTime;
		uint32_t m_unknown18;
	};
}	 // namespace dice::hfe
