#pragma once

namespace dice::hfe::io
{
	// bf2: 00802a0d
	enum class FileAccess
	{
		Read = 0,		  // O_RDONLY
		ReadWrite = 1,	  // O_RDWR
		Write = 2		  // O_WRONLY
	};
}	 // namespace dice::hfe::io
