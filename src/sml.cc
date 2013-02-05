#include "sml.h"

namespace sml
{

globalMath gmath;

vec2 vec2::rotate(const float angle) const
{
	float s		= sinf(angle);
	float c		= cosf(angle);
	return vec2(x * c + y * s, y * c - x * s);
}

// assumes Axis.Size() == 1
vec3 vec3::rotate(const vec3& axis, const float angle) const
{
	float s		= sinf(angle);
	float c		= cosf(angle);

	float xx	= axis.x * axis.x;
	float yy	= axis.y * axis.y;
	float zz	= axis.z * axis.z;

	float xy	= axis.x * axis.y;
	float yz	= axis.y * axis.z;
	float zx	= axis.z * axis.x;

	float xs	= axis.x * s;
	float ys	= axis.y * s;
	float zs	= axis.z * s;

	float omc	= 1.f - c;

	return vec3(
		(omc * xx + c ) * x + (omc * xy - zs) * y + (omc * zx + ys) * z,
		(omc * xy + zs) * x + (omc * yy + c ) * y + (omc * yz - xs) * z,
		(omc * zx - ys) * x + (omc * yz + xs) * y + (omc * zz + c ) * z);
}

//////////////////////////////////////////////////////////////////////////
const mat	mat::identity(vec4(1,0,0,0),vec4(0,1,0,0),vec4(0,0,1,0),vec4(0,0,0,1));

mat mat::operator*( const mat& o ) const
{
	mat	result = *this;
	result *= o;
	return result;
}

mat& mat::operator*=( const mat& o )
{
	mat	result;
	result.m[0][0] = m[0][0] * o.m[0][0] + m[0][1] * o.m[1][0] + m[0][2] * o.m[2][0] + m[0][3] * o.m[3][0];
	result.m[0][1] = m[0][0] * o.m[0][1] + m[0][1] * o.m[1][1] + m[0][2] * o.m[2][1] + m[0][3] * o.m[3][1];
	result.m[0][2] = m[0][0] * o.m[0][2] + m[0][1] * o.m[1][2] + m[0][2] * o.m[2][2] + m[0][3] * o.m[3][2];
	result.m[0][3] = m[0][0] * o.m[0][3] + m[0][1] * o.m[1][3] + m[0][2] * o.m[2][3] + m[0][3] * o.m[3][3];

	result.m[1][0] = m[1][0] * o.m[0][0] + m[1][1] * o.m[1][0] + m[1][2] * o.m[2][0] + m[1][3] * o.m[3][0];
	result.m[1][1] = m[1][0] * o.m[0][1] + m[1][1] * o.m[1][1] + m[1][2] * o.m[2][1] + m[1][3] * o.m[3][1];
	result.m[1][2] = m[1][0] * o.m[0][2] + m[1][1] * o.m[1][2] + m[1][2] * o.m[2][2] + m[1][3] * o.m[3][2];
	result.m[1][3] = m[1][0] * o.m[0][3] + m[1][1] * o.m[1][3] + m[1][2] * o.m[2][3] + m[1][3] * o.m[3][3];

	result.m[2][0] = m[2][0] * o.m[0][0] + m[2][1] * o.m[1][0] + m[2][2] * o.m[2][0] + m[2][3] * o.m[3][0];
	result.m[2][1] = m[2][0] * o.m[0][1] + m[2][1] * o.m[1][1] + m[2][2] * o.m[2][1] + m[2][3] * o.m[3][1];
	result.m[2][2] = m[2][0] * o.m[0][2] + m[2][1] * o.m[1][2] + m[2][2] * o.m[2][2] + m[2][3] * o.m[3][2];
	result.m[2][3] = m[2][0] * o.m[0][3] + m[2][1] * o.m[1][3] + m[2][2] * o.m[2][3] + m[2][3] * o.m[3][3];

	result.m[3][0] = m[3][0] * o.m[0][0] + m[3][1] * o.m[1][0] + m[3][2] * o.m[2][0] + m[3][3] * o.m[3][0];
	result.m[3][1] = m[3][0] * o.m[0][1] + m[3][1] * o.m[1][1] + m[3][2] * o.m[2][1] + m[3][3] * o.m[3][1];
	result.m[3][2] = m[3][0] * o.m[0][2] + m[3][1] * o.m[1][2] + m[3][2] * o.m[2][2] + m[3][3] * o.m[3][2];
	result.m[3][3] = m[3][0] * o.m[0][3] + m[3][1] * o.m[1][3] + m[3][2] * o.m[2][3] + m[3][3] * o.m[3][3];
	*this = result;
	return *this;
}


bool mat::operator==( const mat& o ) const
{
	for(int x = 0;x < 4;x++)
		for(int y = 0;y < 4;y++)
			if(m[x][y] != o.m[x][y])
				return false;
	return true;
}


mat mat::transpose() const
{
	mat	result;

	result.m[0][0] = m[0][0];
	result.m[0][1] = m[1][0];
	result.m[0][2] = m[2][0];
	result.m[0][3] = m[3][0];

	result.m[1][0] = m[0][1];
	result.m[1][1] = m[1][1];
	result.m[1][2] = m[2][1];
	result.m[1][3] = m[3][1];

	result.m[2][0] = m[0][2];
	result.m[2][1] = m[1][2];
	result.m[2][2] = m[2][2];
	result.m[2][3] = m[3][2];

	result.m[3][0] = m[0][3];
	result.m[3][1] = m[1][3];
	result.m[3][2] = m[2][3];
	result.m[3][3] = m[3][3];

	return result;
}

float mat::determinant() const
{
	return	m[0][0] * (
		m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
		m[2][1] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) +
		m[3][1] * (m[1][2] * m[2][3] - m[1][3] * m[2][2])
		) -
		m[1][0] * (
		m[0][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
		m[2][1] * (m[0][2] * m[3][3] - m[0][3] * m[3][2]) +
		m[3][1] * (m[0][2] * m[2][3] - m[0][3] * m[2][2])
		) +
		m[2][0] * (
		m[0][1] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) -
		m[1][1] * (m[0][2] * m[3][3] - m[0][3] * m[3][2]) +
		m[3][1] * (m[0][2] * m[1][3] - m[0][3] * m[1][2])
		) -
		m[3][0] * (
		m[0][1] * (m[1][2] * m[2][3] - m[1][3] * m[2][2]) -
		m[1][1] * (m[0][2] * m[2][3] - m[0][3] * m[2][2]) +
		m[2][1] * (m[0][2] * m[1][3] - m[0][3] * m[1][2])
		);
}

