#pragma once

#include <string>
#include <list>
#include <vector>
#include <cstdint>

namespace dice
{
	namespace hfe
	{
		namespace io
		{
			class ConsoleCompiler;
			class GameInput;

			class Console {
			private:
				bool m_active;
			public:
				virtual ~Console() = default;
				virtual void setConsoleCompiler(ConsoleCompiler*) = 0;
				virtual void executeLine(std::string const&, std::string&, bool, bool, bool, bool, bool) = 0;
				virtual void executeLines(std::list<std::string> const&, std::list<std::string>&, bool, bool, bool) = 0;
				virtual void output(std::string const&) = 0;
				virtual void updateAsciiKey(char) = 0;
				virtual void updateGameInput(GameInput const&) = 0;
				virtual void updateKeyMacros(GameInput const&) = 0;
				virtual void getLines(int32_t, std::vector<std::string>&) const = 0;
				virtual bool run(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&) = 0;
				virtual bool runFullAccess(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&) = 0;
				virtual bool include(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&) = 0;
				virtual bool bindKeyToConsoleScript(int32_t, std::string const&) = 0;
				virtual void setExitCallBack(void (*)(void*), void*) = 0;
				virtual void update(char, std::string&, std::vector<std::string>&) = 0;
				virtual bool addVariable(std::string const&, std::string const&) = 0;
				virtual bool addConstant(std::string const&, std::string const&) = 0;
				virtual std::string const& listVariables(std::string const&) = 0;
				virtual std::string const& listConstants(std::string const&) = 0;
				virtual void setEchoErrors(bool) = 0;
				virtual bool getEchoErrors() = 0;
				virtual void setEcho(bool) = 0;
				virtual bool getEcho() const = 0;
				virtual void setMaxLineSize(int32_t) = 0;
				virtual int32_t getMaxLineSize() const = 0;
				virtual void setMaxHistorySize(int32_t) = 0;
				virtual int32_t getMaxHistorySize() const = 0;
				virtual void setMaxCommandHistorySize(int32_t) = 0;
				virtual int32_t getMaxCommandHistorySize() const = 0;
				virtual void setUseRelativePaths(bool) = 0;
				virtual bool getUseRelativePaths() const = 0;
				virtual void setAllowMultipleFileLoad(bool) = 0;
				virtual bool getAllowMultipleFileLoad() const = 0;
				virtual std::string const& getWorkingPath() const = 0;
				virtual void setWorkingPath(std::string const&) = 0;
				virtual std::string const& getWorkingFile() const = 0;
				virtual std::string const& getWorkingFileAndLine() const = 0;
				virtual void setAccess(int32_t) = 0;
				virtual int32_t getAccess() const = 0;
				virtual void setCurrentLine(std::string&) = 0;
				virtual void setConsoleActive(bool active) { m_active = active; }
				virtual bool getConsoleActive() { return m_active; }
				virtual void loadCommandHistory(std::string const&) {}
				virtual void saveCommandHistory(std::string const&) {}
				virtual void addAutoComplArgument(std::string const&) = 0;
				virtual void removeAutoComplArgument(std::string const&) = 0;
				virtual void setHandleCommandHook(bool (*)(char const*, int32_t)) = 0;
			};
		}
	}
}
