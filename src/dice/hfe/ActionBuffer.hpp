#pragma once
#include <dice/hfe/io/PlayerAction.hpp>
#include <list>

namespace dice::hfe
{
	using ActionBufferEntry = io::PlayerAction;

	class ActionBuffer
	{
	public:
		std::list<ActionBufferEntry> m_entries;
		int _0x14;
		unsigned int m_lastActionTick;
		ActionBufferEntry m_lastAction;
		int _0x34;
	};

#if defined(WIN32)
	// TODO: Win32 static_assert
#else
	static_assert(sizeof(ActionBuffer) == 0x38); // bf2: 0049efaa
#endif
}	 // namespace dice::hfe
