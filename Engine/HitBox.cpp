#include "HitBox.h"

HitBoxF::HitBoxF( float left_in,float right_in,float top_in,float bottem_in )
	:
	left( left_in ),
	right( right_in ),
	top( top_in ),
	bottem( bottem_in )
{
}

HitBoxF::HitBoxF( const VectorF& topleft,const VectorF& bottemright )
	:
	HitBoxF( topleft.x,bottemright.x,topleft.y,bottemright.y )
{
}

HitBoxF::HitBoxF( const VectorF& topleft,float width,float height )
	:
	HitBoxF( topleft,topleft + VectorF( width,height ) )
{
}

bool HitBoxF::isOverlappingWith( const HitBoxF& other ) const
{
	return right > other.left && left < other.right
		&& bottem > other.top && top < other.bottem;
}

bool HitBoxF::isOverlappingWith( const VectorF& other ) const
{
	return right > other.x && left < other.x
		&& bottem > other.y && top < other.y;
}

HitBoxF HitBoxF::fromCenter( const VectorF& center,float half_width,float half_height )
{
	const VectorF half( half_width,half_height );
	return HitBoxF( center - half,center + half );
}

HitBoxI::HitBoxI( int left_in,int right_in,int top_in,int bottem_in )
	:
	left( left_in ),
	right( right_in ),
	top( top_in ),
	bottem( bottem_in )
{
}

HitBoxI::HitBoxI( const VectorI& topleft,const VectorI& bottemright )
	:
	HitBoxI( topleft.x,bottemright.x,topleft.y,bottemright.y )
{
}

HitBoxI::HitBoxI( const VectorI& topleft,int width,int height )
	:
	HitBoxI( topleft,topleft + VectorI( width,height ) )
{
}

bool HitBoxI::isOverlappingWith( const HitBoxI& other ) const
{
	return right > other.left&& left < other.right
		&& bottem > other.top&& top < other.bottem;
}

bool HitBoxI::isOverlappingWith( const VectorI& other ) const
{
	return right > other.x&& left < other.x
		&& bottem > other.y&& top < other.y;
}

HitBoxI HitBoxI::fromCenter( const VectorI& center,int half_width,int half_height )
{
	const VectorI half( half_width,half_height );
	return HitBoxI( center - half,center + half );
}
