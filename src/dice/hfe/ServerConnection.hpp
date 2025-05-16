#pragma once

#include <dice/hfe/ClientConnection.hpp>

namespace dice::hfe
{
	class ServerConnection : public ClientConnection
	{
	public:

		unsigned int _0x1E8;
		unsigned int _0x1EC;
		int _0x1F0;
		int _0x1F4;
	};

	static_assert(sizeof(ServerConnection) == 0x1F8);
}	 // namespace dice::hfe
