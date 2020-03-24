#include "Field.h"

Field::Field( Graphics& gfx )
	:
	gfx( gfx )
{
}

void Field::DrawSeenField( const Vector& player_pos )
{
	for ( int y = int( player_pos.y ) - 10; y <= int( player_pos.y ) + 10; ++y )
	{
		for ( int x = int( player_pos.x ) - 10; x <= int( player_pos.x ) + 10; ++x )
		{
			if ( HasBlock[y * FieldWidth + x] )
			{
				//block relativ zum player???
			}
		}
	}
}

void Field::Border() const
{
	for ( int y = 36; y < gfx.ScreenHeight - 35; ++y )
	{
		for ( int x = 36; x < gfx.ScreenWidth - 35; ++x )
		{
			if ( !( y >= 40 && y < gfx.ScreenHeight - 40
				&& x >= 40 && x < gfx.ScreenWidth - 40 ) )
			{
				gfx.PutPixel( x,y,{ 128,128,128 } );
			}
		}
	}
}
