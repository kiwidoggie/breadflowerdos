#pragma once

namespace dice::hfe::io
{
	enum class FileMode
	{
		// Truncate if exists, create if missing
		Overwrite = 0,	  // O_CREAT | O_TRUNC // bf2: 00802a90
		// Fail if exists, exclusive create
		CreateNew = 1,		 // O_CREAT | O_EXCL | O_TRUNC // bf2: 00802af6
		OpenExisting = 2,	 // guessed
		// Just ensure it exists, don't truncate
		CreateIfMissing = 3	   // O_CREAT // bf2: 00802b00
	};
}	 // namespace dice::hfe::io
