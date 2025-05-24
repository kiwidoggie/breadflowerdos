#pragma once

#include <dice/hfe/io/INetworkable.hpp>
#include <vector>

namespace dice::hfe::io
{
	typedef std::vector<int> UniqueNetProperty;

	struct NetworkableDescriptor
	{
		unsigned int m_pcoId;
		unsigned short m_networkId;
		char _0x6[0xa];
		std::vector<std::vector<INetworkable*>> m_netProps;
		unsigned char _0x1C;
		unsigned char _0x1D[3];
		unsigned int m_minBitSize;
	};

#if defined(WIN32)
	// TODO: Win32 static_assert
#else
	static_assert(sizeof(NetworkableDescriptor) == 0x30);
#endif
}	 // namespace dice::hfe::io
