#pragma once
class VectorF
{
public:
	VectorF() = default;
	VectorF( float x_in , float y_in );
	VectorF operator+( const VectorF& rhs ) const;
	VectorF& operator+=( const VectorF& rhs );
	VectorF operator-( const VectorF& rhs ) const;
	VectorF& operator-=( const VectorF& rhs );
	VectorF operator*( float rhs ) const;
	VectorF& operator*=( float rhs );
	VectorF operator/( float rhs ) const;
	VectorF& operator/=( float rhs );
	bool operator==( const VectorF& rhs ) const;
	float getLength() const;
	float getLengthSq() const;
	VectorF& Nomalize();
	VectorF getNomalize() const;
public:
	float x;
	float y;
};

class VectorI
{
public:
	VectorI() = default;
	VectorI( int x_in,int y_in );
	VectorI operator+( const VectorI & rhs ) const;
	VectorI& operator+=( const VectorI & rhs );
	VectorI operator-( const VectorI & rhs ) const;
	VectorI& operator-=( const VectorI & rhs );
	VectorI operator*( int rhs ) const;
	VectorI& operator*=( int rhs );
	VectorI operator/( int rhs ) const;
	VectorI& operator/=( int rhs );
	bool operator==( const VectorI & rhs ) const;
	float getLength() const;
	float getLengthSq() const;
	VectorI& Nomalize();
	VectorI getNomalize() const;
public:
	int x;
	int y;
};