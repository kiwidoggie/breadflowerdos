#pragma once
#include <dice/hfe/Mat4.hpp>
#include <dice/hfe/IBase.hpp>

namespace dice
{
	namespace hfe
	{
		namespace geom
		{
			class IGeometry : public IBase {
			public:
				virtual void function4() = 0;
				virtual void function5() = 0;
				virtual void draw() = 0;
				virtual void drawSilhouette() = 0;
				virtual void drawShadowMap() = 0;
				virtual void function9() = 0;
				virtual void function10() = 0;
				virtual void function11() = 0;
				virtual void function12() = 0;
				virtual void function13() = 0;
				virtual void function14() = 0;
				virtual void function15() = 0;
				virtual void function16() = 0;
				virtual void function17() = 0;
				virtual void function18() = 0;
				virtual void setGeometryNodeTransform(const Mat4* transform, int index) = 0;
				virtual void setTransformation(const Mat4* transform) = 0;
				virtual void function21(unsigned int, unsigned int) = 0;
				virtual void function22() = 0;
				virtual int getNumGeometryNodes() = 0;
				virtual void function24() = 0;
				virtual void function25() = 0;
				virtual void function26() = 0;
				virtual void setSubGeometry(int geom) = 0;
				virtual int  getSubGeometry() = 0;
				virtual void function29() = 0;
				virtual void setGeometryLod(int lod) = 0;
				virtual int getGeometryLod() = 0;
				virtual void function32() = 0;
				virtual void setGeometryMaterial(int mat) = 0;
				virtual int getGeometryMaterial() = 0;
				virtual void function35() = 0;
				virtual void function36() = 0;
				virtual void function37() = 0;
				virtual void function38() = 0;
				virtual void function39() = 0;
				virtual void function40() = 0;
				virtual void function41() = 0;
				virtual void function42() = 0;
				virtual void function43() = 0;
				virtual void function44() = 0;
				virtual void function45() = 0;
				virtual void function46() = 0;
				virtual void function47() = 0;
				virtual void function48() = 0;
				virtual void function49() = 0;
				virtual void function50() = 0;
				virtual void function51() = 0;
				virtual void function52() = 0;
				virtual void function53() = 0;
				virtual void function54() = 0;
				virtual void function55() = 0;
				virtual void function56() = 0;
				virtual void function57() = 0;
				virtual void function58() = 0;
				virtual void function59() = 0;
				virtual void function60() = 0;
				virtual void setAlpha(float) = 0;
			};
		}
	}
}