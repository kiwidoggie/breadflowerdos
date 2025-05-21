#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/Vec2.hpp>
#include <dice/hfe/Vec3.hpp>

#include <string>

namespace dice
{
    namespace hfe
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
        }
        namespace world
        {
            enum class VehicleType;
            enum class MissileLockMessage;
            class IPlayer;
            class IObjectTemplate;
            class IObject;
        }

        class IGame : public IBase {
        public:
            virtual ~IGame() = 0;
            virtual bool init() = 0;
            virtual void shutdown() = 0;
            virtual bool load() = 0;
            virtual bool loadPath(std::string const&) = 0;
            virtual void unload() = 0;
            virtual void getStatsMonitor() = 0;
            virtual void update(int, float) = 0;
            virtual void say(std::string const&) = 0;
            virtual TargetChannel getCurrentChannel() = 0;
            virtual void setCurrentChannel(TargetChannel) = 0;
            virtual int32_t getCurrentFlags() = 0;
            virtual void setCurrentFlags(int32_t) = 0;
            virtual ChannelMessageType getCurrentType() = 0;
            virtual void setCurrentType(ChannelMessageType) = 0;
            virtual MapInfo* getMapInfo(MapInfo*) = 0;
            virtual void radioMessage(TargetChannel, std::string const&, world::IPlayer*, unsigned int, bool, bool) = 0;
            virtual void radioMessageFromPlayer(TargetChannel, std::string const&, unsigned int, unsigned int, bool, bool) = 0;
            virtual bool localRadioMessage(TargetChannel, std::string const&) = 0;
            virtual void gameInfoMessage(TargetChannel, std::string const&, unsigned int, unsigned int, bool) = 0;
            virtual bool localGameInfoMessage(TargetChannel, std::string const&) = 0;
            virtual void addPlayerInput(io::PlayerInput const&) = 0;
            virtual int32_t getCurrentInputIndex() = 0;
            virtual void confirmGhost(int, unsigned int) = 0;
            virtual void confirmReset(int) = 0;
            virtual void createObjectOnAllClients(world::IObjectTemplate const*, Vec3, Vec3, bool, int, int) = 0;
            virtual void getObjectFromNetworkableId(unsigned short const&) = 0;
            virtual void createAndDestroyObject(world::IObjectTemplate const*) = 0;
            virtual void sendGameEventToAllPlaying(GameEvent*) = 0;
            virtual void sendGameEventIfPlaying(unsigned int, GameEvent*) = 0;
            virtual void sendGameEventToAll(GameEvent*) = 0;
            virtual void sendGameEvent(unsigned int, GameEvent*) = 0;
            virtual void sendGameEventToAllConnected(GameEvent*) = 0;
            virtual void sendGameEventIfConnected(unsigned int, GameEvent*) = 0;
            virtual void sendMissileMessageToOccupyingPlayers(world::IObject*, world::MissileLockMessage) = 0;
            virtual bool destroyObject(world::IObject*) = 0;
            virtual void enterVehicle(world::IPlayer*, world::IObject*, bool) = 0;
            virtual void exitVehicle(world::IPlayer*, bool, bool) = 0;
            virtual void listPlayers() = 0;
            virtual void joinSquad(int) = 0;
            virtual void leaveSquad(int) = 0;
            virtual void listSquadMembers(int, int) = 0;
            virtual void listSquads(int) = 0;
            virtual void changeSquadName(std::string const&, bool) = 0;
            virtual void makeMeCommander() = 0;
            virtual void popNextCommanderApplicant(int) = 0;
            virtual void getSpottedMessage(unsigned short) = 0;
            virtual void sendSpottedMessage(world::IPlayer*, unsigned short, Vec2, world::VehicleType) = 0;
            virtual void callForSpecialist(world::IPlayer*, HudNodeTypes) = 0;
            virtual void recordDemo(DemoRecorder*) = 0;
            virtual void stopRecording() = 0;
            virtual void isPlayingDemo() = 0;
            virtual void setSimulationRate(int) = 0;
            virtual void getSimulationRate() = 0;
            virtual void debugShowActiveGhosts(int) = 0;
            virtual void getCurrentMapName() = 0;
            virtual void getCurrentMapGameMode() = 0;
            virtual void getCurrentMapLevelPath() = 0;
            virtual void getCurrentMapMaxPlayers() = 0;
            virtual void getCurrentMapSize() = 0;
            virtual void setCurrentMapSize(unsigned int) = 0;
            virtual void getNetworkStats() = 0;
            virtual void sendUDPPacket(char const*, unsigned short, void*, int) = 0;
            virtual void addTextToChatWindow(char const*) = 0;
            virtual void failedExitVehicle(int) = 0;
            virtual void isPunkBusterEnabled() = 0;
            virtual void getAbortLoadLevel() = 0;
            virtual void destroyPlayer(world::IPlayer*) = 0;
        };
    }
}