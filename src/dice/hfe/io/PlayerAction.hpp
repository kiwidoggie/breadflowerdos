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

                unsigned int m_Tick;

                // the first 6 inputs from PlayerInputMap (compressed)
                short m_AxisInputs[6]; // 0x04

                // rest of the buttons
                unsigned int m_ButtonInputs[2]; // 0x10
                unsigned char m_Unknown18;

                inline static short convertAxisToInternalResolution(float p_Axis) 
                {
                    float s_Temp = p_Axis * AXIS_RESOLUTION;
                    if (s_Temp < -32767.0f) {
                        s_Temp = -32767.0f;
                    }
                    else if (s_Temp > 32767.0f)
                    {
                        s_Temp = 32767.0f;
                    }
                    return static_cast<short>(s_Temp);
                }

                void setAxis(PlayerInput& p_Input, PlayerInputMap p_Id) 
                {
                    float* s_Axis = p_Input.getInput(p_Id);
                    m_AxisInputs[static_cast<size_t>(p_Id)] = convertAxisToInternalResolution(s_Axis ? *s_Axis : 0.0f);
                }

                void getAxis(PlayerInput& p_Input, PlayerInputMap p_Id) 
                {
                    float s_Axis = m_AxisInputs[static_cast<size_t>(p_Id)] / AXIS_RESOLUTION;
                    p_Input.setInput(p_Id, s_Axis);
                }
            };

            static_assert(sizeof(PlayerAction) == 0x1C); // XXX: BF2 mallocs 0x20 for some reason
        }
    }
}