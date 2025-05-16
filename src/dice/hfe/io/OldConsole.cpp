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
}

void OldConsole::output(std::string const&)
{
}

void OldConsole::updateAsciiKey(char)
{
}

void OldConsole::updateGameInput(GameInput const&)
{
}

void OldConsole::updateKeyMacros(GameInput const&)
{
}

void OldConsole::getLines(int32_t, std::vector<std::string>&) const
{
}

bool OldConsole::run(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&)
{
	return false;
}

bool OldConsole::runFullAccess(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&)
{
	return false;
}

bool OldConsole::include(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string&)
{
	return false;
}

bool OldConsole::bindKeyToConsoleScript(int32_t, std::string const&)
{
	return false;
}

void OldConsole::setExitCallBack(void(*)(void*), void*)
{
}

void OldConsole::update(char, std::string&, std::vector<std::string>&)
{
}

bool OldConsole::addVariable(std::string const&, std::string const&)
{
	return false;
}

bool OldConsole::addConstant(std::string const&, std::string const&)
{
	return false;
}

std::string const& OldConsole::listVariables(std::string const&)
{
	return "";
}

std::string const& OldConsole::listConstants(std::string const&)
{
	return "";
}

void OldConsole::setEchoErrors(bool)
{
}

bool OldConsole::getEchoErrors()
{
	return false;
}

void OldConsole::setEcho(bool)
{
}

bool OldConsole::getEcho() const
{
	return false;
}

void OldConsole::setMaxLineSize(int32_t)
{
}

int32_t OldConsole::getMaxLineSize() const
{
	return 0;
}

void OldConsole::setMaxHistorySize(int32_t)
{
}

int32_t OldConsole::getMaxHistorySize() const
{
	return 0;
}

void OldConsole::setMaxCommandHistorySize(int32_t)
{
}

int32_t OldConsole::getMaxCommandHistorySize() const
{
	return 0;
}

void OldConsole::setUseRelativePaths(bool)
{
}

bool OldConsole::getUseRelativePaths() const
{
	return false;
}

void OldConsole::setAllowMultipleFileLoad(bool)
{
}

bool OldConsole::getAllowMultipleFileLoad() const
{
	return false;
}

std::string const& OldConsole::getWorkingPath() const
{
	return "";
}

void OldConsole::setWorkingPath(std::string const&)
{
}

std::string const& OldConsole::getWorkingFile() const
{
	return "";
}

std::string const& OldConsole::getWorkingFileAndLine() const
{
	return "";
}

void OldConsole::setAccess(int32_t)
{
}

int32_t OldConsole::getAccess() const
{
	return 0;
}

void OldConsole::setCurrentLine(std::string&)
{
}

void OldConsole::addAutoComplArgument(std::string const&)
{
}

void OldConsole::removeAutoComplArgument(std::string const&)
{
}

void OldConsole::setHandleCommandHook(bool(*)(char const*, int32_t))
{
}
