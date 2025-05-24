#pragma once
#include <dice/hfe/world/IPlayer.hpp>

namespace dice::hfe
{
	class IStreamManager;

	class IClientConnection
	{
	public:
		virtual ~IClientConnection();
		virtual void addStreamManager(IStreamManager*);
		virtual void getStreamManager(int);
		virtual void getDataBlockManager(void);
		virtual void getStringManager(void);
		virtual world::IPlayer* getPlayer(void);
		virtual void setPlayer(world::IPlayer*);
		virtual void getIsRecordingConnection(void);
		virtual void debugGetNumActiveGhosts(void);
		virtual void debugShowActiveGhosts(void);
		virtual void setContentValid(bool);
		virtual void getContentValid(void);
	};
}	 // namespace dice::hfe
