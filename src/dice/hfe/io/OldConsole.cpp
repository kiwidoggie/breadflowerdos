#include "OldConsole.hpp"

#include <dice/hfe/EventManager.hpp>

#include <sstream>

using namespace dice::hfe::io;

OldConsole* dice::hfe::io::g_mainConsole = new OldConsole();

// bf2: 007a81c0
void OldConsole::setConsoleCompiler(ConsoleCompiler* consoleCompiler)
{
	m_consoleCompiler = consoleCompiler;
}

// bf2: 007b4610
void OldConsole::executeLine(
	const std::string& input, std::string& outputStr, bool sendToOutput, bool,
	bool saveToHistory, bool, bool)
{
	std::istringstream iss(input);
	std::string line;
	while (true)
	{
		while (true)
		{
			if (!std::getline(iss, line))
			{
				// EOF or read failure
				return;
			}

			// Remove '\r' at end if present
			if (!line.empty() && line.back() == '\r')
			{
				line.pop_back();
			}

			if (line.empty())
			{
				// Skip empty lines and continue reading
				continue;
			}

			// Optionally add to command history
			if (saveToHistory)
			{
				// TODO: addToCommandHistory(line);
			}

			if (sendToOutput)
			{
				// TODO: output(m_unknown170 + line);
			}

			if (!line.starts_with("rcon "))
			{
				break;
			}

			// Skip "rcon " prefix when sending data to event manager
			const char* data = line.c_str() + 5;
			g_eventManager
				->postEvent(EventCategory::ECNetwork, 12, (void*)data, 0.f);

			outputStr += "\n";
		}

		if (m_consoleCompiler != nullptr)
		{
			// TODO: m_consoleCompiler->addLine(line);
		}

		// TODO: Implement
		return;
	}
}

// bf2: 007aa590
void OldConsole::executeLines(
	const std::list<std::string>&, std::list<std::string>&, bool, bool, bool)
{
	// TODO: Implement
}

void OldConsole::output(const std::string&) { }

void OldConsole::updateAsciiKey(char) { }

void OldConsole::updateGameInput(const GameInput&) { }

void OldConsole::updateKeyMacros(const GameInput&) { }

void OldConsole::getLines(int32_t, std::vector<std::string>&) const { }

bool OldConsole::run(
	const std::string&, const std::string&, const std::string&,
	const std::string&, const std::string&, const std::string&,
	const std::string&, const std::string&, const std::string&, std::string&)
{
	return false;
}

bool OldConsole::runFullAccess(
	const std::string&, const std::string&, const std::string&,
	const std::string&, const std::string&, const std::string&,
	const std::string&, const std::string&, const std::string&, std::string&)
{
	return false;
}

bool OldConsole::include(
	const std::string&, const std::string&, const std::string&,
	const std::string&, const std::string&, const std::string&,
	const std::string&, const std::string&, const std::string&, std::string&)
{
	return false;
}

bool OldConsole::bindKeyToConsoleScript(int32_t, const std::string&)
{
	return false;
}

void OldConsole::setExitCallBack(void (*)(void*), void*) { }

void OldConsole::update(char, std::string&, std::vector<std::string>&) { }

bool OldConsole::addVariable(const std::string&, const std::string&)
{
	return false;
}

bool OldConsole::addConstant(const std::string&, const std::string&)
{
	return false;
}

const std::string& OldConsole::listVariables(const std::string&)
{
	return "";
}

const std::string& OldConsole::listConstants(const std::string&)
{
	return "";
}

void OldConsole::setEchoErrors(bool) { }

bool OldConsole::getEchoErrors()
{
	return false;
}

void OldConsole::setEcho(bool) { }

bool OldConsole::getEcho() const
{
	return false;
}

void OldConsole::setMaxLineSize(int32_t) { }

int32_t OldConsole::getMaxLineSize() const
{
	return 0;
}

void OldConsole::setMaxHistorySize(int32_t) { }

int32_t OldConsole::getMaxHistorySize() const
{
	return 0;
}

void OldConsole::setMaxCommandHistorySize(int32_t) { }

int32_t OldConsole::getMaxCommandHistorySize() const
{
	return 0;
}

void OldConsole::setUseRelativePaths(bool) { }

bool OldConsole::getUseRelativePaths() const
{
	return false;
}

void OldConsole::setAllowMultipleFileLoad(bool) { }

bool OldConsole::getAllowMultipleFileLoad() const
{
	return false;
}

const std::string& OldConsole::getWorkingPath() const
{
	return "";
}

void OldConsole::setWorkingPath(const std::string&) { }

const std::string& OldConsole::getWorkingFile() const
{
	return "";
}

const std::string& OldConsole::getWorkingFileAndLine() const
{
	return "";
}

void OldConsole::setAccess(int32_t) { }

int32_t OldConsole::getAccess() const
{
	return 0;
}

void OldConsole::setCurrentLine(std::string&) { }

void OldConsole::addAutoComplArgument(const std::string&) { }

void OldConsole::removeAutoComplArgument(const std::string&) { }

void OldConsole::setHandleCommandHook(bool (*)(const char*, int32_t)) { }
