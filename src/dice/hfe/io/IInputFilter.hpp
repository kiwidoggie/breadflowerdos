#pragma once

namespace dice::hfe::io
{
	class GameInput;
	class PlayerInput;

	class IInputFilter
	{
	public:
		// virtual ~IInputFilter(); // TODO: Figure out if this is
		// needed
		virtual void filterGameInput(dice::hfe::io::GameInput* p_GameInput) = 0;
		virtual void
		filterPlayerInput(dice::hfe::io::PlayerInput* p_PlayerInput) = 0;
	};
}	 // namespace dice::hfe::io
