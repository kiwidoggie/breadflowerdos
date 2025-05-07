#pragma once

namespace dice
{
    namespace hfe
    {
        namespace io
        {
            class IInputFilter
            {
            public:
                virtual ~IInputFilter() = 0;
                virtual void filterGameInput() = 0;
                virtual void filterPlayerInput() = 0;
            };
        }
    }
}
