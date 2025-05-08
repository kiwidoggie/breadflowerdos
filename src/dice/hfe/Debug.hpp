#pragma once

#include <string>
#include <sstream>

namespace dice
{
    namespace hfe
    {
        enum class DebugType {
            Error = 6,
            Warning = 7,
            Info = 8,
        };

        struct Debug {
            DebugType type;
            std::string filename;
            std::string _0x10;
            int lineNo;
            std::ostringstream oss;

            Debug(DebugType type, std::string const& filename, int lineNo, std::string const& _0x10)
                : type(type), filename(filename), lineNo(lineNo), _0x10(_0x10)
            {
            }

            ~Debug() {
                // TODO: print msg to stdout
            }
        };
    }
}

#define _BF2_DBG(dbg_type, msg) { \
    std::string file = __FILE__; \
    std::string unk = ""; \
    dice::hfe::Debug dbg(dbg_type, file, __LINE__, unk); \
    dbg->oss << msg; \
}

#define BF2_ERROR(msg) _BF2_DBG(dice::hfe::DebugType::Error, msg);
#define BF2_WARNING(msg) _BF2_DBG(dice::hfe::DebugType::Warning, msg);
#define BF2_INFO(msg) _BF2_DBG(dice::hfe::DebugType::Info, msg);
#define BF2_ASSERT(cond) if (!(cond)) _BF2_DBG(dice::hfe::DebugType::Error, #cond);
