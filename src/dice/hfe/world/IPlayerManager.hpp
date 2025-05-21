#pragma once

#include <dice/hfe/IBase.hpp>
#include <string>
#include <list>

namespace dice
{
    namespace hfe
    {
        namespace world
        {
            class IPlayer;

            const uint32_t IID_IPlayerManager = 0x0C373;

            class IPlayerManager : public IBase {
            public:
                virtual void addPlayer(IPlayer*) = 0;
                virtual void removePlayer(IPlayer*) = 0;
                virtual void removePlayerId(int32_t) = 0;
                virtual IPlayer* getPlayerFromName(std::string const&) = 0;
                virtual IPlayer* getPlayerFromId(int32_t) = 0;
                virtual IPlayer* getNextPlayerFromId(int32_t) = 0;
                virtual IPlayer* getPlayerFromProfileId(int32_t) = 0;
                virtual IPlayer* getPlayerFromIdString(std::string const&) = 0;
                virtual IPlayer* getLocalHumanPlayer() = 0;
                virtual IPlayer* setLocalHumanPlayer(IPlayer*) = 0;
                virtual IPlayer* setLocalHumanPlayer(int32_t) = 0;
                virtual std::list<IPlayer*>& getPlayers() = 0;
                virtual std::list<IPlayer*>& getPlayersSortedByScore() = 0;
                virtual std::list<IPlayer*>& getPlayersSortedByRank() = 0;
                virtual std::list<IPlayer*>& getPlayers(int32_t) = 0;
                virtual std::list<IPlayer*>& getPlayersSortedByScore(int32_t) = 0;
                virtual std::list<IPlayer*>& getPlayersSortedByRank(int32_t) = 0;
                virtual std::list<IPlayer*>& getPlayersInSquad(int32_t, int32_t) = 0;
                virtual std::list<IPlayer*>& getPlayersInSquadSortedByScore(int32_t, int32_t) = 0;
                virtual std::list<IPlayer*>& getPlayersInSquadSortedByRank(int32_t, int32_t) = 0;
                virtual std::list<IPlayer*>& getTeamSquadLeaders(int32_t) = 0;
                virtual void updatePlayers(float) = 0;
                virtual void registerPlayerClass(uint32_t, std::string const&) = 0;
                virtual void getPlayerClasses(std::list<std::pair<uint32_t, std::string>>&) const = 0;
                virtual std::string const& getClassNameFromPlayerClassID(uint32_t) const = 0;
                virtual IPlayer* createPlayer(uint32_t, std::string const&, int32_t) = 0;
                virtual IPlayer* createPlayer(std::string const&, std::string const&, int32_t) = 0;
                virtual bool saveAllPlayers(std::string const&) = 0;
                virtual IPlayer* getActivePlayer() const = 0;
                virtual void setActivePlayer(IPlayer*) = 0;
                virtual uint32_t getNumberOfPlayers() const = 0;
                virtual uint32_t getNumberOfHumanPlayers() const = 0;
                virtual uint32_t getNumberOfAliveHumanPlayers() const = 0;
                virtual uint32_t getNrOfPlayerInTeam(int32_t) = 0;
                virtual uint32_t getNrOfPlayerInSquads(int32_t) = 0;
                virtual uint32_t getNrOfPlayersInSquad(int32_t, int32_t) = 0;
                virtual std::list<IPlayer*>& getInvitedPlayers(int32_t, int32_t) = 0;
                virtual uint32_t getNrOfActiveSquads(int32_t) = 0;
                virtual int32_t getTeamToAddPlayer(float, float) = 0;
                virtual bool deactivatePlayer(int32_t) = 0;
                virtual bool reactivatePlayer(int32_t) = 0;
                virtual bool renamePlayer(IPlayer*, std::string) = 0;
            };
        }
    }
}
