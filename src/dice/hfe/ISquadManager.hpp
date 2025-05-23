#pragma once

#include "IBase.hpp"
#include <string>

namespace dice::hfe
{
	enum class OrderType;
	enum class SquadOrderType;
	class SquadOrder;

	namespace world
	{
		class IPlayer;
	}

	const uint32_t IID_ISquadManager = 0x0C48A;

	class ISquadManager : public IBase
	{
	public:
		virtual void reset() = 0;
		virtual void reAddDynamicSpawnGroups() = 0;
		virtual bool sendSquadManagerState(int32_t) = 0;
		virtual bool
		setSquadName(int32_t, int32_t, int32_t, const std::string&, bool) = 0;
		virtual bool setIsPrivate(int32_t, int32_t, bool, bool) = 0;
		virtual bool setIsAccepted(
			int32_t, int32_t, bool, OrderType, SquadOrderType, bool) = 0;
		virtual void getSquadInfo(int32_t, int32_t) = 0;
		virtual bool inviteToSquad(int32_t, int32_t, int32_t, bool, bool) = 0;
		virtual bool addToSquad(int32_t, int32_t, int32_t) = 0;
		virtual bool removeFromSquad(int32_t, int32_t, int32_t, bool) = 0;
		virtual bool setSquadLeader(int32_t, int32_t, int32_t, bool) = 0;
		virtual int32_t getSquadLeader(int32_t, int32_t) = 0;
		virtual int32_t getFirstUnusedSquad(int32_t) const = 0;
		virtual void issueSquadOrder(int32_t, int32_t, SquadOrder&, bool) = 0;
		virtual void
		issueCommanderOrder(int32_t, int32_t, SquadOrder&, bool) = 0;
		virtual void issueRequest(int32_t, int32_t, SquadOrder&, bool) = 0;
		virtual void resetSquad(int32_t, int32_t) = 0;
		virtual bool findNewSquadLeader(int32_t, int32_t, int32_t) = 0;
		virtual void applyForCommander(int32_t, int32_t) = 0;
		virtual int32_t popNextCommanderApplicant(int32_t) = 0;
		virtual void acceptCommander(int32_t, int32_t) = 0;
		virtual void declineCommander(int32_t, int32_t) = 0;
		virtual void resignCommander(int32_t) = 0;
		virtual bool setCommander(int32_t, int32_t) = 0;
		virtual int32_t getCommander(int32_t) = 0;
		virtual void* getCommanderCam(int32_t) = 0;
		virtual bool setCommanderToSoldierMode(int32_t) = 0;
		virtual bool setCommanderToOverheadCamMode(int32_t) = 0;
		virtual bool setCommanderOverheadCamZoomMode(int32_t, bool) = 0;
		virtual void removeCommanderApplicant(int32_t, int32_t) = 0;
		virtual void addOrderMarker(int32_t, SquadOrder&) = 0;
		virtual void removeAllOrderMarkers() = 0;
		virtual void removeOrderMarker(int32_t) = 0;
		virtual void updateOrderMarkers(world::IPlayer*) = 0;
	};
}	 // namespace dice::hfe
