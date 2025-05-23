#pragma once
#include <dice/hfe/IBase.hpp>

namespace dice::hfe
{
	const uint32_t IID_IGameServer = 0x1D4C1;

	class GameEvent;
	class EventNode;
	class HTTPRequest;
	enum class TargetChannel;
	enum class ChannelMessageType;
	enum class ConnectionType;

	namespace io
	{
		enum class ConnectionStatus;
		enum class PResult;
		class NetworkableDescriptor;
	}	 // namespace io

	class IGameServer : public IBase
	{
	public:
		virtual void addScopableGhost(io::NetworkableDescriptor*);
		virtual void removeGhost(io::NetworkableDescriptor*);
		virtual void addStaticGhost(io::NetworkableDescriptor*);
		virtual void startServer(const std::string&, int, int);
		virtual void createPlayer(const std::string&, bool);
		virtual void createAndSpawnAIPlayer(const std::string&, int, int);
		virtual void destroyPlayer(world::IPlayer*);
		virtual void challengeResponse(int, GameEvent*);
		virtual void setConnectionType(int, ConnectionType);
		virtual void chokeBandwidth();
		virtual void changePlayerName(int, const std::string&);
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
		virtual void
		getPlayerConnectionIpAndPort(world::IPlayer*, std::string&);
		virtual void updatePlayersVoipStatusOnAllClients(int, bool);
		virtual void kickPlayer(int, io::PResult, const std::string&);
		virtual void consoleKickPlayer(const std::string&);
		virtual void getStatsManager();
		virtual void getNumberOfConnectedClients();
		virtual void getNumberOfConnectingClients();
		virtual void getNumDroppedFrames();
		virtual void getNumOvershotFrames();
		virtual void getInitComplete();
		virtual void getIsInternetServer();
		virtual void sendUDPPacket(const char*, unsigned short, void*, int);
		virtual void say(const std::string&);
		virtual void sayAll(const std::string&);
		virtual void sayTeam(int, const std::string&);
		virtual void
		say(const std::string&, TargetChannel, ChannelMessageType, unsigned int,
			unsigned int);
		virtual void enqueueRadioMessage(EventNode*);
		virtual void addPersistenceConnection(HTTPRequest*);
		virtual void removePersistenceConnection(HTTPRequest*);
		virtual void setCurrentPersistenceObject(IBase*);
		virtual void getCurrentPersistenceObject();
		virtual void getAutoRecorder();
		virtual void getNetServer();
		virtual void onContentCheckEvent(
			int, const unsigned char*, const unsigned char*,
			const unsigned char*);
		virtual void useContentChecking();
		virtual void isClientReady(int);
		virtual void getPlayerUnlockInfo();
		virtual void isPythonValid();
		virtual void setPythonValid(int, bool);
		virtual void getServerAddress();
		virtual void getName();
	};
}	 // namespace dice::hfe
