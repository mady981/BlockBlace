#include "Field.h"

Field::Field( Graphics& gfx )
	:
	gfx( gfx )
{
}

void Field::DrawSeenField( const Vector& player_pos )
{
	for ( int y = int( player_pos.y ) - RenderDistens; y <= int( player_pos.y ) + RenderDistens; ++y )
	{
		for ( int x = int( player_pos.x ) - RenderDistens; x <= int( player_pos.x ) + RenderDistens; ++x )
		{
			if ( HasBlock[y * FieldWidth + x] )
			{
				gfx.DrawRectDim( ScreenMid + ( ( Vector( float( x ),float( y ) ) - player_pos ) * BlockDimansion ) + Vector( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,{ 0,255,0 } );
			}
		}
	}
}

void Field::PlaceBlock( const Vector& mouse_pos )
{
	assert( mouse_pos.x < ScreenMid.x + RenderDistens );
	assert( mouse_pos.x > ScreenMid.x - RenderDistens );
	assert( mouse_pos.y < ScreenMid.y + RenderDistens );
	assert( mouse_pos.y > ScreenMid.y - RenderDistens );
	Vector Bock = { mouse_pos / BlockDimansion };
	HasBlock[int( mouse_pos.y ) * FieldWidth + int( mouse_pos.x )] = true;
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
