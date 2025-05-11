#pragma once

#include <vector>
#include <dice/hfe/io/INetworkable.hpp>

namespace dice
{
	namespace hfe
	{
		namespace io
		{
			typedef std::vector<int> UniqueNetProperty;

			struct NetworkableDescriptor
			{
				unsigned int m_PcoId;
				unsigned short m_NetworkId;
				char m_Unknown06[0xa];
				std::vector<std::vector<INetworkable*>> m_NetProps;
				unsigned char m_Unknown1C;
				unsigned char m_Unknown1D[3];
				unsigned int m_MinBitSize;
			};

#if defined(WIN32)
			// TODO: Win32 static_assert
#else
			static_assert(sizeof(NetworkableDescriptor) == 0x30);
#endif
		}
	}
}
