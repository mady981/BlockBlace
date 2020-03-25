#pragma once
#include "Vector.h"

class HitBoxF
{
public:
	HitBoxF() = default;
	HitBoxF( float left_in,float right_in,float top_in,float bottem_in );
	HitBoxF( const VectorF& topleft,const VectorF& bottemright );
	HitBoxF( const VectorF& topleft,float width,float height );
	bool isOverlappingWith( const HitBoxF& other ) const;
	bool isOverlappingWith( const VectorF& other ) const;
	static HitBoxF fromCenter( const VectorF& center,float half_width,float half_height );
public:
	float left;
	float right;
	float top;
	float bottem;
};

class HitBoxI
{
public:
	HitBoxI() = default;
	HitBoxI( int left_in,int right_in,int top_in,int bottem_in );
	HitBoxI( const VectorI& topleft,const VectorI& bottemright );
	HitBoxI( const VectorI& topleft,int width,int height );
	bool isOverlappingWith( const HitBoxI& other ) const;
	bool isOverlappingWith( const VectorI& other ) const;
	static HitBoxI fromCenter( const VectorI& center,int half_width,int half_height );
public:
	int left;
	int right;
	int top;
	int bottem;
};

