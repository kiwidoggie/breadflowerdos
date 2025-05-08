#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/world/IPlayer.hpp>
#include <dice/hfe/world/IObject.hpp>
#include <dice/hfe/world/IObjectTemplate.hpp>
#include <dice/hfe/io/NetworkableDescriptor.hpp>

namespace dice
{
    namespace hfe
    {
        const uint32_t IID_IGameServer = 0x1D4C1;

        class GameEvent;
        class EventNode;
        class HTTPRequest;
        typedef int TargetChannel;
        typedef int ChannelMessageType;
        enum class ConnectionType;

        namespace io
        {
            enum class ConnectionStatus;
            enum class PResult;
        }

        class IGameServer : public IBase {
        public:
            virtual void addScopableGhost(io::NetworkableDescriptor*);
            virtual void removeGhost(io::NetworkableDescriptor*);
            virtual void addStaticGhost(io::NetworkableDescriptor*);
            virtual void startServer(std::string const&, int, int);
            virtual void createPlayer(std::string const&, bool);
            virtual void createAndSpawnAIPlayer(std::string const&, int, int);
            virtual void destroyPlayer(world::IPlayer*);
            virtual void challengeResponse(int,GameEvent*);
            virtual void setConnectionType(int, ConnectionType);
            virtual void chokeBandwidth();
            virtual void changePlayerName(int, std::string const&);
            virtual void getConnection(int);
            virtual void getConnectionState(int);
            virtual void getConnectionStatus(int, io::ConnectionStatus&);
            virtual void toggleFreeCamera(world::IPlayer*);
            virtual void resetConnections();
            virtual void debugShowActiveGhosts(int);
            virtual void debugShowStreamManagerSizes();
            virtual void debugShowGhostPriorities(int);
            virtual void getTotalActiveGhosts();
            virtual void getPlayerConnectionIp(world::IPlayer*, std::string&);
            virtual void getPlayerConnectionIpAndPort(world::IPlayer*, std::string&);
            virtual void updatePlayersVoipStatusOnAllClients(int, bool);
            virtual void kickPlayer(int, io::PResult, std::string const&);
            virtual void consoleKickPlayer(std::string const&);
            virtual void getStatsManager();
            virtual void getNumberOfConnectedClients();
            virtual void getNumberOfConnectingClients();
            virtual void getNumDroppedFrames();
            virtual void getNumOvershotFrames();
            virtual void getInitComplete();
            virtual void getIsInternetServer();
            virtual void sendUDPPacket(char const*, unsigned short, void*, int);
            virtual void say(std::string const&);
            virtual void sayAll(std::string const&);
            virtual void sayTeam(int, std::string const&);
            virtual void say(std::string const&, TargetChannel, ChannelMessageType, unsigned int, unsigned int);
            virtual void enqueueRadioMessage(EventNode*);
            virtual void addPersistenceConnection(HTTPRequest*);
            virtual void removePersistenceConnection(HTTPRequest*);
            virtual void setCurrentPersistenceObject(IBase*);
            virtual void getCurrentPersistenceObject();
            virtual void getAutoRecorder();
            virtual void getNetServer();
            virtual void onContentCheckEvent(int, unsigned char const*, unsigned char const*, unsigned char const*);
            virtual void useContentChecking();
            virtual void isClientReady(int);
            virtual void getPlayerUnlockInfo();
            virtual void isPythonValid();
            virtual void setPythonValid(int, bool);
            virtual void getServerAddress();
            virtual void getName();
        };
    }
}