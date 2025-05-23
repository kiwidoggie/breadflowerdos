#pragma once

#include "IBase.hpp"
#include "Vec3.hpp"
#include "WeakPtr.hpp"

#include <list>
#include <map>
#include <string>
#include <vector>

namespace dice::hfe
{
	namespace io
	{
		class PlayerInput;
	}

	namespace world
	{
		enum class MaterialCollisionType;
		enum class TargetType : class CollisionFaceInfo;
		class IArmorGLComp;
		class IObject;
		class IObjectTemplate;
		class IPlayer;
		class IProjectileObject;
		class StrategicObjectHolder;
		class TargetObject;
	}	 // namespace world
	enum class BeginRoundState;
	enum class SpecialGameEventType;
	class TicketHistory;
	struct Vec4;

	const uint32_t IID_IGameLogic = 0x1D4C5;

	class IGameLogic : public IBase
	{
	public:
		virtual bool init() = 0;
		virtual bool load(const std::string&) = 0;
		virtual bool unload() = 0;
		virtual bool close() = 0;
		virtual void update(float) = 0;
		virtual void reset() = 0;
		virtual void restartDemoPlayback() = 0;
		virtual void runNextLevel() = 0;
		virtual void setNextLevel(int32_t) = 0;
		virtual void addPreStoredTemplate(uint32_t, uint32_t, uint32_t) = 0;
		virtual void createPreStoredObjects() = 0;
		virtual uint32_t getStartPreStoredNetID() const = 0;
		virtual uint32_t getEndPreStoredNetID() const = 0;
		virtual void setTeamName(int32_t, const std::string&) = 0;
		virtual const std::string& getTeamName(int32_t) = 0;
		virtual int32_t getTeamFromName(const std::string&) = 0;
		virtual const std::string& getTeamDropVehicle(int32_t) const = 0;
		virtual void setNumDropVehiclesForTeam(int32_t, int32_t) = 0;
		virtual int32_t getNumDropVehiclesForTeam(int32_t) = 0;
		virtual void setDropVehicleDeviationRadius(int32_t, int32_t) = 0;
		virtual int32_t getDropVehicleDeviationRadius() = 0;
		virtual int32_t getDropVehicleDeviationMinRadius() = 0;
		virtual bool killPlayer(world::IPlayer*, bool, bool) = 0;
		virtual bool reSpawnPlayer(world::IPlayer*) = 0;
		virtual bool selectSpawnGroup(world::IPlayer*, int32_t) = 0;
		virtual bool selectTeam(world::IPlayer*, int32_t) = 0;
		virtual bool
		selectKitAndUnlockLevel(world::IPlayer*, int32_t, int32_t) = 0;
		virtual bool isLevelLoadedXP() = 0;
		virtual bool getNoVehiclesMode() = 0;
		virtual void setNoVehiclesMode(bool) = 0;
		virtual void setTicketState(uint32_t, int32_t) = 0;
		virtual int32_t getTicketState(uint32_t) = 0;
		virtual void setDefaultNumberOfTickets(uint32_t, uint32_t) = 0;
		virtual uint32_t getDefaultNumberOfTickets(uint32_t) = 0;
		virtual void
		setDefaultNumberOfTicketsEx(uint32_t, uint32_t, uint32_t) = 0;
		virtual uint32_t getDefaultNumberOfTicketsEx(uint32_t, uint32_t) = 0;
		virtual void setDefaultTimeToNextAIWave(float) = 0;
		virtual float getDefaultTimeToNextAIWave() = 0;
		virtual void setTicketLossAtEndPerMin(float) = 0;
		virtual float getTicketLossAtEndPerMin() = 0;
		virtual void setTicketLossPerMin(uint32_t, float) = 0;
		virtual float getTicketLossPerMin(uint32_t) = 0;
		virtual void setMaximumLevelViewDistance(float) = 0;
		virtual float getMaximumLevelViewDistance() const = 0;
		virtual void setExtraUAVVehicleFlightHeight(float) = 0;
		virtual float getExtraUAVVehicleFlightHeight() const = 0;
		virtual void setFogStartEndAndBase(const Vec4&) = 0;
		virtual const Vec4& getFogStartEndAndBase() const = 0;
		virtual void setDefaultLevel(const std::string&) = 0;
		virtual const std::string& getDefaultLevel() const = 0;
		virtual void refreshTriggerables() = 0;
		virtual bool playEffect(Vec3, const world::IObjectTemplate*, Vec3) = 0;
		virtual bool giveDamage(
			world::IObject*, float, world::IPlayer*,
			std::list<WeakPtr<world::IPlayer>>*, world::IObject*, int32_t,
			world::IObject*, world::IObject*, Vec3, Vec3, int32_t, bool, bool,
			bool) = 0;
		virtual void handleExplosion(
			Vec3, float, int32_t, float, world::IPlayer*, world::IArmorGLComp*,
			int32_t, world::IObject*, world::IObject*, float, world::IObject*,
			world::IObject*, float, bool, bool) = 0;
		virtual void handlePickup(
			world::IObject*, world::IPlayer*, world::IObject*, bool) = 0;
		virtual void
		handleDrop(world::IObject*, world::IPlayer*, world::IObject*, bool) = 0;
		virtual bool handleCollisionForProjectile(
			world::IObject*, world::IObject*, const Vec3&, const Vec3&,
			const Vec3&, int32_t, int32_t, world::CollisionFaceInfo*,
			world::CollisionFaceInfo*) = 0;
		virtual bool handleCollisionForReplenisher(
			bool, world::IObject*, world::IObject*, const Vec3&, const Vec3&,
			const Vec3&, int32_t, int32_t) = 0;
		virtual bool handleCollisionForResurrecter(
			world::IObject*, world::IObject*, float, float, const Vec3&,
			const Vec3&, const Vec3&, int32_t, int32_t) = 0;
		virtual void handleCollision(
			world::IObject*, world::IObject*, const Vec3&, const Vec3&,
			const Vec3&, int32_t, int32_t, world::CollisionFaceInfo*,
			world::CollisionFaceInfo*) = 0;
		virtual bool heal(
			world::IObject*, float, world::IPlayer*, int32_t, int32_t, float*,
			bool, bool) = 0;
		virtual bool replenishAmmo(
			world::IObject*, float, world::IPlayer*, int32_t, int32_t, float*,
			bool) = 0;
		virtual void doImpact(
			int32_t, int32_t, world::MaterialCollisionType, const Vec3&,
			const Vec3&, const Vec3&, world::IObject*, world::IObject*,
			world::IProjectileObject*, world::CollisionFaceInfo*, Vec3,
			bool) = 0;
		virtual bool playCollisionEffect(
			Vec3, const world::IObjectTemplate*, Vec3, Vec3) = 0;
		virtual void*
		spawnMultipleObjects(const world::IObjectTemplate*, int32_t) = 0;
		virtual bool spawnObject(const std::string&, Vec3, Vec3, int32_t) = 0;
		virtual void
		spawnObject(const world::IObjectTemplate*, Vec3, Vec3, int32_t) = 0;
		virtual void triggerSpecialGameEvent(SpecialGameEventType, void*) = 0;
		virtual bool
		remoteCommand(int32_t, int32_t, int32_t, int32_t, int32_t) = 0;
		virtual void setUseActiveCombatArea(bool) = 0;
		virtual bool getUseActiveCombatArea() = 0;
		virtual void setActiveCombatArea(float, float, float, float) = 0;
		virtual void getActiveCombatArea(float*, float*, float*, float*) = 0;
		virtual float getTimeUntilRestartMap() = 0;
		virtual bool isServer() const = 0;
		virtual void
		setKit(int32_t, int32_t, const std::string&, const std::string&) = 0;
		virtual world::IObjectTemplate* getKitTemplate(int32_t, int32_t) = 0;
		virtual const std::string& getKitTemplateString(int32_t, int32_t) = 0;
		virtual const std::string& getSoldierSkin(int32_t, int32_t) = 0;
		virtual std::map<int32_t, std::string>* getKits() const = 0;
		virtual void checkPlayerTriggers(
			world::IPlayer*, world::IObject*, io::PlayerInput&, bool) = 0;
		virtual int32_t getGameStatus() = 0;
		virtual BeginRoundState getBeginRoundState() = 0;
		virtual void setBeginRoundState(BeginRoundState) = 0;
		virtual uint32_t getNextStateChangeAtTick() = 0;
		virtual void setNextStateChangeAtTick(uint32_t) = 0;
		virtual float getTimeToNextStateChange() = 0;
		virtual void addControlPoint(world::IObject*, int32_t) = 0;
		virtual std::map<uint32_t, world::IObject*>&
		getControlPointMap() const = 0;
		virtual world::IObject* getControlPoint(uint32_t) = 0;
		virtual void removeControlPoint(world::IObject*) = 0;
		virtual bool
		getControlPointsInGroup(std::vector<world::IObject*>&, int32_t) = 0;
		virtual uint32_t getNumberOfControlPointGroups() = 0;
		virtual void addFlag(world::IObject*) = 0;
		virtual std::map<uint32_t, world::IObject*>& getFlagMap() const = 0;
		virtual void removeFlag(world::IObject*) = 0;
		virtual void addPco(world::IObject*) = 0;
		virtual std::map<uint32_t, world::IObject*>& getPcoMap() const = 0;
		virtual void removePco(world::IObject*) = 0;
		virtual void addStrategicObject(world::IObject*) = 0;
		virtual std::map<std::string, world::StrategicObjectHolder*>&
		getStrategicObjectMap() const = 0;
		virtual void removeStrategicObject(world::IObject*) = 0;
		virtual void addTargetObject(world::IObject*) = 0;
		virtual std::map<uint32_t, world::IObject*>&
		getTargetObjectMap() const = 0;
		virtual void removeTargetObject(world::IObject*) = 0;
		virtual world::IObject* getTargetObject(uint32_t) const = 0;
		virtual world::TargetObject* findBestTargetObject(
			const Vec3&, const Vec3&, world::TargetType, float, float,
			world::IObject*, world::IObject*, float, const world::IObject*,
			bool, bool, bool) = 0;
		virtual void addRemoteControlledObject(world::IObject*) = 0;
		virtual std::map<uint32_t, world::IObject*>&
		getRemoteControlledObjectMap() const = 0;
		virtual void removeRemoteControlledObject(world::IObject*) = 0;
		virtual world::IObject* getRemoteControlledObject(uint32_t) const = 0;
		virtual void addProjectile(world::IObject*) = 0;
		virtual std::map<uint32_t, world::IObject*>&
		getProjectileMap() const = 0;
		virtual void removeProjectile(world::IObject*) = 0;
		virtual void addObjectSpawner(world::IObject*) = 0;
		virtual std::map<uint32_t, world::IObject*>&
		getObjectSpawnerMap() const = 0;
		virtual void removeObjectSpawner(world::IObject*) = 0;
		virtual world::IObject* getObjectSpawner(uint32_t) const = 0;
		virtual void addSupplyDepot(world::IObject*) = 0;
		virtual std::map<uint32_t, world::IObject*>&
		getSupplyDepotMap() const = 0;
		virtual void removeSupplyDepot(world::IObject*) = 0;
		virtual void setTeamLanguage(int32_t, const std::string&) = 0;
		virtual const std::string& getTeamLanguage(int32_t) const = 0;
		virtual void setTeamFlag(int32_t, const std::string&) = 0;
		virtual const std::string& getTeamFlag(int32_t) const = 0;
		virtual void toggleLocalFreeCamera() = 0;
		virtual Vec3& getBeforeSpawnCameraPosition() const = 0;
		virtual Vec3& getBeforeSpawnCameraDirection() const = 0;
		virtual void resetPlayerFreeCameraPosition(world::IPlayer*) = 0;

