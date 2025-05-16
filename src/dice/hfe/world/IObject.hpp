#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/Mat4.hpp>
#include <dice/hfe/Vec3.hpp>
#include <dice/hfe/WeakPtr.hpp>
#include <dice/hfe/geom/IGeometry.hpp>
#include <dice/hfe/io/INetworkable.hpp>

#include <string>

namespace dice::hfe::world
{
	class IPlayer;
	class IPhysicsNode;
	class IResponsePhysics;
	class IObjectComp;
	class IObjectTemplate;
	class IWeaponHudComp;
	class ArmorGLComp;

	const uint32_t IID_IObject = 0x0C378;

	class IObject : public IBase
	{
	public:
		// object flags
		enum : unsigned int
		{
			None = 0U,
			IsDisabled = 1U << 0,			 // 0x1
			IsActive = 1U << 1,				 // 0x2
											 // 0x4
			IsDynamic = 1U << 3,			 // 0x8
											 // 0x10
			IsCached = 1U << 5,				 // 0x20
											 // 0x40
											 // 0x80
			HasResponsePhysics = 1U << 8,	 // 0x100
											 // 0x200
			HasGrid = 1U << 10,				 // 0x400
			HasUpdates = 1U << 11,			 // 0x800
											 // 0x1000
			HasFrameUpdates = 1U << 13,		 // 0x2000
			HasNameHash = 1U << 14,			 // 0x4000
			HasDirtyTransform = 1U << 15,	 // 0x8000
											 // 0x10000
											 // 0x20000
											 // 0x40000
											 // 0x80000
											 // 0x100000
											 // 0x200000
											 // 0x400000
											 // 0x800000
			IsRootParent = 1U << 24,		 // 0x1000000
		};

	public:
		virtual unsigned int getClassID() = 0;
		virtual ~IObject() = 0;
		virtual void getWeakPtr() = 0;
		virtual void init() = 0;
		virtual void disableCachedObject() = 0;
		virtual void enableCachedObject() = 0;
		virtual unsigned int getObjectCacheID() = 0;
		virtual void setObjectCacheID(unsigned int id) = 0;
		virtual void destroy(bool recursive) = 0;
		virtual void forceDestroy() = 0;
		virtual bool isObjectDestroyed() = 0;
		virtual void setObjectInDestroyList(bool) = 0;
		virtual bool getObjectInDestroyList() = 0;
		virtual void setGridCullerObject() = 0;
		virtual void getGridCullerObject() = 0;
		virtual void setLatencyCullerObject() = 0;
		virtual void getLatencyCullerObject() = 0;
		virtual void setComponent() = 0;
		virtual void* queryComponent(int memberID, int interfaceID) = 0;
		virtual void
		updateFlags(unsigned int flagsToSet, unsigned int flagsToReset) = 0;
		virtual std::string* getName() = 0;
		virtual void setName() = 0;
		virtual Vec3* getAbsolutePosition() = 0;
		virtual void setPosition(Vec3* vec) = 0;
		virtual Vec3* getAbsolutePositionSecondary() = 0;
		virtual void setPositionSecondary(Vec3* vec) = 0;
		virtual Vec3* getRotationSecondary() = 0;
		virtual void setRotationSecondary(Vec3* vec) = 0;
		virtual Mat4* getAbsoluteTransformation() = 0;
		virtual Mat4* getInvAbsoluteTransformation() = 0;
		virtual void setAbsoluteTransformation(const Mat4* matrix) = 0;
		virtual void getVisualAbsoluteTransformation() = 0;
		virtual void getVisualBoundingRadius() = 0;
		virtual void getPhysicBoundingRadius() = 0;
		virtual void getBoundingRadiusModifier() = 0;
		virtual void getFullBoundingBox() = 0;
		virtual void getMineBoundingBox() = 0;
		virtual void handleVisualUpdate(float, float) = 0;
		virtual void handleFrameUpdate(float) = 0;
		virtual void handleUpdate(float, unsigned int) = 0;
		virtual void handleCollision() = 0;
		virtual void updateGeometry() = 0;
		virtual void getUpdateFrequency() = 0;
		virtual void getUpdateFrequencyType() = 0;
		virtual void setUpdateFrequencyType() = 0;
		virtual void getGeometryPart() = 0;
		virtual void hasCollisionLod() = 0;
		virtual void getMaterial() = 0;
		virtual void SetActiveLod() = 0;
		virtual io::INetworkable* getNetworkable() = 0;
		virtual void getDecalObject() = 0;
		virtual Vec3* getRelativePosition() = 0;
		virtual void setRelativePosition(const Vec3*) = 0;
		virtual Mat4* getRelativeTransformation() = 0;
		virtual void setRelativeTransformation(const Mat4* matrix) = 0;
		virtual IObject* getChild() = 0;
		virtual void addChild(IObject* child) = 0;
		virtual void removeChild(IObject* child) = 0;
		virtual void resetCachedRootParents() = 0;
		virtual void handlePlayerInput() = 0;
		virtual void handleMessage(int, IPlayer*, bool) = 0;
		virtual void getInputId() = 0;
		virtual void setInputId() = 0;
		virtual void getChildId() = 0;
		virtual void setChildId() = 0;
		virtual void getAlpha() = 0;
		virtual unsigned char getLayer() = 0;
		virtual void setLayer() = 0;
		virtual unsigned char getGroup() = 0;
		virtual void setGroup() = 0;
		virtual void setIsOvergrowth() = 0;
		virtual bool getIsOvergrowth() = 0;
		virtual void setNotInAI() = 0;
		virtual bool getNotInAI() = 0;
		virtual void setLightSourceMask(int mask) = 0;
		virtual int getLightSourceMask() = 0;
		virtual bool getDisableChildren() = 0;
		virtual void setDisableChildren();
		virtual void getArmorInfo() = 0;
		virtual void isCreatedByLocalPlayer() = 0;
		virtual void internal_assignNewObjectID() = 0;
		virtual void destroyObject() = 0;
		virtual void addSibling(IObject*) = 0;
		virtual void removeSibling(IObject*) = 0;
		virtual void setParent(IObject*) = 0;

