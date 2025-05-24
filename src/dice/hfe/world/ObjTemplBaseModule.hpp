#pragma once

#include <dice/hfe/IModule.hpp>

namespace dice::hfe::world
{
	class ObjTemplBaseModule : public IModule
	{
	public:
		uint32_t m_refCount;

		ObjTemplBaseModule() :
			m_refCount(1)
		{
		}

		virtual void addRef() override;
		virtual uint32_t getRef() override;
		virtual uint32_t release() override;
		virtual ObjTemplBaseModule* queryInterface(uint32_t) override;
		virtual void getClassList(std::vector<ClassRegInfo>&) override;
		virtual void getSingletonList(std::vector<SingletonRegInfo>&) override;
		virtual bool init() override;
		virtual bool close() override;
	};
}	 // namespace dice::hfe::world