mat mat::inverse() const
{
	mat result;
	const float	det = determinant();

	if(det == 0.0f)
		return mat::identity;

	const float	rdet = 1.0f / det;

	result.m[0][0] = rdet * (
		m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
		m[2][1] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) +
		m[3][1] * (m[1][2] * m[2][3] - m[1][3] * m[2][2])
		);
	result.m[0][1] = -rdet * (
		m[0][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
		m[2][1] * (m[0][2] * m[3][3] - m[0][3] * m[3][2]) +
		m[3][1] * (m[0][2] * m[2][3] - m[0][3] * m[2][2])
		);
	result.m[0][2] = rdet * (
		m[0][1] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) -
		m[1][1] * (m[0][2] * m[3][3] - m[0][3] * m[3][2]) +
		m[3][1] * (m[0][2] * m[1][3] - m[0][3] * m[1][2])
		);
	result.m[0][3] = -rdet * (
		m[0][1] * (m[1][2] * m[2][3] - m[1][3] * m[2][2]) -
		m[1][1] * (m[0][2] * m[2][3] - m[0][3] * m[2][2]) +
		m[2][1] * (m[0][2] * m[1][3] - m[0][3] * m[1][2])
		);

	result.m[1][0] = -rdet * (
		m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
		m[2][0] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) +
		m[3][0] * (m[1][2] * m[2][3] - m[1][3] * m[2][2])
		);
	result.m[1][1] = rdet * (
		m[0][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) -
		m[2][0] * (m[0][2] * m[3][3] - m[0][3] * m[3][2]) +
		m[3][0] * (m[0][2] * m[2][3] - m[0][3] * m[2][2])
		);
	result.m[1][2] = -rdet * (
		m[0][0] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) -
		m[1][0] * (m[0][2] * m[3][3] - m[0][3] * m[3][2]) +
		m[3][0] * (m[0][2] * m[1][3] - m[0][3] * m[1][2])
		);
	result.m[1][3] = rdet * (
		m[0][0] * (m[1][2] * m[2][3] - m[1][3] * m[2][2]) -
		m[1][0] * (m[0][2] * m[2][3] - m[0][3] * m[2][2]) +
		m[2][0] * (m[0][2] * m[1][3] - m[0][3] * m[1][2])
		);

	result.m[2][0] = rdet * (
		m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) -
		m[2][0] * (m[1][1] * m[3][3] - m[1][3] * m[3][1]) +
		m[3][0] * (m[1][1] * m[2][3] - m[1][3] * m[2][1])
		);
	result.m[2][1] = -rdet * (
		m[0][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) -
		m[2][0] * (m[0][1] * m[3][3] - m[0][3] * m[3][1]) +
		m[3][0] * (m[0][1] * m[2][3] - m[0][3] * m[2][1])
		);
	result.m[2][2] = rdet * (
		m[0][0] * (m[1][1] * m[3][3] - m[1][3] * m[3][1]) -
		m[1][0] * (m[0][1] * m[3][3] - m[0][3] * m[3][1]) +
		m[3][0] * (m[0][1] * m[1][3] - m[0][3] * m[1][1])
		);
	result.m[2][3] = -rdet * (
		m[0][0] * (m[1][1] * m[2][3] - m[1][3] * m[2][1]) -
		m[1][0] * (m[0][1] * m[2][3] - m[0][3] * m[2][1]) +
		m[2][0] * (m[0][1] * m[1][3] - m[0][3] * m[1][1])
		);

	result.m[3][0] = -rdet * (
		m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) -
		m[2][0] * (m[1][1] * m[3][2] - m[1][2] * m[3][1]) +
		m[3][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
		);
	result.m[3][1] = rdet * (
		m[0][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) -
		m[2][0] * (m[0][1] * m[3][2] - m[0][2] * m[3][1]) +
		m[3][0] * (m[0][1] * m[2][2] - m[0][2] * m[2][1])
		);
	result.m[3][2] = -rdet * (
		m[0][0] * (m[1][1] * m[3][2] - m[1][2] * m[3][1]) -
		m[1][0] * (m[0][1] * m[3][2] - m[0][2] * m[3][1]) +
		m[3][0] * (m[0][1] * m[1][2] - m[0][2] * m[1][1])
		);
	result.m[3][3] = rdet * (
		m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
		m[1][0] * (m[0][1] * m[2][2] - m[0][2] * m[2][1]) +
		m[2][0] * (m[0][1] * m[1][2] - m[0][2] * m[1][1])
		);

	return result;
}

