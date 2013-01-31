
inline float lerp(float a, float b, float t)
{
	return a + (b - a)*t;
}

inline float floatSelect( float comparand, float valuegezero, float valueltzero )
{
	return comparand >= 0.f ? valuegezero : valueltzero;
}



//////////////////////////////////////////////////////////////////////////

inline vec2::vec2() 
{
}


inline vec2::vec2( float x0, float y0) : 
x(x0), y(y0)
{
}

inline vec2& vec2::operator+=( const vec2& o )
{
	x+=o.x; y+=o.y;
	return *this;
}

inline vec2& vec2::operator-=( const vec2& o )
{
	x-=o.x; y-=o.y;
	return *this;
}

inline vec2& vec2::operator*=( float s )
{
	x*=s; y*=s;
	return *this;
}

inline vec2& vec2::operator/=( float s )
{
	x/=s; y/=s;;
	return *this;
}

inline vec2 vec2::operator+( const vec2& o ) const
{
	return vec2(x+o.x, y+o.y);
}

inline vec2 vec2::operator-( const vec2& o ) const
{
	return vec2(x-o.x, y-o.y);
}

inline vec2 vec2::operator-() const
{
	return vec2(-x,-y);
}

inline vec2 vec2::operator*( float s ) const
{
	return vec2(x*s, y*s);
}

inline vec2 vec2::operator/( float s ) const
{
	return vec2(x/s, y/s);
}

inline bool vec2::operator==( const vec2& o ) const
{
	return x==o.x && y==o.y;
}

inline bool vec2::operator!=( const vec2& o ) const
{
	return !(*this == o); 
}

inline void vec2::set( float x0, float y0 )
{
	x=x0; y=y0;
}

inline float vec2::size() const
{
	return sqrtf( x*x + y*y); 
}

inline float vec2::sizeSquared() const
{
	return x*x + y*y;
}

inline void vec2::normalize()
{
	float s = 1.f / size();
	*this *= s;
}

inline vec2 vec2::normalized() const
{
	float s = 1.f / size();
	return *this * s;
}

inline float dot( const vec2& a, const vec2& b )		
{
	return a.x*b.x + a.y*b.y;
}

inline float cross( const vec2& a, const vec2& b )		
{
	return a.x*b.y - a.y*b.x;
}


//////////////////////////////////////////////////////////////////////////

inline vec3::vec3() 
{
}


inline vec3::vec3( float x0, float y0, float z0 ) : 
x(x0), y(y0), z(z0)
{
}


inline vec3::vec3( const vec2& v0, float z0 ) : 
x(v0.x), y(v0.y), z(z0)
{
}

inline vec3::vec3( const vec4& v) :
x(v.x), y(v.y), z(v.z)
{
}


inline vec3& vec3::operator+=( const vec3& o )
{
	x+=o.x; y+=o.y; z+=o.z;
	return *this;
}

inline vec3& vec3::operator-=( const vec3& o )
{
	x-=o.x; y-=o.y; z-=o.z;
	return *this;
}

inline vec3& vec3::operator*=( float s )
{
	x*=s; y*=s; z*=s;
	return *this;
}

inline vec3& vec3::operator/=( float s )
{
	x/=s; y/=s; z/=s;
	return *this;
}

inline vec3 vec3::operator+( const vec3& o ) const
{
	return vec3(x+o.x, y+o.y, z+o.z);
}

inline vec3 vec3::operator-( const vec3& o ) const
{
	return vec3(x-o.x, y-o.y, z-o.z);
}

inline vec3 vec3::operator-() const
{
	return vec3(-x,-y,-z);
}

inline vec3 vec3::operator*( float s ) const
{
	return vec3(x*s, y*s, z*s);
}

inline vec3 vec3::operator/( float s ) const
{
	return vec3(x/s, y/s, z/s);
}

inline bool vec3::operator==( const vec3& o ) const
{
	return x==o.x && y==o.y && z==o.z;
}

inline bool vec3::operator!=( const vec3& o ) const
{
	return !(*this == o); 
}

inline void vec3::set( float x0, float y0, float z0 )
{
	x=x0; y=y0; z=z0;
}

