#pragma once
#include <list>
#include <dice/hfe/io/PlayerAction.hpp>

namespace dice
{
    namespace hfe 
    {
        using ActionBufferEntry = io::PlayerAction;

        class ActionBuffer {
        public:
            std::list<ActionBufferEntry> m_entries;
            int _0x14;
            unsigned int m_lastActionTick;
            ActionBufferEntry m_lastAction;
            int _0x34;
        };

        static_assert(sizeof(ActionBuffer) == 0x38);
    }
}