#include "HitBox.h"

HitBox::HitBox( float left_in,float right_in,float top_in,float bottem_in )
	:
	left( left_in ),
	right( right_in ),
	top( top_in ),
	bottem( bottem_in )
{
}

HitBox::HitBox( const VectorF& topleft,const VectorF& bottemright )
	:
	HitBox( topleft.x,bottemright.x,topleft.y,bottemright.y )
{
}

HitBox::HitBox( const VectorF& topleft,float width,float height )
	:
	HitBox( topleft,topleft + VectorF( width,height ) )
{
}

bool HitBox::isOverlappingWith( const HitBox& other ) const
{
	return right > other.left && left < other.right
		&& bottem > other.top && top < other.bottem;
}

bool HitBox::isOverlappingWith( const VectorF& other ) const
{
	return right > other.x && left < other.x
		&& bottem > other.y && top < other.y;
}

HitBox HitBox::fromCenter( const VectorF& center,float width,float height )
{
	const VectorF half( width * 0.5f,height * 0.5f );
	return HitBox( center - half,center + half );
}