mat mat::transposeAdjoint() const
{
	mat ta;

	ta.m[0][0] = this->m[1][1] * this->m[2][2] - this->m[1][2] * this->m[2][1];
	ta.m[0][1] = this->m[1][2] * this->m[2][0] - this->m[1][0] * this->m[2][2];
	ta.m[0][2] = this->m[1][0] * this->m[2][1] - this->m[1][1] * this->m[2][0];
	ta.m[0][3] = 0.f;

	ta.m[1][0] = this->m[2][1] * this->m[0][2] - this->m[2][2] * this->m[0][1];
	ta.m[1][1] = this->m[2][2] * this->m[0][0] - this->m[2][0] * this->m[0][2];
	ta.m[1][2] = this->m[2][0] * this->m[0][1] - this->m[2][1] * this->m[0][0];
	ta.m[1][3] = 0.f;

	ta.m[2][0] = this->m[0][1] * this->m[1][2] - this->m[0][2] * this->m[1][1];
	ta.m[2][1] = this->m[0][2] * this->m[1][0] - this->m[0][0] * this->m[1][2];
	ta.m[2][2] = this->m[0][0] * this->m[1][1] - this->m[0][1] * this->m[1][0];
	ta.m[2][3] = 0.f;

	ta.m[3][0] = 0.f;
	ta.m[3][1] = 0.f;
	ta.m[3][2] = 0.f;
	ta.m[3][3] = 1.f;

	return ta;
}

