#pragma once

#include <dice/hfe/IBase.hpp>
#include <string>

namespace dice::hfe
{
	namespace world
	{
		class IPlayer;
	}

	const uint32_t IID_IStatsManager = 0x1D8BA;

	class IStatsManager : public IBase
	{
	public:
		virtual bool connect() = 0;
		virtual void disconnect() = 0;
		virtual bool newGame() = 0;
		virtual bool endGame() = 0;
		virtual bool isConnected() = 0;
		virtual void* getChallenge() = 0;
		virtual void* getGame() const = 0;
		virtual bool think() = 0;
		virtual bool sendSnapshot(const std::string&) = 0;
		virtual bool sendFinal(const std::string&) = 0;
		virtual bool authenticatePlayer(world::IPlayer*) = 0;
	};
}	 // namespace dice::hfe
