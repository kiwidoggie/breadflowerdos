#pragma once

#include <cstdint>
#include <list>
#include <string>
#include <vector>

namespace dice::hfe::io
{
	class ConsoleCompiler;
	class GameInput;

	class Console
	{
	private:
		bool m_active;

	public:
		virtual ~Console() = default;
		virtual void setConsoleCompiler(ConsoleCompiler*) = 0;
		virtual void executeLine(
			const std::string&, std::string&, bool, bool, bool, bool, bool) = 0;
		virtual void executeLines(
			const std::list<std::string>&, std::list<std::string>&, bool, bool,
			bool) = 0;
		virtual void output(const std::string&) = 0;
		virtual void updateAsciiKey(char) = 0;
		virtual void updateGameInput(const GameInput&) = 0;
		virtual void updateKeyMacros(const GameInput&) = 0;
		virtual void getLines(int32_t, std::vector<std::string>&) const = 0;
		virtual bool
		run(const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			std::string&) = 0;
		virtual bool runFullAccess(
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			std::string&) = 0;
		virtual bool include(
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			const std::string&, const std::string&, const std::string&,
			std::string&) = 0;
		virtual bool bindKeyToConsoleScript(int32_t, const std::string&) = 0;
		virtual void setExitCallBack(void (*)(void*), void*) = 0;
		virtual void update(char, std::string&, std::vector<std::string>&) = 0;
		virtual bool addVariable(const std::string&, const std::string&) = 0;
		virtual bool addConstant(const std::string&, const std::string&) = 0;
		virtual const std::string& listVariables(const std::string&) = 0;
		virtual const std::string& listConstants(const std::string&) = 0;
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
		virtual const std::string& getWorkingPath() const = 0;
		virtual void setWorkingPath(const std::string&) = 0;
		virtual const std::string& getWorkingFile() const = 0;
		virtual const std::string& getWorkingFileAndLine() const = 0;
		virtual void setAccess(int32_t) = 0;
		virtual int32_t getAccess() const = 0;
		virtual void setCurrentLine(std::string&) = 0;

		virtual void setConsoleActive(bool active)
		{
			m_active = active;
		}

		virtual bool getConsoleActive()
		{
			return m_active;
		}

		virtual void loadCommandHistory(const std::string&) { }

		virtual void saveCommandHistory(const std::string&) { }

		virtual void addAutoComplArgument(const std::string&) = 0;
		virtual void removeAutoComplArgument(const std::string&) = 0;
		virtual void setHandleCommandHook(bool (*)(const char*, int32_t)) = 0;

		static std::string ignoredString_;
	};
}	 // namespace dice::hfe::io