inline float vec3::size() const
{
	return sqrtf( x*x + y*y + z*z ); 
}

inline float vec3::sizeSquared() const
{
	return x*x + y*y + z*z;
}

inline void vec3::normalize()
{
	float s = 1.f / size();
	*this *= s;
}

inline vec3 vec3::normalized() const
{
	float s = 1.f / size();
	return *this * s;
}

inline vec3 vec3::planeMirror( const plane& p ) const
{
	return *this - p * ( 2.f * p.planeDot(*this) );
}

inline vec3 vec3::normalMirror( const vec3& normal ) const
{
	return *this - normal * (2.f * dot(*this, normal));
}

inline vec3	operator*( const float s, const vec3& v)
{
	return vec3(v.x*s, v.y*s, v.z*s);
}

inline vec3 lerp( const vec3& a, const vec3& b, float t)
{
	return vec3(lerp(a.x, b.x, t), lerp(a.y, b.y, t), lerp(a.z, b.z, t));
}

inline float dot( const vec3& a, const vec3& b )		
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

inline vec3 cross( const vec3& a, const vec3& b )		
{
	return vec3( a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x );
}

//////////////////////////////////////////////////////////////////////////


inline vec4::vec4() 
{
}


inline vec4::vec4( float x0, float y0, float z0, float w0 ) : 
x(x0), y(y0), z(z0), w(w0)
{
}


inline vec4& vec4::operator+=( const vec4& o )
{
	x+=o.x; y+=o.y; z+=o.z; w+=o.w;
	return *this;
}

inline vec4& vec4::operator-=( const vec4& o )
{
	x-=o.x; y-=o.y; z-=o.z; w-=o.w;
	return *this;
}

inline vec4& vec4::operator*=( float s )
{
	x*=s; y*=s; z*=s; w*=s;
	return *this;
}

inline vec4& vec4::operator/=( float s )
{
	x/=s; y/=s; z/=s; w/=s;
	return *this;
}

inline vec4 vec4::operator+( const vec4& o ) const
{
	return vec4(x+o.x, y+o.y, z+o.z, w+o.w);
}

inline vec4 vec4::operator-( const vec4& o ) const
{
	return vec4(x-o.x, y-o.y, z-o.z, w-o.w);
}

inline vec4 vec4::operator-() const
{
	return vec4(-x,-y,-z,-w);
}

inline vec4 vec4::operator*( float s ) const
{
	return vec4(x*s, y*s, z*s, w*s);
}

inline vec4 vec4::operator/( float s ) const
{
	return vec4(x/s, y/s, z/s, w/s);
}

inline bool vec4::operator==( const vec4& o ) const
{
	return x==o.x && y==o.y && z==o.z && w==o.w;
}

inline bool vec4::operator!=( const vec4& o ) const
{
	return !(*this == o); 
}

inline void vec4::set( float x0, float y0, float z0, float w0 )
{
	x=x0; y=y0; z=z0, w=w0;
}

inline float vec4::size3() const
{
	return sqrtf( x*x + y*y + z*z ); 
}

inline float vec4::sizeSquared3() const
{
	return x*x + y*y + z*z;
}

inline vec4 vec4::normalized3()
{
	float s = 1.f / size3();
	return vec4(x*s, y*s, z*s, 0);
}

inline float dot3( const vec4& a, const vec4& b )		
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

//////////////////////////////////////////////////////////////////////////

inline mat::mat()
{}

inline mat::mat(const vec4& inx,const vec4& iny,const vec4& inz,const vec4& inw)
{
	m[0][0] = inx.x; m[0][1] = inx.y;  m[0][2] = inx.z;  m[0][3] = inx.w;
	m[1][0] = iny.x; m[1][1] = iny.y;  m[1][2] = iny.z;  m[1][3] = iny.w;
	m[2][0] = inz.x; m[2][1] = inz.y;  m[2][2] = inz.z;  m[2][3] = inz.w;
	m[3][0] = inw.x; m[3][1] = inw.y;  m[3][2] = inw.z;  m[3][3] = inw.w;
}

inline bool mat::operator!=( const mat& o ) const
{
	return !(*this == o);
}

