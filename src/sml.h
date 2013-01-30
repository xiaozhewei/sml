#ifndef __SML_H__
#define __SML_H__

#ifndef __MATH_H__
#include <math.h>
#define __MATH_H__
#endif

#define null 0
#undef  PI
#define PI 					(3.1415926535897932)
#define SMALL_NUMBER		(1.e-8)
#define KINDA_SMALL_NUMBER	(1.e-4)
#define BIG_NUMBER			(3.4e+38f)
#define EULERS_NUMBER       (2.71828182845904523536)
#define INV_PI				(0.31830988618)
#define HALF_PI				(1.57079632679)
#define DELTA				(0.00001f)

namespace sml
{

class vec2;
class vec3;
class vec4;
class mat;
class quat;
class plane;
class rotator;
class globalMath;
extern globalMath gmath;

class vec2
{
public:
	float x, y;
	vec2();
	vec2( float x0, float y0 );
	vec2&		operator+=( const vec2& o );
	vec2&		operator-=( const vec2& o );
	vec2&		operator*=( float s );
	vec2&		operator/=( float s );
	vec2		operator+( const vec2& o ) const;
	vec2		operator-( const vec2& o ) const;
	vec2		operator-() const;
	vec2		operator*( float s ) const;
	vec2		operator/( float s ) const;
	bool		operator==( const vec2& o ) const;
	bool		operator!=( const vec2& o ) const;
	void		set( float x0, float y0 );
	float		size() const;
	float		sizeSquared() const;
	void		normalize();
	vec2		normalized() const;
	vec2		rotate(const float angle) const;
public:
	friend float	dot( const vec2& a, const vec2& b );
	friend float	cross( const vec2& a, const vec2& b );
};

class vec3
{
public:
	float x, y, z;
	vec3();
	vec3( float x0, float y0, float z0 );
	vec3( const vec2& v0, float w0 );
	vec3( const vec4& v);
	vec3&		operator+=( const vec3& o );
	vec3&		operator-=( const vec3& o );
	vec3&		operator*=( float s );
	vec3&		operator/=( float s );
	vec3		operator+( const vec3& o ) const;
	vec3		operator-( const vec3& o ) const;
	vec3		operator-() const;
	vec3		operator*( float s ) const;
	vec3		operator/( float s ) const;
	bool		operator==( const vec3& o ) const;
	bool		operator!=( const vec3& o ) const;
	void		set( float x0, float y0, float z0 );
	float		size() const;
	float		sizeSquared() const;
	void		normalize();
	vec3		normalized() const;
	vec3		rotate( const vec3& axis, const float angle ) const;
	vec3		planeMirror( const plane& p ) const;
	vec3		normalMirror( const vec3& normal ) const;
public:
	friend vec3		operator*( const float s, const vec3& v);
	friend vec3		lerp( const vec3& a, const vec3& b, float t);
	friend float	dot( const vec3& a, const vec3& b );
	friend vec3		cross( const vec3& a, const vec3& b );
};

class vec4
{
public:
	float x, y, z, w;
	vec4();
	vec4( float x0, float y0, float z0, float w0 );
	vec4&		operator+=( const vec4& o );
	vec4&		operator-=( const vec4& o );
	vec4&		operator*=( float s );
	vec4&		operator/=( float s );
	vec4		operator+( const vec4& o ) const;
	vec4		operator-( const vec4& o ) const;
	vec4		operator-() const;
	vec4		operator*( float s ) const;
	vec4		operator/( float s ) const;
	bool		operator==( const vec4& o ) const;
	bool		operator!=( const vec4& o ) const;
	void		set( float x0, float y0, float z0, float w0 );
	float		size3() const;
	float		sizeSquared3() const;
	vec4		normalized3();
public:
	friend float	dot3( const vec4& a, const vec4& b );
};


class mat
{
public:
	float				m[4][4];
	static const mat	identity;
	mat();
	mat(const vec4& inx,const vec4& iny,const vec4& inz,const vec4& inw);
	mat			operator*( const mat& o ) const;
	mat&		operator*=( const mat& o );
	bool		operator==( const mat& o ) const;
	bool		operator!=( const mat& o ) const;

	vec4		transform( const vec3& v ) const;
	vec4		transform( const vec4& p ) const;
	vec3		inverseTransform( const vec3& v ) const;
	vec4		transformNormal( const vec3& v ) const;
	vec3		inverseTransformNormal( const vec3& v ) const;
	mat			transpose() const;
	float		determinant() const;
	mat			inverse() const;
	mat			transposeAdjoint() const;

	vec3		getOrigin() const;
	vec3		getAxis(int i) const;
	void		getAxes(vec3 &x, vec3 &y, vec3 &z) const;
	void		setAxis( int i, const vec3& axis );
	void		setOrigin( const vec3& origin );
	void		setAxes(vec3* axis0 = null, vec3* axis1 = null, vec3* axis2 = null, vec3* origin = null);