		virtual void togglePause() { }

		virtual bool isLevelLoaded() const
		{
			return false;
		}

		virtual void setPause(bool) { }

		virtual bool getPause() const
		{
			return false;
		}

		virtual bool isPrecaching() const = 0;
		virtual bool getEnableVoHelp() = 0;
		virtual void stopPlayingVoMessages() = 0;
		virtual void setSupplyDropHeight(float) = 0;
		virtual float getSupplyDropHeight() = 0;
		virtual void setVehicleDropHeight(float) = 0;
		virtual float getVehicleDropHeight() = 0;
		virtual void setSupplyDropNumSecsToLive(float) = 0;
		virtual float getSupplyDropNumSecsToLive() = 0;
		virtual void setFeslEnvironment(int32_t) = 0;
		virtual int32_t getFeslEnvironment() = 0;
		virtual void
		storeVoipServerInfo(bool, uint32_t, uint16_t, uint16_t, int32_t) = 0;
		virtual void
		getVoipServerInfo(bool&, uint32_t&, uint16_t&, uint16_t&, int32_t&) = 0;
		virtual bool startupVoipClient() = 0;
		virtual bool isVoipClientRunning() = 0;

		virtual bool getOutputPlayerStats()
		{
			return false;
		}

		virtual bool getAirMouseInverted() = 0;
		virtual void setAirMouseSensitivity(float) = 0;
		virtual float getAirMouseSensitivity() = 0;
		virtual bool becomeSquadLeader(bool) = 0;
		virtual const TicketHistory& getTicketHistory() = 0;
		virtual void setTicketHistory(const TicketHistory&) = 0;
		virtual void setHitIndicationThreshold(float) = 0;
		virtual float getHitIndicationThreshold() = 0;
		virtual float getUAVActiveTime() const = 0;
		virtual float getSatelliteScanActiveTime() const = 0;
		virtual float getUAVReloadTime() const = 0;
		virtual float getUAVRadius() const = 0;
		virtual float getSatelliteScanReloadTime() const = 0;
		virtual float getSatelliteScanVisibleTime() const = 0;
		virtual void* getGroundDecalObject() = 0;
		virtual void noVehiclesOmit(std::string) = 0;
		virtual bool isOmitted(std::string) = 0;
		virtual void AddInvalidDropVehicleObject(std::string, bool) = 0;
		virtual std::list<world::IObject*>&
		GetInvalidVehicleDropObjectList() = 0;
		virtual void setDebugMissiles(int32_t) = 0;
		virtual int32_t getDebugMissiles() = 0;
		virtual void setDebugReplenish(int32_t) = 0;
		virtual int32_t getDebugReplenish() = 0;
	};
}	 // namespace dice::hfe