inline vec4 mat::transform( const vec3& v ) const
{
	return transform(vec4(v.x,v.y,v.z,1.0f));
}

inline vec4 mat::transform( const vec4& p ) const
{
	vec4 result;
	result.x = p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + p.w * m[3][0];
	result.y = p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + p.w * m[3][1];
	result.z = p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + p.w * m[3][2];
	result.w = p.x * m[0][3] + p.y * m[1][3] + p.z * m[2][3] + p.w * m[3][3];
	return result;
}

inline vec3 mat::inverseTransform( const vec3& v ) const
{
	vec3 t, result;

	t.x = v.x - m[3][0];
	t.y = v.y - m[3][1];
	t.z = v.z - m[3][2];

	result.x = t.x * m[0][0] + t.y * m[0][1] + t.z * m[0][2];
	result.y = t.x * m[1][0] + t.y * m[1][1] + t.z * m[1][2];
	result.z = t.x * m[2][0] + t.y * m[2][1] + t.z * m[2][2];

	return result;
}

inline vec4 mat::transformNormal( const vec3& v ) const
{
	return transform(vec4(v.x,v.y,v.z,0.0f));
}

inline vec3 mat::inverseTransformNormal( const vec3& v ) const
{
	return vec3( v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2],
		v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2],
		v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] );
}

inline vec3 mat::getOrigin() const
{
	return vec3(m[3][0],m[3][1],m[3][2]);
}

inline vec3 mat::getAxis(int i) const
{
	return vec3(m[i][0], m[i][1], m[i][2]);
}

inline void mat::getAxes(vec3 &x, vec3 &y, vec3 &z) const
{
	x.x = m[0][0]; x.y = m[0][1]; x.z = m[0][2];
	y.x = m[1][0]; y.y = m[1][1]; y.z = m[1][2];
	z.x = m[2][0]; z.y = m[2][1]; z.z = m[2][2];
}

inline void mat::setAxis( int i, const vec3& axis )
{
	m[i][0] = axis.x;
	m[i][1] = axis.y;
	m[i][2] = axis.z;
}

inline void mat::setOrigin( const vec3& origin )
{
	m[3][0] = origin.x;
	m[3][1] = origin.y;
	m[3][2] = origin.z;
}

inline void mat::setIdentityMat()
{
	m[0][0] = 1; m[0][1] = 0;  m[0][2] = 0;  m[0][3] = 0;
	m[1][0] = 0; m[1][1] = 1;  m[1][2] = 0;  m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0;  m[2][2] = 1;  m[2][3] = 0;
	m[3][0] = 0; m[3][1] = 0;  m[3][2] = 0;  m[3][3] = 1;
}

//////////////////////////////////////////////////////////////////////////

inline quat::quat( float inx, float iny, float inz, float ina ) :
x(inx), y(iny), z(inz), w(ina)
{
}

inline quat::quat( const vec3& axis, float angle )
{
	const float half_a = 0.5f * angle;
	const float s = sinf(half_a);
	const float c = cosf(half_a);
	x = s * axis.x;
	y = s * axis.y;
	z = s * axis.z;
	w = c;
}

inline quat::quat( const vec3& euler )
{
}

inline quat quat::operator+( const quat& q ) const
{		
	return quat( x + q.x, y + q.y, z + q.z, w + q.w );
}

inline quat quat::operator-( const quat& q ) const
{
	return quat( x - q.x, y - q.y, z - q.z, w - q.w );
}

inline quat quat::operator*( const quat& q ) const
{
	return quat( 
		w*q.x + x*q.w + y*q.z - z*q.y,
		w*q.y - x*q.z + y*q.w + z*q.x,
		w*q.z + x*q.y - y*q.x + z*q.w,
		w*q.w - x*q.x - y*q.y - z*q.z
		);
}

inline quat quat::operator*( const float& scale ) const
{
	return quat( scale*x, scale*y, scale*z, scale*w);			
}

inline quat quat::operator-() const
{
	return quat( -x, -y, -z, w );
}

inline bool quat::operator!=( const quat& q ) const
{
	return x!=q.x || y!=q.y || z!=q.z || w!=q.w;
}