void mat::setAxes(vec3* axis0, vec3* axis1, vec3* axis2, vec3* origin)
{
	if (axis0 != null)
	{
		m[0][0] = axis0->x;
		m[0][1] = axis0->y;
		m[0][2] = axis0->z;
	}
	if (axis1 != null)
	{
		m[1][0] = axis1->x;
		m[1][1] = axis1->y;
		m[1][2] = axis1->z;
	}
	if (axis2 != null)
	{
		m[2][0] = axis2->x;
		m[2][1] = axis2->y;
		m[2][2] = axis2->z;
	}
	if (origin != null)
	{
		m[3][0] = origin->x;
		m[3][1] = origin->y;
		m[3][2] = origin->z;
	}
}

void mat::setTranslationMat(const vec3& delta)
{
	m[0][0] = 1; m[0][1] = 0;  m[0][2] = 0;  m[0][3] = 0;
	m[1][0] = 0; m[1][1] = 1;  m[1][2] = 0;  m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0;  m[2][2] = 1;  m[2][3] = 0;
	m[3][0] = delta.x; m[3][1] = delta.y;  m[3][2] = delta.z;  m[3][3] = 1;
}

void mat::setRotationMat(const rotator& r)
{
	const float	sr	= gmath.sinTab(r.roll);
	const float	sp	= gmath.sinTab(r.pitch);
	const float	sy	= gmath.sinTab(r.yaw);
	const float	cr	= gmath.cosTab(r.roll);
	const float	cp	= gmath.cosTab(r.pitch);
	const float	cy	= gmath.cosTab(r.yaw);

	m[0][0]	= cp * cy;
	m[0][1]	= cp * sy;
	m[0][2]	= sp;
	m[0][3]	= 0.f;

	m[1][0]	= sr * sp * cy - cr * sy;
	m[1][1]	= sr * sp * sy + cr * cy;
	m[1][2]	= - sr * cp;
	m[1][3]	= 0.f;

	m[2][0]	= -( cr * sp * cy + sr * sy );
	m[2][1]	= cy * sr - cr * sp * sy;
	m[2][2]	= cr * cp;
	m[2][3]	= 0.f;

	m[3][0]	= 0.f;
	m[3][1]	= 0.f;
	m[3][2]	= 0.f;
	m[3][3]	= 1.f;
}

void mat::setOrthoMat(float width,float height,float zscale,float zoffset)
{

	m[0][0] = 1/width; m[0][1] = 0;  m[0][2] = 0;  m[0][3] = 0;
	m[1][0] = 0; m[1][1] = 1/height;  m[1][2] = 0;  m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0;  m[2][2] = zscale;  m[2][3] = 0;
	m[3][0] = 0; m[3][1] = 0;  m[3][2] = zoffset * zscale;  m[3][3] = 1;
}

void mat::setScaleMat(float scale)
{
	m[0][0] = scale; m[0][1] = 0;  m[0][2] = 0;  m[0][3] = 0;
	m[1][0] = 0; m[1][1] = scale;  m[1][2] = 0;  m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0;  m[2][2] = scale;  m[2][3] = 0;
	m[3][0] = 0; m[3][1] = 0;  m[3][2] = 0;  m[3][3] = 1;
}

void mat::setScaleMat(const vec3& scale)
{
	m[0][0] = scale.x; m[0][1] = 0;  m[0][2] = 0;  m[0][3] = 0;
	m[1][0] = 0; m[1][1] = scale.y;  m[1][2] = 0;  m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0;  m[2][2] = scale.z;  m[2][3] = 0;
	m[3][0] = 0; m[3][1] = 0;  m[3][2] = 0;  m[3][3] = 1;
}

void mat::setPerspectiveMat(float fovx, float fovy, float multfovx, float multfovy, float minz, float maxz)
{
	m[0][0] = multfovx / tanf(fovx); m[0][1] = 0;  m[0][2] = 0;  m[0][3] = 0;
	m[1][0] = 0; m[1][1] = multfovy / tanf(fovy);  m[1][2] = 0;  m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0;  m[2][2] = maxz / (maxz - minz);   m[2][3] = 1;
	m[3][0] = 0; m[3][1] = 0;  m[3][2] = -minz * (maxz / (maxz - minz));  m[3][3] = 0;
}

void mat::setPerspectiveMat(float fov, float width, float height, float minz, float maxz)
{
	m[0][0] = 1.0f / tanf(fov); m[0][1] = 0;  m[0][2] = 0;  m[0][3] = 0;
	m[1][0] = 0; m[1][1] = width / tanf(fov) / height;  m[1][2] = 0;  m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0;  m[2][2] = maxz / (maxz - minz);  m[2][3] = 1;
	m[3][0] = 0; m[3][1] = 0;  m[3][2] = -minz * (maxz / (maxz - minz));  m[3][3] = 0;
}

