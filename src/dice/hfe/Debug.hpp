#pragma once

#include <sstream>
#include <string>

namespace dice::hfe
{
	// bf2: 004e481f
	enum class DebugType
	{
		DTDebug = 0,
		DTInfo = 1,
		DTWarning = 2,
		DTAssert = 3,
		DxAssert = 5,
		DTError = 6,
		Log = 8,
	};

	struct Debug
	{
		DebugType type;
		std::string filename;
		std::string _0x10;
		int lineNo;
		std::ostringstream oss;

		Debug(
			DebugType type, const std::string& filename, int lineNo,
			const std::string& _0x10) :
			type(type),
			filename(filename),
			_0x10(_0x10),
			lineNo(lineNo)
		{
		}

		~Debug()
		{
			// TODO: print msg to stdout
		}
	};
}	 // namespace dice::hfe

#define _BF2_DBG(dbg_type, msg)                              \
	{                                                        \
		std::string file = __FILE__;                         \
		std::string unk = "";                                \
		dice::hfe::Debug dbg(dbg_type, file, __LINE__, unk); \
		dbg.oss << msg;                                      \
	}

#define BF2_ERROR(msg)	 _BF2_DBG(dice::hfe::DebugType::DTError, msg);
#define BF2_WARNING(msg) _BF2_DBG(dice::hfe::DebugType::DTWarning, msg);
#define BF2_INFO(msg)	 _BF2_DBG(dice::hfe::DebugType::DTInfo, msg);
#define BF2_ASSERT(cond)                                 \
	if (!(cond))                                         \
		_BF2_DBG(dice::hfe::DebugType::DTAssert, #cond);
