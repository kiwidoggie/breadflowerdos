#include "OldConsole.hpp"
#include <dice/hfe/EventManager.hpp>
#include <sstream>

using namespace dice::hfe::io;

OldConsole* dice::hfe::io::g_mainConsole = new OldConsole();

void OldConsole::setConsoleCompiler(ConsoleCompiler* consoleCompiler)
{
	m_consoleCompiler = consoleCompiler;
}

void OldConsole::executeLine(std::string const& input, std::string& outputStr, bool sendToOutput, bool, bool saveToHistory, bool, bool)
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
			g_eventManager->postEvent(EventCategory::ECNetwork, 12, (void*)data, 0.f);

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

void OldConsole::executeLines(std::list<std::string> const&, std::list<std::string>&, bool, bool, bool)
{
	// TODO: Implement
}

void OldConsole::output(std::string const&)
{
	// TODO: Implement
}

void OldConsole::updateAsciiKey(char)
{
	// TODO: Implement
}

void OldConsole::updateGameInput(GameInput const&)
{
	// TODO: Implement
}

void OldConsole::updateKeyMacros(GameInput const&)
{
	// TODO: Implement
}

void OldConsole::getLines(int32_t, std::vector<std::string>&) const
{
	// TODO: Implement
}

bool OldConsole::run(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&)
{
	// TODO: Implement
	return false;
}

bool OldConsole::runFullAccess(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&)
{
	// TODO: Implement
	return false;
}

bool OldConsole::include(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&)
{
	// TODO: Implement
	return false;
}

bool OldConsole::bindKeyToConsoleScript(int32_t, std::string const&)
{
	// TODO: Implement
	return false;
}

void OldConsole::setExitCallBack(void(*)(void*), void*)
{
	// TODO: Implement
}

void OldConsole::update(char, std::string&, std::vector<std::string>&)
{
	// TODO: Implement
}

bool OldConsole::addVariable(std::string const&, std::string const&)
{
	// TODO: Implement
	return false;
}

bool OldConsole::addConstant(std::string const&, std::string const&)
{
	// TODO: Implement
	return false;
}

std::string const& OldConsole::listVariables(std::string const&)
{
	// TODO: Implement
	return "";
}

std::string const& OldConsole::listConstants(std::string const&)
{
	// TODO: Implement
	return "";
}

void OldConsole::setEchoErrors(bool)
{
	// TODO: Implement
}

bool OldConsole::getEchoErrors()
{
	// TODO: Implement
	return false;
}

void OldConsole::setEcho(bool)
{
	// TODO: Implement
}

bool OldConsole::getEcho() const
{
	// TODO: Implement
	return false;
}

void OldConsole::setMaxLineSize(int32_t)
{
	// TODO: Implement
}

int32_t OldConsole::getMaxLineSize() const
{
	// TODO: Implement
	return 0;
}

void OldConsole::setMaxHistorySize(int32_t)
{
	// TODO: Implement
}

int32_t OldConsole::getMaxHistorySize() const
{
	// TODO: Implement
	return 0;
}

void OldConsole::setMaxCommandHistorySize(int32_t)
{
	// TODO: Implement
}

int32_t OldConsole::getMaxCommandHistorySize() const
{
	// TODO: Implement
	return 0;
}

void OldConsole::setUseRelativePaths(bool)
{
	// TODO: Implement
}

bool OldConsole::getUseRelativePaths() const
{
	// TODO: Implement
	return false;
}

void OldConsole::setAllowMultipleFileLoad(bool)
{
	// TODO: Implement
}

bool OldConsole::getAllowMultipleFileLoad() const
{
	// TODO: Implement
	return false;
}

std::string const& OldConsole::getWorkingPath() const
{
	// TODO: Implement
	return "";
}

void OldConsole::setWorkingPath(std::string const&)
{
	// TODO: Implement
}

std::string const& OldConsole::getWorkingFile() const
{
	// TODO: Implement
	return "";
}

std::string const& OldConsole::getWorkingFileAndLine() const
{
	// TODO: Implement
	return "";
}

void OldConsole::setAccess(int32_t)
{
	// TODO: Implement
}

int32_t OldConsole::getAccess() const
{
	// TODO: Implement
	return 0;
}

void OldConsole::setCurrentLine(std::string&)
{
	// TODO: Implement
}

void OldConsole::addAutoComplArgument(std::string const&)
{
	// TODO: Implement
}

void OldConsole::removeAutoComplArgument(std::string const&)
{
	// TODO: Implement
}

void OldConsole::setHandleCommandHook(bool(*)(char const*, int32_t))
{
	// TODO: Implement
}