void mat::setPerspectiveMat(float fov, float width, float height, float minz)
{
	m[0][0] = 1.0f / tanf(fov); m[0][1] = 0;  m[0][2] = 0;  m[0][3] = 0;
	m[1][0] = 0; m[1][1] = width / tanf(fov) / height;  m[1][2] = 0;  m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0;  m[2][2] = (1.0f - 0.001f); m[2][3] = 1;
	m[3][0] = 0; m[3][1] = 0;  m[3][2] = -minz * (1.0f - 0.001f);  m[3][3] = 0;
}

void mat::setRotationTranslationMat(const rotator& rot, const vec3& origin)
{
	const float	sr	= gmath.sinTab(rot.roll);
	const float	sp	= gmath.sinTab(rot.pitch);
	const float	sy	= gmath.sinTab(rot.yaw);
	const float	cr	= gmath.cosTab(rot.roll);
	const float	cp	= gmath.cosTab(rot.pitch);
	const float	cy	= gmath.cosTab(rot.yaw);

	m[0][0]	= cp * cy;
	m[0][1]	= cp * sy;
	m[0][2]	= sp;
	m[0][3]	= 0.f;

	m[1][0]	= sr * sp * cy - cr * sy;
	m[1][1]	= sr * sp * sy + cr * cy;
	m[1][2]	= - sr * cp;
	m[1][3]	= 0.f;

	m[2][0]	= -( cr * sp * cy + sr * sy );
	m[2][1]	= cy * sr - cr * sp * sy;
	m[2][2]	= cr * cp;
	m[2][3]	= 0.f;

	m[3][0]	= origin.x;
	m[3][1]	= origin.y;
	m[3][2]	= origin.z;
	m[3][3]	= 1.f;
}

void mat::setScaleRotationTranslationMat(const vec3& scale, const rotator& rot, const vec3& origin)
{
	const float	sr	= gmath.sinTab(rot.roll);
	const float	sp	= gmath.sinTab(rot.pitch);
	const float	sy	= gmath.sinTab(rot.yaw);
	const float	cr	= gmath.cosTab(rot.roll);
	const float	cp	= gmath.cosTab(rot.pitch);
	const float	cy	= gmath.cosTab(rot.yaw);

	m[0][0]	= (cp * cy) * scale.x;
	m[0][1]	= (cp * sy) * scale.x;
	m[0][2]	= (sp) * scale.x;
	m[0][3]	= 0.f;

	m[1][0]	= (sr * sp * cy - cr * sy) * scale.y;
	m[1][1]	= (sr * sp * sy + cr * cy) * scale.y;
	m[1][2]	= (- sr * cp) * scale.y;
	m[1][3]	= 0.f;

	m[2][0]	= ( -( cr * sp * cy + sr * sy ) ) * scale.z;
	m[2][1]	= (cy * sr - cr * sp * sy) * scale.z;
	m[2][2]	= (cr * cp) * scale.z;
	m[2][3]	= 0.f;

	m[3][0]	= origin.x;
	m[3][1]	= origin.y;
	m[3][2]	= origin.z;
	m[3][3]	= 1.f;
}

void mat::setQuatRotationTranslationMat(const quat& q, const vec3& origin)
{
	const float x2 = q.x + q.x;  const float y2 = q.y + q.y;  const float z2 = q.z + q.z;
	const float xx = q.x * x2;   const float xy = q.x * y2;   const float xz = q.x * z2;
	const float yy = q.y * y2;   const float yz = q.y * z2;   const float zz = q.z * z2;
	const float wx = q.w * x2;   const float wy = q.w * y2;   const float wz = q.w * z2;

	m[0][0] = 1.0f - (yy + zz);	m[1][0] = xy - wz;				m[2][0] = xz + wy;			m[3][0] = origin.x;
	m[0][1] = xy + wz;			m[1][1] = 1.0f - (xx + zz);		m[2][1] = yz - wx;			m[3][1] = origin.y;
	m[0][2] = xz - wy;			m[1][2] = yz + wx;				m[2][2] = 1.0f - (xx + yy);	m[3][2] = origin.z;
	m[0][3] = 0.0f;				m[1][3] = 0.0f;					m[2][3] = 0.0f;				m[3][3] = 1.0f;
}

