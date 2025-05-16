#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/io/INetworkableInfo.hpp>

namespace dice::hfe::io
{
	class BaseLineData;
	class BitStream;
	class INetworkableObject;

	const uint32_t IID_INetworkable = 0x58165FFE;

	class INetworkable : public IBase
	{
	public:
		virtual ~INetworkable() = 0;
		virtual void init(void*) = 0;
		virtual void reset() = 0;
		virtual void addedToManager() = 0;
		virtual void removedFromManager() = 0;
		virtual void getGhostStateMask() = 0;
		virtual void updateStateMask(unsigned int*) = 0;
		virtual void
		getNetUpdate(BitStream&, BaseLineData*, unsigned int, int) = 0;
		virtual void
		setNetUpdate(BitStream&, float, bool, BaseLineData*, int) = 0;
		virtual void getBaseLine(BaseLineData*) = 0;
		virtual void setGhostActive(bool) = 0;
		virtual void getMinimumBitSize() = 0;
		virtual void getAverageUpdateDeltaTime() = 0;

		unsigned short m_netId;	   // 0x08
		char _0x0C[0x5];
		INetworkableInfo* m_networkableInfo;	// 0x10
		char m_ghostActive;						// 0x18
		char _0x19[0x3];
		float m_priority;
		char m_isServerSide;	// 0x20
		char _0x21[0x7];
		INetworkableObject* m_netObj;	 // 0x28
	};

	static_assert(sizeof(INetworkable) == 0x30);
}	 // namespace dice::hfe::io
