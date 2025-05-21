#pragma once

#include <dice/hfe/WeakPtr.hpp>
#include <dice/hfe/ActionBuffer.hpp>
#include <dice/hfe/IBase.hpp>
#include <dice/hfe/Vec3.hpp>

#include <string>
#include <vector>

namespace dice
{
    namespace hfe
    {
        namespace io
        {
            class BitStream;
        }

        namespace world
        {
            class ICameraObject;
            class IObject;
            class IObjectTemplate;

            const uint32_t IID_IPlayer = 0x0C3E6;

            class IPlayer : public IBase {
            public:
                virtual void getClassID() = 0;
                virtual ~IPlayer() = 0;
                virtual void getWeakPtr() = 0;
                virtual void setName(std::string const&) = 0;
                virtual std::string const& getName() = 0;
                virtual void setFlags() = 0;
                virtual void testFlags() = 0;
                virtual void handleUpdate(float, unsigned int) = 0;
                virtual void handleFrameUpdate(float) = 0;
                virtual void getUpdateFrequencyType() = 0;
                virtual void setUpdateFrequencyType() = 0;
                virtual void handleInput(io::PlayerInput*, float, unsigned int) = 0;
                virtual void getAutoInput(io::PlayerInput*, bool) = 0;
                virtual world::IObject* getVehicle() = 0;
                virtual void setVehicle(world::IObject*, int) = 0;
                virtual void getInputId() = 0;
                virtual int getId() = 0;
                virtual void setIsRemote(bool) = 0;
                virtual bool getIsRemote() = 0;
                virtual void setIsAIPlayer(bool) = 0;
                virtual bool getIsAIPlayer() = 0;
                virtual void setIsAlive(bool) = 0;
                virtual bool getIsAlive() = 0;
                virtual void setSuicide(bool) = 0;
                virtual void getSuicide() = 0;
                virtual bool getIsConnected() = 0;
                virtual void setIsConnected(bool) = 0;
                virtual void getCrossHairFadeValue() = 0;
                virtual void setViewDistance(float) = 0;
                virtual void getViewDistance() = 0;
                virtual void setFov(float fov, float delay) = 0;
                virtual float getFov() = 0;
                virtual void getEndFov() = 0;
                virtual ActionBuffer* getActionBuffer() = 0;
                virtual void getAIPlayerInput() = 0;
                virtual void setDefaultVehicle(world::IObject*) = 0;
                virtual world::IObject* getDefaultVehicle() = 0;
                virtual void getFreeCamera() = 0;
                virtual void setFreeCameraEnabled(bool) = 0;
                virtual void getFreeCameraEnabled() = 0;
                virtual void toggleFreeCameraEnabled() = 0;
                virtual void setOverheadCameraEnabled(bool) = 0;
                virtual void getOverheadCameraEnabled() = 0;
                virtual void setOverheadCameraTopDownView(bool) = 0;
                virtual void getOverheadCameraTopDownView() = 0;
                virtual void setCommanderCamOverhead(bool) = 0;
                virtual void getCommanderCamOverhead() = 0;
                virtual void getTickCount() = 0;
                virtual void addTick() = 0;
                virtual void subTick() = 0;
                virtual void resetTickCounter() = 0;
                virtual void getTimeOutSideWorld() = 0;
                virtual void setTeam(int, bool) = 0;
                virtual int32_t getTeam() = 0;
                virtual void getSpawnAtTick() = 0;
                virtual void setSpawnAtTick(unsigned int) = 0;
                virtual void getTimeToSpawn() = 0;
                virtual void getManDownTimeLeft() = 0;
                virtual void setIsManDown(bool) = 0;
                virtual void getIsManDown() = 0;
                virtual void getManDownAtTick() = 0;
                virtual void setSquadId(unsigned int) = 0;
                virtual uint32_t getSquadId() = 0;
                virtual void setIsCommander(bool) = 0;
                virtual void getIsCommander() = 0;
                virtual void setUAVIsReady(bool) = 0;
                virtual void getUAVIsReady() = 0;
                virtual void setSatelliteIsReady(bool) = 0;
                virtual void getSatelliteIsReady() = 0;
                virtual void setLastTimeCommander(double) = 0;
                virtual void getLastTimeCommander() = 0;
                virtual void setCommanderReapplyWaitTime(double) = 0;
                virtual void getCommanderReapplyWaitTime() = 0;
                virtual void setIsSquadLeader(bool) = 0;
                virtual bool getIsSquadLeader() = 0;
                virtual void getIsGassed() = 0;
                virtual void setIsInsideCP(bool) = 0;
                virtual void getIsInsideCP() = 0;
                virtual void setHasSimulatedFrame(bool) = 0;
                virtual void getHasSimulatedFrame() = 0;
                virtual void setSpawnGroup(int) = 0;
                virtual void getSpawnGroup() = 0;
                virtual void setInterpolationTime(unsigned int) = 0;
                virtual void getInterpolationTime() = 0;
                virtual void setPing(unsigned int) = 0;
                virtual int getPing() = 0;
                virtual void setKit(int) = 0;
                virtual void getKit() = 0;
                virtual void getScoreData() = 0;
                virtual void setFlagHolder(bool) = 0;
                virtual void getFlagHolder() = 0;
                virtual world::ICameraObject* getCamera() = 0;
                virtual void setCamera(world::ICameraObject*) = 0;
                virtual bool hasFirstPersonView() = 0;
                virtual void getTimeConnected() = 0;
                virtual void getNetworkable() = 0;
                virtual void getStateSync(io::BitStream*, world::IObject*) = 0;
                virtual void setStateSync(io::BitStream*, world::IObject*, double) = 0;
                virtual void reset() = 0;
                virtual void setFiringState(bool) = 0;
                virtual void getFiringState() = 0;
                virtual void setAltFiringState(bool) = 0;
                virtual void getAltFiringState() = 0;
                virtual void setFlareFiringState(bool) = 0;
                virtual void getFlareFiringState() = 0;
                virtual void setSprintState(bool) = 0;
                virtual void getSprintState() = 0;
                virtual void setSprintStateLastTick(bool) = 0;
                virtual void getSprintStateLastTick() = 0;
                virtual void setReloadState() = 0;
                virtual void getAndResetReloadState() = 0;
                virtual void updateFiringState(unsigned int, world::IObject*) = 0;
                virtual void updateGhostFiringState() = 0;
                virtual void setHitIndicator(bool) = 0;
                virtual void getHitIndicator() = 0;
                virtual void updateHitFromDirection(const Vec3*) = 0;
                virtual void getHitFromDirection() = 0;
                virtual void updateCameraShake(float) = 0;
                virtual void getCameraShake() = 0;
                virtual void getSquadInviteMask() = 0;
                virtual void setSquadInviteMask(unsigned int) = 0;
                virtual bool getIsInvitedToSquad(int32_t) = 0;
                virtual void setKitTimeStamp(double) = 0;
                virtual void getKitTimeStamp() = 0;
                virtual void setCurrentFiringButton(io::PlayerInputMap) = 0;
                virtual io::PlayerInputMap getCurrentFiringButton() = 0;
                virtual void setPersonalDecalTemplate(world::IObjectTemplate const*) = 0;
                virtual void getPersonalDecalTemplate() = 0;
                virtual void enableVOHelp(bool) = 0;
                virtual void enableVOHelpMessage(int) = 0;
                virtual void disableVOHelpMessage(int) = 0;
                virtual void getVOHelpMessagePlayed(int) = 0;
                virtual void doAddTouchItem(IPlayer*) = 0;
                virtual void setHealRepairedAtTick(unsigned int, bool, bool) = 0;
                virtual void getHealRepairedAtTick() = 0;
                virtual void setGaveAmmoAtTick(unsigned int, bool) = 0;
                virtual void getGaveAmmoAtTick() = 0;
                virtual void setFailedExitAtTick(unsigned int) = 0;
                virtual void getFailedExitAtTick() = 0;
                virtual void getIsGivingAbility() = 0;
                virtual void getIsRepairing() = 0;
                virtual void getIsGivingReplenish() = 0;
                virtual void getChosenUnlockLevel(int, int) = 0;
                virtual void setChosenUnlockLevel(int, int, int) = 0;
                virtual void isUnlocked(int, int, int) = 0;
                virtual void getUnlockLevel(int, int) = 0;
                virtual void setUnlocks() = 0;
                virtual void getUnlocks() = 0;
                virtual void setPeerAddress(std::string const&) = 0;
                virtual void getPeerAddress() = 0;
                virtual void getVoipEnabled() = 0;
                virtual void getVoipSessionId() = 0;
                virtual void setVoipSessionId(unsigned short) = 0;
                virtual void getIsMuted() = 0;
                virtual void getIsTalking() = 0;
                virtual void getLastTalkTime() = 0;
                virtual void getStopTalkingThreshold() = 0;
                virtual void setIsMuted(bool) = 0;
                virtual void setIsTalking(bool) = 0;
                virtual void setVoipEnabled(bool) = 0;
                virtual void setVotingStatus() = 0;
                virtual void getVotingStatus() = 0;
                virtual void setParticipateInVoting(bool) = 0;
                virtual void getParticipateInVoting() = 0;
                virtual void setTargetOfVote(bool) = 0;
                virtual void getTargetOfVote() = 0;
                virtual void getProfileId() = 0;
                virtual void setProfileId(int) = 0;
                virtual void setBlurryVision(float, float, float) = 0;
                virtual void getBlurValue() = 0;
                virtual void getIsNearGasCloud() = 0;
                virtual void getIsGasMaskOn() = 0;
                virtual void setIsGasMaskOn(bool, bool) = 0;
                virtual void setGasMaskHudItem(bool) = 0;
                virtual void getPlayerGasMaskChangeTimer() = 0;
                virtual void getPlayerNightVisionChangeTimer() = 0;
                virtual void getIsUnderwater() = 0;
                virtual void getNormalizedNightVisionPower() = 0;
                virtual void setNightVision(bool, bool) = 0;
                virtual void rechargeNightVision() = 0;
                virtual void setVisualNightVision(bool) = 0;
                virtual void getNightVision() = 0;
                virtual void disableFlashBangEffect() = 0;
                virtual void disableBlurryVision() = 0;
                virtual io::PlayerInput getPlayerInput() = 0;
                virtual void resetOnDeath() = 0;
                virtual void isPlayerInNightMap() = 0;
                virtual void setTracePlayerId(int) = 0;
                virtual int getTracePlayerId() = 0;
                virtual void allocateFreeCamera() = 0;
                virtual void getIsThisASpam(bool) = 0;
                virtual void setRadioSpamFlagCount(int) = 0;
                virtual int getRadioSpamFlagCount() = 0;
                virtual void setRadioSpamBlockedFlagCount(int) = 0;
                virtual int getRadioSpamBlockedFlagCount() = 0;
                virtual void setRadioSpamFilterFlagTimer(float) = 0;
                virtual float getRadioSpamFilterFlagTimer() = 0;
                virtual void resetSpamFilter() = 0;
                virtual void getCloseMines(std::vector<world::IObject*>&) = 0;
                virtual bool getAutoReload() = 0;
                virtual void setAutoReload(bool) = 0;
                virtual void updateClientSettings() = 0;

                WeakPtr<IPlayer> m_weakPtr;
            };
        }
    }
}