void mat::setInverseRotationMat(const rotator& rot)
{
	mat(
		mat(
		vec4(+gmath.cosTab(-rot.yaw),	+gmath.sinTab(-rot.yaw), 0.0f,	0.0f),
		vec4(-gmath.sinTab(-rot.yaw),	+gmath.cosTab(-rot.yaw), 0.0f,	0.0f),
		vec4(0.0f,					0.0f,					1.0f,	0.0f),
		vec4(0.0f,					0.0f,					0.0f,	1.0f)) *
		mat(	// pitch
		vec4(+gmath.cosTab(-rot.pitch),0.0f,				+gmath.sinTab(-rot.pitch),	0.0f),
		vec4(0.0f,					1.0f,					0.0f,						0.0f),
		vec4(-gmath.sinTab(-rot.pitch),0.0f,				+gmath.cosTab(-rot.pitch),	0.0f),
		vec4(0.0f,					0.0f,					0.0f,						1.0f)) *
		mat(	// roll
		vec4(1.0f,					0.0f,					0.0f,						0.0f),
		vec4(0.0f,					+gmath.cosTab(-rot.roll),-gmath.sinTab(-rot.roll),	0.0f),
		vec4(0.0f,					+gmath.sinTab(-rot.roll),+gmath.cosTab(-rot.roll),	0.0f),
		vec4(0.0f,					0.0f,					0.0f,						1.0f))
		);
}

void mat::setAxisMat(const vec3& xaxis,const vec3& yaxis,const vec3& zaxis,const vec3& origin)
{
	for(int rowindex = 0;rowindex < 3; rowindex++)
	{
		m[rowindex][0] = (&xaxis.x)[rowindex];
		m[rowindex][1] = (&yaxis.x)[rowindex];
		m[rowindex][2] = (&zaxis.x)[rowindex];
		m[rowindex][3] = 0.0f;
	}
	m[3][0] = dot(origin, xaxis);
	m[3][1] = dot(origin, yaxis);
	m[3][2] = dot(origin, zaxis);
	m[3][3] = 1.0f;
}

void mat::setMirrorMat(const plane& p)
{
	mat(
		vec4( -2.f*p.x*p.x + 1.f,	-2.f*p.y*p.x,		-2.f*p.z*p.x,		0.f ),
		vec4( -2.f*p.x*p.y,			-2.f*p.y*p.y + 1.f,	-2.f*p.z*p.y,		0.f ),
		vec4( -2.f*p.x*p.z,			-2.f*p.y*p.z,		-2.f*p.z*p.z + 1.f,	0.f ),
		vec4( -2.f*p.x*p.w,			-2.f*p.y*p.w,		-2.f*p.z*p.w,		1.f ) );
}

void mat::setLookAtMat(const vec3& eye,const vec3& at,const vec3& up)
{
	vec3 zaxis = (at - eye).normalized();

	vec3 xaxis = cross(up, zaxis).normalized();

	vec3 yaxis = cross(zaxis, xaxis).normalized();

	m[0][0] = xaxis.x;       m[0][1] = yaxis.x;       m[0][2] = zaxis.x;       m[0][3] = 0;
	m[1][0] = xaxis.y;       m[1][1] = yaxis.y;       m[1][2] = zaxis.y;       m[1][3] = 0;
	m[2][0] = xaxis.z;       m[2][1] = yaxis.z;       m[2][2] = zaxis.z;       m[2][3] = 0;
	m[3][0] = -dot(xaxis, eye);  m[3][1] = -dot(yaxis, eye);  m[3][2] = -dot(zaxis, eye);  m[3][3] = 1;
}

//////////////////////////////////////////////////////////////////////////

const quat quat::identity(0,0,0,1);

