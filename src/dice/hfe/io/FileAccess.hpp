#pragma once

namespace dice
{
	namespace hfe
	{
		namespace io
		{
			// bf2: 00802a0d
			enum class FileAccess {
				Read = 0,        // O_RDONLY
				ReadWrite = 1,   // O_RDWR
				Write = 2        // O_WRONLY
			};
		}
	}
}
