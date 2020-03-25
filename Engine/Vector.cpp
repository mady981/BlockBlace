#include "Vector.h"
#include <cmath>

VectorF::VectorF(float x_in, float y_in)
	:
	x( x_in ),
	y( y_in )
{
}

VectorF VectorF::operator+(const VectorF& rhs) const
{
	return VectorF( x + rhs.x , y + rhs.y );
}

VectorF& VectorF::operator+=(const VectorF& rhs)
{
	return *this = *this + rhs;
}

VectorF VectorF::operator-( const VectorF& rhs ) const
{
	return VectorF( x - rhs.x,y - rhs.y );
}

VectorF& VectorF::operator-=( const VectorF& rhs )
{
	return *this = *this - rhs;
}

VectorF VectorF::operator*(float rhs) const
{
	return VectorF( x * rhs , y * rhs );
}

VectorF& VectorF::operator*=(float rhs)
{
	return *this = *this * rhs;
}

VectorF VectorF::operator/( float rhs ) const
{
	return VectorF( x / rhs,y / rhs );
}

VectorF& VectorF::operator/=( float rhs )
{
	return *this = *this / rhs;
}

bool VectorF::operator==( const VectorF& rhs ) const
{
	return x == rhs.x && y == rhs.y;
}

float VectorF::getLength() const
{
	return std::sqrt( getLengthSq() );
}

float VectorF::getLengthSq() const
{
	return x * x + y * y;
}

VectorF& VectorF::Nomalize()
{
	return *this = getNomalize();
}

VectorF VectorF::getNomalize() const
{
	const float len = getLengthSq();
	if ( len != 0.0f )
	{
		return *this * (1.0f / len);
	}
	return *this;
}

VectorI::VectorI( int x_in,int y_in )
	:
	x( x_in ),
	y( y_in )
{
}

VectorI VectorI::operator+( const VectorI& rhs ) const
{
	return VectorI( x + rhs.x,y + rhs.y );
}

VectorI& VectorI::operator+=( const VectorI& rhs )
{
	return *this = *this + rhs;
}

VectorI VectorI::operator-( const VectorI& rhs ) const
{
	return VectorI( x - rhs.x,y - rhs.y );
}

VectorI& VectorI::operator-=( const VectorI& rhs )
{
	return *this = *this - rhs;
}

VectorI VectorI::operator*( int rhs ) const
{
	return VectorI( x * rhs,y * rhs );
}

VectorI& VectorI::operator*=( int rhs )
{
	return *this = *this * rhs;
}

VectorI VectorI::operator/( int rhs ) const
{
	return VectorI( x / rhs,y / rhs );
}

VectorI& VectorI::operator/=( int rhs )
{
	return *this = *this / rhs;
}

bool VectorI::operator==( const VectorI& rhs ) const
{
	return x == rhs.x && y == rhs.y;
}

int VectorI::getLength() const
{
	return std::sqrt( getLengthSq() );
}

int VectorI::getLengthSq() const
{
	return x * x + y * y;
}

VectorI& VectorI::Nomalize()
{
	return *this = getNomalize();
}

VectorI VectorI::getNomalize() const
{
	const int len = getLengthSq();
	if ( len != 0 )
	{
		return *this * ( 1 / len );
	}
	return *this;
}
