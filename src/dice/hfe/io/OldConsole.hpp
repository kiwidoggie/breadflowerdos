#pragma once
#include "Console.hpp"

namespace dice::hfe::io
{
	class OldConsole : public Console
	{
	public:
		ConsoleCompiler* m_consoleCompiler;

	public:
		virtual ~OldConsole() = default;
		virtual void setConsoleCompiler(ConsoleCompiler*) override;
		virtual void executeLine(
			const std::string&, std::string&, bool, bool, bool, bool,
			bool) override;
		virtual void executeLines(
			const std::list<std::string>&, std::list<std::string>&, bool, bool,
			bool) override;
		virtual void output(const std::string&) override;
		virtual void updateAsciiKey(char) override;
		virtual void updateGameInput(const GameInput&) override;
		virtual void updateKeyMacros(const GameInput&) override;
		virtual void
		getLines(int32_t, std::vector<std::string>&) const override;
		virtual bool
		run(const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			std::string&) override;
		virtual bool runFullAccess(
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			std::string& ignoredString = ignoredString_) override;
		virtual bool include(
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			std::string&) override;
		virtual bool
		bindKeyToConsoleScript(int32_t, const std::string&) override;
		virtual void setExitCallBack(void (*)(void*), void*) override;
		virtual void
		update(char, std::string&, std::vector<std::string>&) override;
		virtual bool
		addVariable(const std::string&, const std::string&) override;
		virtual bool
		addConstant(const std::string&, const std::string&) override;
		virtual const std::string& listVariables(const std::string&) override;
		virtual const std::string& listConstants(const std::string&) override;
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
		virtual const std::string& getWorkingPath() const override;
		virtual void setWorkingPath(const std::string&) override;
		virtual const std::string& getWorkingFile() const override;
		virtual const std::string& getWorkingFileAndLine() const override;
		virtual void setAccess(int32_t) override;
		virtual int32_t getAccess() const override;
		virtual void setCurrentLine(std::string&) override;
		virtual void addAutoComplArgument(const std::string&) override;
		virtual void removeAutoComplArgument(const std::string&) override;
		virtual void
		setHandleCommandHook(bool (*)(const char*, int32_t)) override;
	};

	extern OldConsole* g_mainConsole;
}	 // namespace dice::hfe::io
