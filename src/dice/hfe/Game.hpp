#pragma once

#include <dice/hfe/IGame.hpp>

namespace dice
{
    namespace hfe
    {
        class MapInfo {
        public:
            std::string m_gamemode;
            std::string m_levelPath;
            std::string m_mapName;
            int32_t m_maxPlayers;
            bool m_commanderEnabled;
            int m_challengeOrdinal;
            bool _0x24;
            bool _0x25;
            bool m_netBufferNeedsUpdate; // 0x26
            void* m_netBuffer; // 0x28

        public:
            std::string const& getGameMode() const { return m_gamemode; }
            std::string const& getLevelPath() const { return m_levelPath; }
            std::string const& getMapName() const { return m_mapName; }
            int32_t getMaxNumberOfPlayers() const { return m_maxPlayers; }
        };

        const uint32_t CID_Game = 0x1D8A9;

        class Game : public IGame {
        public:
            MapInfo m_currentMap;
            char _0x38[0x10];
            uint32_t m_currentMapSize;
            char _0x4C[0x1C];
            TargetChannel m_currentChannel;
            ChannelMessageType m_channelMessageType;
            int32_t m_currentFlags;
            bool m_abortLoadLevel;
            char _0x75[0xB];

        public:
            virtual ~Game() override {}
            virtual bool load() override { return false; }
            virtual bool loadPath(std::string const&) override { return false; }
            virtual int32_t getCurrentFlags() override { return m_currentFlags; }
            virtual void setCurrentFlags(int32_t flags) override { m_currentFlags = flags; }
            virtual ChannelMessageType getCurrentType() override { return m_channelMessageType; }
            virtual void setCurrentType(ChannelMessageType msgType) override { m_channelMessageType = msgType; }
            virtual MapInfo* getMapInfo(MapInfo*) override;
            virtual bool localRadioMessage(TargetChannel, std::string const&) override;
            virtual bool localGameInfoMessage(TargetChannel, std::string const&) override;
            virtual void addPlayerInput(io::PlayerInput const&) override;
            virtual int32_t getCurrentInputIndex() override { return 0; }
            virtual void* getObjectFromNetworkableId(uint16_t const&) override;
            virtual void createAndDestroyObject(world::IObjectTemplate const*) override;
            virtual bool destroyObject(world::IObject*) override;
            virtual void joinSquad(int32_t) override;
            virtual void leaveSquad(int32_t) override;
            virtual std::string const& listSquadMembers(int32_t, int32_t) override;
            virtual std::string const& listSquads(int32_t) override;
            virtual void changeSquadName(std::string const&, bool) override;
            virtual void makeMeCommander() override;
            virtual void popNextCommanderApplicant(int32_t) override;
            virtual std::string const& getSpottedMessage(uint16_t) override;
            virtual void sendSpottedMessage(world::IPlayer*, uint16_t, Vec2, world::VehicleType) override;
            virtual void callForSpecialist(world::IPlayer*, HudNodeTypes) override;
            virtual std::string const& getCurrentMapName() const override;
            virtual std::string const& getCurrentMapGameMode() const override;
            virtual std::string const& getCurrentMapLevelPath() const override;
            virtual int32_t getCurrentMapMaxPlayers() const override;
            virtual uint32_t getCurrentMapSize() const override;
            virtual void setCurrentMapSize(uint32_t) override;
            virtual void failedExitVehicle(int32_t) override {}
            virtual bool getAbortLoadLevel() const override { return m_abortLoadLevel; }
        };

        extern Game* g_game;

#if defined(WIN32)
        // TODO: Win32 static_assert
#else
        static_assert(sizeof(Game) == 0x80);
        static_assert(offsetof(Game, m_currentMapSize) == 0x48);
        static_assert(sizeof(MapInfo) == 0x30);
#endif
    }
}