		unsigned int m_flags;	 // 0x008
		void* _0x0C;
		IObject* m_objectRoot;				  // 0x018
		unsigned int m_objectId;			  // 0x020
		IObjectTemplate* m_objectTemplate;	  // 0x028
		void* m_gridCullerObj;				  // 0x030
		void* _0x38;
		void* m_latencyCullerObj;				// 0x040
		unsigned int m_objectCacheId;			// 0x048
		IObject* m_objectParent;				// 0x050
		IObject* m_objectSub;					// 0x058
		IObject* m_objectChild;					// 0x060
		void* m_aiObject;						// 0x068
		geom::IGeometry* m_geometry;			// 0x070
		ArmorGLComp* m_armorGlComp;				// 0x078
		IObjectComp* m_collisionMesh;			// 0x080
		IPhysicsNode* m_physicsNode;			// 0x088
		IResponsePhysics* m_responsePhysics;	// 0x090
		io::INetworkable* m_networkable;		// 0x098
		IObjectComp* m_postProcessComp;			// 0x0A0
		IObjectComp* m_vehicleHudComp;			// 0x0A8
		IObjectComp* m_helpHudComp;				// 0x0B0
		IWeaponHudComp* m_weaponHudComp;		// 0x0B8
		IObjectComp* m_abilityHudComp;			// 0x0C0
		IObjectComp* m_abilityGlComp;			// 0x0C8
		IObjectComp* m_radioGlComp;				// 0x0D0
		IObjectComp* m_warningHudComp;			// 0x0D8
		IObjectComp* m_windAffector;			// 0x0E0
		IObjectComp* m_strategicObjectComp;		// 0x0E8
		void* _0xF0;
		WeakPtr<IObject>* m_weakPtr;	// 0x0F8
	};

	inline IObject* getRootParent(IObject* obj)
	{
		if (obj == nullptr)
		{
			return nullptr;
		}
		if (obj->m_flags & IObject::IsRootParent)
		{
			obj->m_objectRoot = obj;
			return obj;
		}
		if (obj->m_objectRoot == nullptr)
		{
			obj->m_objectRoot = getRootParent(obj->m_objectParent);
		}
		return obj->m_objectRoot;
	}
}	 // namespace dice::hfe::world