inline bool quat::normalize()
{
	const float squaresum = (float)(x*x+y*y+z*z+w*w);
	if( squaresum >= DELTA )
	{
		if( abs(squaresum-1.f) >= DELTA )
		{
			const float scale = 1.f / sqrtf(squaresum);
			x *= scale; 
			y *= scale; 
			z *= scale;
			w *= scale;
			return true;
		}
		return false;
	}
	else 
	{	
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.0f;
		return false;
	}
}

inline float quat::sizeSquared() const
{
	return (x*x+y*y+z*z+w*w);
}

inline void quat::toAxisAngle(vec3& axis, float& angle)
{
	angle = 2.f * acosf(w);
	const float s = sqrtf(1.f-(w*w));
	if (s < 0.0001f) 
	{ 
		axis.x = 1.f;
		axis.y = 0.f;
		axis.z = 0.f;
	} 
	else 
	{
		axis.x = x / s;
		axis.y = y / s;
		axis.z = z / s;
	}
};

inline vec3 quat::rotate(vec3 v) const
{	
	const vec3 qv(x, y, z);
	vec3 result = 2.f * w * cross(qv, v);
	result += ((w * w) - dot(qv, qv)) * v;
	result += (2.f * dot(qv, v)) * qv;
	return result;
}

inline float dot( const quat& a, const quat& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

//////////////////////////////////////////////////////////////////////////
inline plane::plane( const plane& p ) :
vec3(p), w(p.w)
{
}

inline plane::plane( const vec4& v ) :
vec3(v), w(v.w)
{
}

inline plane::plane( float inx, float iny, float inz, float inw ) :
vec3(inx, iny, inz), w(inw)
{	
}

inline plane::plane( const vec3& normal, float inw ) :
vec3(normal), w(inw)
{
}

inline plane::plane( const vec3& base, const vec3& normal ) :
vec3(normal), w( dot(base, normal) )
{
}

inline plane::plane( const vec3& a, const vec3& b, const vec3& c ) :
vec3( cross((b-a), (c-a)).normalized() ),
w( dot(a, cross((b-a), (c-a)).normalized()) )
{
}

inline plane& plane::operator+=( const plane& o )
{
	x += o.x; y += o.y; z += o.z; w += o.w;
	return *this;
}

inline plane& plane::operator-=( const plane& o )
{
	x -= o.x; y -= o.y; z -= o.z; w -= o.w;
	return *this;
}

inline plane& plane::operator*=( float s )
{
	x *= s; y *= s; z *= s; w *= s;
	return *this;
}

inline plane& plane::operator/=( float s )
{
	x *= s; y *= s; z *= s; w *= s;
	return *this;
}

inline plane plane::operator+( const plane& o ) const
{
	return plane( x + o.x, y + o.y, z + o.z, w + o.w );
}

inline plane plane::operator-( const plane& o ) const
{
	return plane( x - o.x, y - o.y, z - o.z, w - o.w );
}

inline plane plane::operator-() const
{
	return plane( -x, -y, -z, -w );
}

inline plane plane::operator*( float s ) const
{
	return plane( x * s, y * s, z * s, w * s);
}

inline plane plane::operator/( float s ) const
{
	return plane( x / s, y / s, z / s, w / s);
}

inline bool plane::operator==( const plane& o ) const
{
	return x==o.x && y==o.y && z==o.z && w==o.w;
}

inline bool plane::operator!=( const plane& o ) const
{
	return x!=o.x || y!=o.y || z!=o.z || w!=o.w;
}

inline float dot( const plane& a, const plane& b )
{
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

inline vec3 intersectLinePlane(const plane p, const vec3& a, const vec3& b)
{
	return a + (b-a) * ((p.w - dot(a, p) )/dot((b - a), p));
}

inline bool intersectPlanes3(vec3& i, const plane& p1, const plane& p2, const plane& p3)
{
	const float det = dot( cross(p1, p2) , p3);
	if( det * det < DELTA )
	{
		i = vec3(0,0,0);
		return false;
	}
	else
	{
		i = (p1.w*cross(p2, p3) + p2.w*cross(p3, p1) + p3.w*cross(p1, p2)) / det;
	}
	return true;
}

inline bool intersectPlanes2(vec3& i, vec3& d, const plane& p1, const plane& p2)
{
	d = cross(p1, p2);
	const float dd = d.sizeSquared();
	if( dd < DELTA )
	{
		d = i = vec3(0,0,0);
		return false;
	}
	else
	{
		i = (p1.w * cross(p2, d) + p2.w * cross(d, p1)) / dd;
		d.normalize();
		return true;
	}
}

//////////////////////////////////////////////////////////////////////////
inline rotator::rotator( int inp, int iny, int inr )
:	pitch(inp), yaw(iny), roll(inr)
{
}

inline rotator::rotator( const quat& q )
{
}

inline rotator rotator::operator+( const rotator &r ) const
{
	return rotator( pitch+r.pitch, yaw+r.yaw, roll+r.roll );
}

inline rotator rotator::operator-( const rotator &r ) const
{
	return rotator( pitch-r.pitch, yaw-r.yaw, roll-r.roll );
}

inline rotator rotator::operator*( float scale ) const
{
	return rotator( int(pitch*scale), int(yaw*scale), int(roll*scale) );
}

inline rotator rotator::operator*= (float scale)
{
	pitch = int(pitch*scale); yaw = int(yaw*scale); roll = int(roll*scale);
	return *this;
}

inline bool rotator::operator==( const rotator &r ) const
{
	return pitch==r.pitch && yaw==r.yaw && roll==r.roll;
}

inline bool rotator::operator!=( const rotator &v ) const
{
	return pitch!=v.pitch || yaw!=v.yaw || roll!=v.roll;
}

inline rotator rotator::operator+=( const rotator &r )
{
	pitch += r.pitch; yaw += r.yaw; roll += r.roll;
	return *this;
}

inline rotator rotator::operator-=( const rotator &r )
{
	pitch -= r.pitch; yaw -= r.yaw; roll -= r.roll;
	return *this;
}

inline bool rotator::isZero() const
{
	return ((pitch&65535)==0) && ((yaw&65535)==0) && ((roll&65535)==0);
}

inline vec3 rotator::vector() const
{
	mat m;
	m.setRotationMat( *this );
	return m.getAxis(0);
}

inline vec3 rotator::toEuler() const
{
	return vec3( roll * (180.f / 32768.f), pitch * (180.f / 32768.f), yaw * (180.f / 32768.f) );
}

inline void rotator::fromEuler(const vec3& v)
{
	pitch = int(v.y * (32768.f / 180.f));
	yaw = int(v.z * (32768.f / 180.f));
	roll = int(v.x * (32768.f / 180.f));
}

inline quat rotator::quaternion() const
{
	mat m;
	m.setRotationMat( *this );
	return quat( m );
}

inline rotator rotator::clamp() const
{
	return rotator( pitch&65535, yaw&65535, roll&65535 );
}

inline rotator rotator::normalize() const
{
	rotator rot = *this;
	rot.pitch = normalizeAxis(rot.pitch);
	rot.roll = normalizeAxis(rot.roll);
	rot.yaw = normalizeAxis(rot.yaw);
	return rot;
}

inline rotator rotator::deNormalize() const
{
	rotator rot = *this;
	rot.pitch	= rot.pitch & 0xffff;
	rot.yaw		= rot.yaw & 0xffff;
	rot.roll	= rot.roll & 0xffff;
	return rot;
}

inline int rotator::normalizeAxis(int angle)
{
	angle &= 0xffff;
	if( angle > 32767 ) 
	{
		angle -= 0x10000;
	}
	return angle;
}

//////////////////////////////////////////////////////////////////////////

inline float globalMath::sinTab( int i ) const
{
	return trigFloat[((i>>ANGLE_SHIFT)&(NUM_ANGLES-1))];
}

inline float globalMath::cosTab( int i ) const
{
	return trigFloat[(((i+16384)>>ANGLE_SHIFT)&(NUM_ANGLES-1))];
}

inline float globalMath::sinFloat( float f ) const
{
	return sinTab(int((f*65536.f)/(2.f*PI)));
}

inline float globalMath::cosFloat( float f ) const
{
	return cosTab(int((f*65536.f)/(2.f*PI)));
}
