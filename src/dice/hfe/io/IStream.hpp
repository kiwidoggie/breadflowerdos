#pragma once

#include <dice/hfe/IBase.hpp>

namespace dice
{
	namespace hfe
	{
		namespace io
		{
			class SeekOrigin;

			const uint32_t IID_IStream = 0x6317C8FE;

			class IStream : public IBase {
			public:
				virtual void read(void*, unsigned int) = 0;
				virtual void write(void const*, unsigned int) = 0;
				virtual void skip(unsigned int) = 0;
				virtual void getAvailableBytes(void) = 0;
				virtual void clone(void) = 0;
				virtual void canRead(void) = 0;
				virtual void canWrite(void) = 0;
				virtual void flushWrite(void) = 0;
				virtual void seek(SeekOrigin, int) = 0;
				virtual void getPosition(void) = 0;
				virtual void getSize(void) = 0;
				virtual ~IStream() = 0;
			};

		}
	}
}