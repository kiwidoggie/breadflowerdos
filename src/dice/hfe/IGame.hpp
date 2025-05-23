#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/Vec2.hpp>
#include <dice/hfe/Vec3.hpp>

#include <string>

namespace dice::hfe
{
	const uint32_t IID_IGame = 0x1D4C0;

	class GameEvent;
	class EventNode;
	class HTTPRequest;
	class DemoRecorder;
	class MapInfo;

	enum class ConnectionType;
	enum class TargetChannel;
	enum class ChannelMessageType;
	enum class HudNodeTypes;

	namespace io
	{
		enum class ConnectionStatus;
		enum class PResult;
		class PlayerInput;
	}	 // namespace io

	namespace world
	{
		enum class VehicleType;
		enum class MissileLockMessage;
		class IPlayer;
		class IObjectTemplate;
		class IObject;
	}	 // namespace world

	class IGame : public IBase
	{
	public:
		virtual ~IGame() { };
		virtual bool init() = 0;
		virtual void shutdown() = 0;
		virtual bool load() = 0;
		virtual bool loadPath(const std::string&) = 0;
		virtual void unload() = 0;
		virtual void getStatsMonitor() = 0;
		virtual void update(int, float) = 0;
		virtual void say(const std::string&) = 0;
		virtual TargetChannel getCurrentChannel() = 0;
		virtual void setCurrentChannel(TargetChannel) = 0;
		virtual int32_t getCurrentFlags() = 0;
		virtual void setCurrentFlags(int32_t) = 0;
		virtual ChannelMessageType getCurrentType() = 0;
		virtual void setCurrentType(ChannelMessageType) = 0;
		virtual MapInfo* getMapInfo(MapInfo*) = 0;
		virtual void radioMessage(
			TargetChannel, const std::string&, world::IPlayer*, unsigned int,
			bool, bool) = 0;
		virtual void radioMessageFromPlayer(
			TargetChannel, const std::string&, unsigned int, unsigned int, bool,
			bool) = 0;
		virtual bool localRadioMessage(TargetChannel, const std::string&) = 0;
		virtual void gameInfoMessage(
			TargetChannel, const std::string&, unsigned int, unsigned int,
			bool) = 0;
		virtual bool
		localGameInfoMessage(TargetChannel, const std::string&) = 0;
		virtual void addPlayerInput(const io::PlayerInput&) = 0;
		virtual int32_t getCurrentInputIndex() = 0;
		virtual void confirmGhost(int, unsigned int) = 0;
		virtual void confirmReset(int) = 0;
		virtual void createObjectOnAllClients(
			const world::IObjectTemplate*, Vec3, Vec3, bool, int, int) = 0;
		virtual void* getObjectFromNetworkableId(const uint16_t&) = 0;
		virtual void createAndDestroyObject(const world::IObjectTemplate*) = 0;
		virtual void sendGameEventToAllPlaying(GameEvent*) = 0;
		virtual void sendGameEventIfPlaying(unsigned int, GameEvent*) = 0;
		virtual void sendGameEventToAll(GameEvent*) = 0;
		virtual void sendGameEvent(unsigned int, GameEvent*) = 0;
		virtual void sendGameEventToAllConnected(GameEvent*) = 0;
		virtual void sendGameEventIfConnected(unsigned int, GameEvent*) = 0;
		virtual void sendMissileMessageToOccupyingPlayers(
			world::IObject*, world::MissileLockMessage) = 0;
		virtual bool destroyObject(world::IObject*) = 0;
		virtual void enterVehicle(world::IPlayer*, world::IObject*, bool) = 0;
		virtual void exitVehicle(world::IPlayer*, bool, bool) = 0;
		virtual void listPlayers() = 0;
		virtual void joinSquad(int32_t) = 0;
		virtual void leaveSquad(int32_t) = 0;
		virtual const std::string& listSquadMembers(int32_t, int32_t) = 0;
		virtual const std::string& listSquads(int32_t) = 0;
		virtual void changeSquadName(const std::string&, bool) = 0;
		virtual void makeMeCommander() = 0;
		virtual void popNextCommanderApplicant(int32_t) = 0;
		virtual const std::string& getSpottedMessage(uint16_t) = 0;
		virtual void sendSpottedMessage(
			world::IPlayer*, uint16_t, Vec2, world::VehicleType) = 0;
		virtual void callForSpecialist(world::IPlayer*, HudNodeTypes) = 0;
		virtual void recordDemo(DemoRecorder*) = 0;
		virtual void stopRecording() = 0;
		virtual void isPlayingDemo() = 0;
		virtual void setSimulationRate(int) = 0;
		virtual void getSimulationRate() = 0;
		virtual void debugShowActiveGhosts(int) = 0;
		virtual const std::string& getCurrentMapName() const = 0;
		virtual const std::string& getCurrentMapGameMode() const = 0;
		virtual const std::string& getCurrentMapLevelPath() const = 0;
		virtual int32_t getCurrentMapMaxPlayers() const = 0;
		virtual uint32_t getCurrentMapSize() const = 0;
		virtual void setCurrentMapSize(uint32_t) = 0;
		virtual void getNetworkStats() = 0;
		virtual void sendUDPPacket(const char*, unsigned short, void*, int) = 0;
		virtual void addTextToChatWindow(const char*) = 0;
		virtual void failedExitVehicle(int32_t) = 0;
		virtual void isPunkBusterEnabled() = 0;
		virtual bool getAbortLoadLevel() const = 0;
		virtual void destroyPlayer(world::IPlayer*) = 0;
	};
}	 // namespace dice::hfe
