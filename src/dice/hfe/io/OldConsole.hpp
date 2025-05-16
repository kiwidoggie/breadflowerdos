#pragma once

#include "Console.hpp"

namespace dice
{
	namespace hfe
	{
		namespace io
		{
			class OldConsole : public Console {
			public:
				ConsoleCompiler* m_consoleCompiler;
			public:
				virtual ~OldConsole() = default;
				virtual void setConsoleCompiler(ConsoleCompiler*) override;
				virtual void executeLine(std::string const&, std::string&, bool, bool, bool, bool, bool) override;
				virtual void executeLines(std::list<std::string> const&, std::list<std::string>&, bool, bool, bool) override;
				virtual void output(std::string const&) override;
				virtual void updateAsciiKey(char) override;
				virtual void updateGameInput(GameInput const&) override;
				virtual void updateKeyMacros(GameInput const&) override;
				virtual void getLines(int32_t, std::vector<std::string>&) const override;
				virtual bool run(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&) override;
				virtual bool runFullAccess(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string& ignoredString = ignoredString_) override;
				virtual bool include(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&) override;
				virtual bool bindKeyToConsoleScript(int32_t, std::string const&) override;
				virtual void setExitCallBack(void (*)(void*), void*) override;
				virtual void update(char, std::string&, std::vector<std::string>&) override;
				virtual bool addVariable(std::string const&, std::string const&) override;
				virtual bool addConstant(std::string const&, std::string const&) override;
				virtual std::string const& listVariables(std::string const&) override;
				virtual std::string const& listConstants(std::string const&) override;
				virtual void setEchoErrors(bool) override;
				virtual bool getEchoErrors() override;
				virtual void setEcho(bool) override;
				virtual bool getEcho() const override;
				virtual void setMaxLineSize(int32_t) override;
				virtual int32_t getMaxLineSize() const override;
				virtual void setMaxHistorySize(int32_t) override;
				virtual int32_t getMaxHistorySize() const override;
				virtual void setMaxCommandHistorySize(int32_t) override;
				virtual int32_t getMaxCommandHistorySize() const override;
				virtual void setUseRelativePaths(bool) override;
				virtual bool getUseRelativePaths() const override;
				virtual void setAllowMultipleFileLoad(bool) override;
				virtual bool getAllowMultipleFileLoad() const override;
				virtual std::string const& getWorkingPath() const override;
				virtual void setWorkingPath(std::string const&) override;
				virtual std::string const& getWorkingFile() const override;
				virtual std::string const& getWorkingFileAndLine() const override;
				virtual void setAccess(int32_t) override;
				virtual int32_t getAccess() const override;
				virtual void setCurrentLine(std::string&) override;
				virtual void addAutoComplArgument(std::string const&) override;
				virtual void removeAutoComplArgument(std::string const&) override;
				virtual void setHandleCommandHook(bool (*)(char const*, int32_t)) override;
			};

			extern OldConsole* g_mainConsole;
		}
	}
}
