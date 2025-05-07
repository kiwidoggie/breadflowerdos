#pragma once

namespace dice
{
    namespace hfe
    {
        class IEventListener
        {
        public:
            virtual void handleEvent() = 0;
        };
    }
}