	void		setIdentityMat();
	void		setTranslationMat(const vec3& delta);
	void		setRotationMat(const rotator& r);
	void		setOrthoMat(float width,float height,float zscale,float zoffset);
	void		setPerspectiveMat(float fovx, float fovy, float multfovx, float multfovy, float minz, float maxz);
	void		setPerspectiveMat(float fov, float width, float height, float minz, float maxz);
	void		setPerspectiveMat(float fov, float width, float height, float minz);
	void		setScaleMat(const vec3& delta);
	void		setScaleMat(float scale);
	void		setRotationTranslationMat(const rotator& rot, const vec3& origin);
	void		setScaleRotationTranslationMat(const vec3& scale, const rotator& rot, const vec3& origin);
	void		setQuatRotationTranslationMat(const quat& q, const vec3& origin);
	void		setInverseRotationMat(const rotator& rot);
	void		setAxisMat(const vec3& xaxis,const vec3& yaxis,const vec3& zaxis,const vec3& origin);
	void		setMirrorMat(const plane& p);
};

class quat 
{
public:
	float x, y, z, w;
	static const quat identity;

	quat() {}
	quat( float inx, float iny, float inz, float ina );
	quat( const mat& m );	
	quat( const vec3& axis, float angle );
	quat( const vec3& euler );
	vec3		euler() const;
	quat		operator+( const quat& q ) const;
	quat		operator-( const quat& q ) const;
	quat		operator*( const quat& q ) const;
	quat		operator*( const float& scale ) const;
	quat		operator-() const;
	bool		operator!=( const quat& q ) const;
	float		operator|( const quat& q ) const;

	bool		normalize();
	float		sizeSquared() const;
	void		toAxisAngle(vec3& axis, float& angle);
	vec3		rotate(vec3 v) const;
	quat		log() const;
	quat		exp() const;
public:
	friend float	dot( const quat& a, const quat& b);
	friend quat		quatBetween(const vec3& vec1, const vec3& vec2);
	friend quat		lerp( const quat& a, const quat& b, float t);

};

class plane : public vec3
{
public:
	float w;

	plane() {}
	plane( const plane& p );
	plane( const vec4& v );
	plane( float inx, float iny, float inz, float inw );
	plane( const vec3& normal, float inw );
	plane( const vec3& base, const vec3& normal );
	plane( const vec3& a, const vec3& b, const vec3& c );
	plane&		operator+=( const plane& o );
	plane&		operator-=( const plane& o );
	plane&		operator*=( float s );
	plane&		operator/=( float s );
	plane		operator+( const plane& o ) const;
	plane		operator-( const plane& o ) const;
	plane		operator-() const;
	plane		operator*( float s ) const;
	plane		operator/( float s ) const;
	bool		operator==( const plane& o ) const;
	bool		operator!=( const plane& o ) const;
	float		planeDot( const vec3 &p ) const;
public:
	friend float	dot( const plane& a, const plane& b );
	friend vec3		intersectLinePlane(const plane p, const vec3& a, const vec3& b);
	friend bool		intersectPlanes3(vec3& i, const plane& p1, const plane& p2, const plane& p3);
	friend bool		intersectPlanes2(vec3& i, vec3& d, const plane& p1, const plane& p2);
};


class rotator
{
public:
	int pitch; // looking up and down (0=straight ahead, +up, -down).
	int yaw;   // rotating around (running in circles), 0=east, +north, -south.
	int roll;  // rotation about axis of screen, 0=straight, +clockwise, -ccw.
	rotator() {}
	rotator( int inp, int iny, int inr );
	rotator( const quat& q );

	rotator		operator+( const rotator &r ) const;
	rotator		operator-( const rotator &r ) const;
	rotator		operator*( float s ) const;
	rotator		operator*= ( float s );
	bool		operator==( const rotator &r ) const;
	bool		operator!=( const rotator &v ) const;
	rotator		operator+=( const rotator &r );
	rotator		operator-=( const rotator &r );
	bool		isZero() const;
	vec3		vector() const;
	vec3		toEuler() const;
	void		fromEuler(const vec3& v);
	quat		quaternion() const;
	rotator		clamp() const;
	rotator		normalize() const;
	rotator		deNormalize() const;
	void		makeShortestRoute();
public:
	static int	normalizeAxis(int angle);
};

class globalMath
{
public:
	enum {ANGLE_SHIFT 	= 2};		// Bits to right-shift to get lookup value.
	enum {ANGLE_BITS	= 14};		// Number of valid bits in angles.
	enum {NUM_ANGLES 	= 16384}; 	// Number of angles that are in lookup table.
	enum {ANGLE_MASK    =  (((1<<ANGLE_BITS)-1)<<(16-ANGLE_BITS))};
	globalMath();
	float		sinTab( int i ) const;
	float		cosTab( int i ) const;
	float		sinFloat( float f ) const;
	float		cosFloat( float f ) const;
private:
	float		trigFloat[NUM_ANGLES];
};

#include "sml.inl"
};

#endif