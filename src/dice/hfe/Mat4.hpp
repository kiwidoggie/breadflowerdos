#pragma once

#include <cmath>
#include <dice/hfe/Math.hpp>

namespace dice::hfe
{
	class Vec3;

	class Mat4
	{
	public:
		union
		{
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};

			float m[4][4];
		};

		Mat4() :
			_11(1),
			_12(0),
			_13(0),
			_14(0),
			_21(0),
			_22(1),
			_23(0),
			_24(0),
			_31(0),
			_32(0),
			_33(1),
			_34(0),
			_41(0),
			_42(0),
			_43(0),
			_44(1) { };

		Mat4(
			float _11, float _12, float _13, float _14, float _21, float _22,
			float _23, float _24, float _31, float _32, float _33, float _34,
			float _41, float _42, float _43, float _44) :
			_11(_11),
			_12(_12),
			_13(_13),
			_14(_14),
			_21(_21),
			_22(_22),
			_23(_23),
			_24(_24),
			_31(_31),
			_32(_32),
			_33(_33),
			_34(_34),
			_41(_41),
			_42(_42),
			_43(_43),
			_44(_44) { };

		const Vec3& translation() const
		{
			return *reinterpret_cast<const Vec3*>(&_41);
		};

		Vec3& translation()
		{
			return *reinterpret_cast<Vec3*>(&_41);
		};

		Mat4& setRotateXDeg(float angle)
		{
			angle = -degToRad(angle);
			const float c = ::std::cos(angle);
			const float s = ::std::sin(angle);
			*this = Mat4(1, 0, 0, 0, 0, c, -s, 0, 0, s, c, 0, 0, 0, 0, 1);
			return *this;
		};

		Mat4& setRotateYDeg(float angle)
		{
			angle = -degToRad(angle);
			const float c = ::std::cos(angle);
			const float s = ::std::sin(angle);
			*this = Mat4(c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1);
			return *this;
		};

		Mat4& setRotateZDeg(float angle)
		{
			angle = -degToRad(angle);
			const float c = ::std::cos(angle);
			const float s = ::std::sin(angle);
			*this = Mat4(c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
			return *this;
		};

		Mat4& identity()
		{
			_11 = 1.0f;
			_12 = 0.0f;
			_13 = 0.0f;
			_14 = 0.0f;
			_21 = 0.0f;
			_22 = 1.0f;
			_23 = 0.0f;
			_24 = 0.0f;
			_31 = 0.0f;
			_32 = 0.0f;
			_33 = 1.0f;
			_34 = 0.0f;
			_41 = 0.0f;
			_42 = 0.0f;
			_43 = 0.0f;
			_44 = 1.0f;
			return *this;
		};

		static const Mat4& getIdentity()
		{
			static Mat4 i;
			return i;
		};

		Mat4& rotMult(const Mat4& a, const Mat4& b)
		{
			_11 = a._11 * b._11 + a._12 * b._21 + a._13 * b._31;
			_12 = a._11 * b._12 + a._12 * b._22 + a._13 * b._32;
			_13 = a._11 * b._13 + a._12 * b._23 + a._13 * b._33;
			_21 = a._21 * b._11 + a._22 * b._21 + a._23 * b._31;
			_22 = a._21 * b._12 + a._22 * b._22 + a._23 * b._32;
			_23 = a._21 * b._13 + a._22 * b._23 + a._23 * b._33;
			_31 = a._31 * b._11 + a._32 * b._21 + a._33 * b._31;
			_32 = a._31 * b._12 + a._32 * b._22 + a._33 * b._32;
			_33 = a._31 * b._13 + a._32 * b._23 + a._33 * b._33;
			return *this;
		}

		Mat4& mult(const Mat4& a, const Mat4& b)
		{
			_11 = a._11 * b._11 + a._12 * b._21 + a._13 * b._31;
			_12 = a._11 * b._12 + a._12 * b._22 + a._13 * b._32;
			_13 = a._11 * b._13 + a._12 * b._23 + a._13 * b._33;
			_14 = 0.0f;
			_21 = a._21 * b._11 + a._22 * b._21 + a._23 * b._31;
			_22 = a._21 * b._12 + a._22 * b._22 + a._23 * b._32;
			_23 = a._21 * b._13 + a._22 * b._23 + a._23 * b._33;
			_24 = 0.0f;
			_31 = a._31 * b._11 + a._32 * b._21 + a._33 * b._31;
			_32 = a._31 * b._12 + a._32 * b._22 + a._33 * b._32;
			_33 = a._31 * b._13 + a._32 * b._23 + a._33 * b._33;
			_34 = 0.0f;
			_41 = a._41 * b._11 + a._42 * b._21 + a._43 * b._31 + b._41;
			_42 = a._41 * b._12 + a._42 * b._22 + a._43 * b._32 + b._42;
			_43 = a._41 * b._13 + a._42 * b._23 + a._43 * b._33 + b._43;
			_44 = 1.0f;
			return *this;
		}

		Mat4& fullMult(const Mat4& a, const Mat4& b)
		{
			_11 = a._11 * b._11 + a._12 * b._21 + a._13 * b._31 + a._14 * b._41;
			_12 = a._11 * b._12 + a._12 * b._22 + a._13 * b._32 + a._14 * b._42;
			_13 = a._11 * b._13 + a._12 * b._23 + a._13 * b._33 + a._14 * b._43;
			_14 = a._11 * b._14 + a._12 * b._24 + a._13 * b._34 + a._14 * b._44;
			_21 = a._21 * b._11 + a._22 * b._21 + a._23 * b._31 + a._24 * b._41;
			_22 = a._21 * b._12 + a._22 * b._22 + a._23 * b._32 + a._24 * b._42;
			_23 = a._21 * b._13 + a._22 * b._23 + a._23 * b._33 + a._24 * b._43;
			_24 = a._21 * b._14 + a._22 * b._24 + a._23 * b._34 + a._24 * b._44;
			_31 = a._31 * b._11 + a._32 * b._21 + a._33 * b._31 + a._34 * b._41;
			_32 = a._31 * b._12 + a._32 * b._22 + a._33 * b._32 + a._34 * b._42;
			_33 = a._31 * b._13 + a._32 * b._23 + a._33 * b._33 + a._34 * b._43;
			_34 = a._31 * b._14 + a._32 * b._24 + a._33 * b._34 + a._34 * b._44;
			_41 = a._41 * b._11 + a._42 * b._21 + a._43 * b._31 + a._44 * b._41;
			_42 = a._41 * b._12 + a._42 * b._22 + a._43 * b._32 + a._44 * b._42;
			_43 = a._41 * b._13 + a._42 * b._23 + a._43 * b._33 + a._44 * b._43;
			_44 = a._41 * b._14 + a._42 * b._24 + a._43 * b._34 + a._44 * b._44;
			return *this;
		}
	};
}	 // namespace dice::hfe
