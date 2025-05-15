#pragma once

#include <dice/hfe/io/PlayerInput.hpp>

namespace dice
{
    namespace hfe
    {
        namespace io
        {

            class PlayerAction {
            public:

                static constexpr float AXIS_RESOLUTION = 100.0f;

                unsigned int m_tick;

                // the first 6 inputs from PlayerInputMap (compressed)
                short m_axisInputs[6]; // 0x04

                // rest of the buttons
                unsigned int m_buttonInputs[2]; // 0x10
                unsigned char _0x18;

                inline static short convertAxisToInternalResolution(float axis) {
                    float tmp = axis * AXIS_RESOLUTION;
                    if (tmp < -32767.0f) {
                        tmp = -32767.0f;
                    }
                    else if (tmp > 32767.0f)
                    {
                        tmp = 32767.0f;
                    }
                    return static_cast<short>(tmp);
                }

                void setAxis(PlayerInput& input, PlayerInputMap id) {
                    float* axis = input.getInput(id);
                    m_axisInputs[static_cast<size_t>(id)] = convertAxisToInternalResolution(axis ? *axis : 0.0f);
                }

                void getAxis(PlayerInput& input, PlayerInputMap id) {
                    float axis = m_axisInputs[static_cast<size_t>(id)] / AXIS_RESOLUTION;
                    input.setInput(id, axis);
                }
            };

            static_assert(sizeof(PlayerAction) == 0x1C); // XXX: BF2 mallocs 0x20 for some reason
        }
    }
}