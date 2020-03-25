#pragma once
#include "Vector.h"
class HitBox
{
public:
	HitBox() = default;
	HitBox( float left_in,float right_in,float top_in,float bottem_in );
	HitBox( const VectorF& topleft,const VectorF& bottemright );
	HitBox( const VectorF& topleft,float width,float height );
	bool isOverlappingWith( const HitBox& other ) const;
	bool isOverlappingWith( const VectorF& other ) const;
	static HitBox fromCenter( const VectorF& center,float width,float height );
public:
	float left;
	float right;
	float top;
	float bottem;
};
