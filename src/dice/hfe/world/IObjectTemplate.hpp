#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/WeakPtr.hpp>
#include <dice/hfe/io/IStream.hpp>
#include <dice/hfe/world/IObject.hpp>

namespace dice
{
    namespace hfe
	{
        namespace world
		{
			class IObjectTemplate : public IBase {
			public:
				virtual unsigned int getClassID() = 0;
				virtual ~IObjectTemplate() = 0;
				virtual void templateInitialize() = 0;
				virtual void writeBinary(io::IStream*) = 0;
				virtual void readBinary(io::IStream*) = 0;
				virtual void setName(std::string const&) = 0;
				virtual const std::string const& getName() = 0;
				virtual void getCreator() = 0;
				virtual void setCreator(std::string const&) = 0;
				virtual void getModifiedByUser() = 0;
				virtual void setModifiedByUser(std::string const&) = 0;
				virtual void setId(unsigned int) = 0;
				virtual unsigned int getId() = 0;
				virtual void getFlags() = 0;
				virtual void updateFlags(unsigned int, unsigned int) = 0;
				virtual void queryImplementation(unsigned int) = 0;
				virtual void createObject() = 0;
				virtual void setComponent(unsigned int, IBase*) = 0;
				virtual void queryComponent(unsigned int) = 0;
				virtual void getComponentFromClassID(unsigned int) = 0;
				virtual void objectCreated(IObject*) = 0;
				virtual void objectDestroyed(IObject*) = 0;
				virtual void preCache() = 0;
				virtual void setCullRadiusScale(float) = 0;
				virtual void getCullRadiusScale() = 0;
				virtual void setPhysicsComponent(IObject*) = 0;
				virtual void removePhysicsComponent(IObject*) = 0;
				virtual void setPhysicsNodeComponent(IObject*) = 0;
				virtual void removePhysicsNodeComponent(IObject*) = 0;
				virtual void setResponsePhysicsComponent(IObject*) = 0;
				virtual void removeResponsePhysicsComponent(IObject*) = 0;
				virtual void setNetworkableInfo(std::string const&) = 0;
				virtual void getNetworkableInfo() = 0;
				virtual void setCollisionMesh(std::string const&) = 0;
				virtual void getCollisionMesh() = 0;
				virtual void getAnchor() = 0;
				virtual void setAnchor(Vec3 const&) = 0;
				virtual void getAnchorOffset() = 0;
				virtual void setAnchorOffset(Vec3 const&) = 0;
				virtual void getAnchorPos() = 0;
				virtual void setIsOvergrowth(bool) = 0;
				virtual void getIsOvergrowth() = 0;
				virtual void getMaterialVector() = 0;
				virtual void getComponentMap() = 0;
				virtual void setMaterial(int) = 0;
				virtual void getMaterial() = 0;
				virtual void setSpecialMaterials(unsigned int) = 0;
				virtual void getSpecialMaterials() = 0;

				WeakPtr<IObjectTemplate>* m_weakPtr;
			};
		}
	}
}