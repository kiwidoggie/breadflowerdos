#pragma once

#include <dice/hfe/world/IPlayerManager.hpp>
#include <map>

namespace dice::hfe::world
{
	const uint32_t CID_PlayerManager = 0x0C374;

	class PlayerManager : public IPlayerManager
	{
	public:
		uint32_t m_refCount;
		IPlayer* m_activePlayer;
		std::list<IPlayer*> m_players;
		std::list<IPlayer*> m_tempPlayers;
		char m_unknown38[0x28];	   // dice::hfe::StringHash at 0x48 (size 0x18)
								   // // bf2: 00680298
		std::map<uint32_t, std::string> m_playerClasses;
		std::map<int32_t, IPlayer*> m_idToPlayerMap;
		std::map<int32_t, IPlayer*> m_deactivatedPlayers;
		IPlayer* m_localPlayer;
		char m_unknownF8[8];

	public:
		static IBase* create(uint32_t, IBase*);
		PlayerManager();

		virtual void addRef() override;
		virtual uint32_t getRef() override;
		virtual uint32_t release() override;
		virtual IBase* queryInterface(uint32_t p_param) override;
		virtual void addPlayer(IPlayer*) override;
		virtual void removePlayer(IPlayer*) override;
		virtual void removePlayerId(int32_t) override;
		virtual IPlayer* getPlayerFromName(const std::string&) override;
		virtual IPlayer* getPlayerFromId(int32_t) override;
		virtual IPlayer* getNextPlayerFromId(int32_t) override;
		virtual IPlayer* getPlayerFromProfileId(int32_t) override;
		virtual IPlayer* getPlayerFromIdString(const std::string&) override;
		virtual IPlayer* getLocalHumanPlayer() override;
		virtual IPlayer* setLocalHumanPlayer(IPlayer*) override;
		virtual IPlayer* setLocalHumanPlayer(int32_t) override;
		virtual std::list<IPlayer*>& getPlayers() override;
		virtual std::list<IPlayer*>& getPlayersSortedByScore() override;
		virtual std::list<IPlayer*>& getPlayersSortedByRank() override;
		virtual std::list<IPlayer*>& getPlayers(int32_t) override;
		virtual std::list<IPlayer*>& getPlayersSortedByScore(int32_t) override;
		virtual std::list<IPlayer*>& getPlayersSortedByRank(int32_t) override;
		virtual std::list<IPlayer*>& getPlayersInSquad(int32_t, int32_t) override;
		virtual std::list<IPlayer*>& getPlayersInSquadSortedByScore(int32_t, int32_t) override;
		virtual std::list<IPlayer*>& getPlayersInSquadSortedByRank(int32_t, int32_t) override;
		virtual std::list<IPlayer*>& getTeamSquadLeaders(int32_t) override;
		virtual void updatePlayers(float) override;
		virtual void registerPlayerClass(uint32_t, const std::string&) override;
		virtual void getPlayerClasses(std::list<std::pair<uint32_t, std::string>>&) const override;
		virtual const std::string&getClassNameFromPlayerClassID(uint32_t) const override;
		virtual IPlayer* createPlayer(uint32_t, const std::string&, int32_t) override;
		virtual IPlayer* createPlayer(const std::string&, const std::string&, int32_t) override;
		virtual bool saveAllPlayers(const std::string&) override;
		virtual IPlayer* getActivePlayer() const override;
		virtual void setActivePlayer(IPlayer*) override;
		virtual uint32_t getNumberOfPlayers() const override;
		virtual uint32_t getNumberOfHumanPlayers() const override;
		virtual uint32_t getNumberOfAliveHumanPlayers() const override;
		virtual uint32_t getNrOfPlayerInTeam(int32_t) override;
		virtual uint32_t getNrOfPlayerInSquads(int32_t) override;
		virtual uint32_t getNrOfPlayersInSquad(int32_t, int32_t) override;
		virtual std::list<IPlayer*>& getInvitedPlayers(int32_t, int32_t) override;
		virtual uint32_t getNrOfActiveSquads(int32_t) override;
		virtual int32_t getTeamToAddPlayer(float, float) override;
		virtual bool deactivatePlayer(int32_t) override;
		virtual bool reactivatePlayer(int32_t) override;
		virtual bool renamePlayer(IPlayer*, std::string) override;
		virtual ~PlayerManager() = default;
	};
#if defined(WIN32)
	// TODO: Win32 static_assert
#else
	static_assert(sizeof(PlayerManager) == 0x100);	  // bf2: 008add03
	static_assert(
		offsetof(PlayerManager, m_activePlayer) == 0x10);	 // bf2: 00682580
	static_assert(
		offsetof(PlayerManager, m_players) == 0x18);	// bf2: 00680239
	static_assert(
		offsetof(PlayerManager, m_playerClasses) == 0x60);	  // bf2: 006818c7
	static_assert(
		offsetof(PlayerManager, m_idToPlayerMap) == 0x90);	  // bf2: 00680264
	static_assert(
		offsetof(PlayerManager, m_deactivatedPlayers) ==
		0xC0);	  // bf2: 006800be
#endif
}	 // namespace dice::hfe::world