quat::quat( const mat& m )
{
	float	s;
	const float tr = m.m[0][0] + m.m[1][1] + m.m[2][2];

	if (tr > 0.0f) 
	{
		float invs = 1.f / sqrtf(tr + 1.f);
		this->w = 0.5f * (1.f / invs);
		s = 0.5f * invs;

		this->x = (m.m[1][2] - m.m[2][1]) * s;
		this->y = (m.m[2][0] - m.m[0][2]) * s;
		this->z = (m.m[0][1] - m.m[1][0]) * s;
	} 
	else 
	{
		int i = 0;

		if (m.m[1][1] > m.m[0][0])
			i = 1;

		if (m.m[2][2] > m.m[i][i])
			i = 2;

		static const int nxt[3] = { 1, 2, 0 };
		const int j = nxt[i];
		const int k = nxt[j];

		s = m.m[i][i] - m.m[j][j] - m.m[k][k] + 1.0f;

		float invs = 1.f / sqrtf(s);

		float qt[4];
		qt[i] = 0.5f * (1.f / invs);

		s = 0.5f * invs;

		qt[3] = (m.m[j][k] - m.m[k][j]) * s;
		qt[j] = (m.m[i][j] + m.m[j][i]) * s;
		qt[k] = (m.m[i][k] + m.m[k][i]) * s;

		this->x = qt[0];
		this->y = qt[1];
		this->z = qt[2];
		this->w = qt[3];
	}
}

quat quat::log() const
{
	quat result;
	result.w = 0.f;
	if ( abs(w) < 1.f )
	{
		const float angle = cosf(w);
		const float sinangle = sinf(angle);
		if ( abs(sinangle) >= SMALL_NUMBER )
		{
			const float scale = angle/sinangle;
			result.x = scale*x;
			result.y = scale*y;
			result.z = scale*z;
			return result;
		}
	}
	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}

quat quat::exp() const
{
	const float angle = sqrtf(x*x + y*y + z*z);
	const float sinangle = sinf(angle);

	quat result;
	result.w = cosf(angle);
	if ( abs(sinangle) >= SMALL_NUMBER )
	{
		const float scale = sinangle/angle;
		result.x = scale*x;
		result.y = scale*y;
		result.z = scale*z;
	}
	else
	{
		result.x = x;
		result.y = y;
		result.z = z;
	}
	return result;
}

quat quatBetween(const vec3& vec1, const vec3& vec2)
{
	const vec3 vc = cross(vec1, vec2);
	const float crossMag = vc.size();
	if(crossMag < KINDA_SMALL_NUMBER)
	{
		return quat::identity;
	}
	float angle = asinf(crossMag);
	if( dot(vec1, vec2) < 0.0f )
	{
		angle = PI - angle;
	}
	const float s = sinf(0.5f * angle);
	const float c = cosf(0.5f * angle);
	const vec3 axis = vc / crossMag;
	return quat(
		s * axis.x,
		s * axis.y,
		s * axis.z,
		c );
}

quat lerp( const quat& a, const quat& b, float t)
{
	quat result;
	const float rawcosom = 
				a.x * b.x +
				a.y * b.y +
				a.z * b.z +
				a.w * b.w;
	const float cosom = floatSelect( rawcosom, rawcosom, -rawcosom );
	float scale0, scale1;
	if( cosom < 0.9999f )
	{	
		const float omega = acosf(cosom);
		const float invsin = 1.f/sinf(omega);
		scale0 = sinf( (1.f - t) * omega ) * invsin;
		scale1 = sinf( t * omega ) * invsin;
	}
	else
	{
		scale0 = 1.0f - t;
		scale1 = t;
	}
	scale1 = floatSelect( rawcosom, scale1, -scale1 );
	result.x = scale0 * a.x + scale1 * b.x;
	result.y = scale0 * a.y + scale1 * b.y;
	result.z = scale0 * a.z + scale1 * b.z;
	result.w = scale0 * a.w + scale1 * b.w;
	return result;
}

//////////////////////////////////////////////////////////////////////////

void rotator::makeShortestRoute()
{
	yaw = yaw & 65535;

	if(yaw > 32768)
		yaw -= 65535;
	else if(yaw < -32768)
		yaw += 65535;

	pitch = pitch & 65535;

	if(pitch > 32768)
		pitch -= 65535;
	else if(pitch < -32768)
		pitch += 65535;

	roll = roll & 65535;

	if(roll > 32768)
		roll -= 65535;
	else if(roll < -32768)
		roll += 65535;
}

globalMath::globalMath()
{
	for( int i=0; i<NUM_ANGLES; i++ )
		trigFloat[i] = sinf((float)i * 2.f * PI / (float)NUM_ANGLES);
}

};