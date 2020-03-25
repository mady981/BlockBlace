#include "Field.h"

Field::Field( Graphics& gfx )
	:
	gfx( gfx )
{
	for ( int i = 0; i < FieldWidth; ++i )
	{
		HasBlock[60 * FieldWidth + i] = true;
		HasBlock[i * FieldWidth + 60] = true;
	}
}

void Field::DrawSeenField( const VectorF& player_pos )
{
	for ( int y = int( player_pos.y ) - RenderDistens; y <= int( player_pos.y ) + RenderDistens; ++y )
	{
		for ( int x = int( player_pos.x ) - RenderDistens; x <= int( player_pos.x ) + RenderDistens; ++x )
		{
			if ( HasBlock[y * FieldWidth + x] )
			{
				gfx.DrawRectDim( ScreenMid + ( ( VectorF( float( x ),float( y ) ) - player_pos ) * BlockDimansion ) + VectorF( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,{ 0,255,0 } );
			}
		}
	}
}

void Field::PlaceBlock( const VectorF& mouse_pos,const VectorF& player_pos )
{
	assert( mouse_pos.x < ScreenMid.x + RenderDistens * BlockDimansion );
	assert( mouse_pos.x > ScreenMid.x - RenderDistens * BlockDimansion );
	assert( mouse_pos.y < ScreenMid.y + RenderDistens * BlockDimansion );
	assert( mouse_pos.y > ScreenMid.y - RenderDistens * BlockDimansion );
	VectorF block = { player_pos + ( ( mouse_pos - ScreenMid ) / BlockDimansion ) };
	HasBlock[int( block.y * FieldWidth + block.x )] = true;
}

void Field::Border() const
{
	for ( int y = int( ScreenMid.y ) -  RenderDistens * BlockDimansion - 5; y <= ScreenMid.y + ( RenderDistens + 1 ) * BlockDimansion + 5; ++y )
	{
		for ( int x = int( ScreenMid.x ) - RenderDistens * BlockDimansion - 5; x <= ScreenMid.x + ( RenderDistens + 1 ) * BlockDimansion + 5; ++x )
		{
			if (!( y >= ScreenMid.y - RenderDistens * BlockDimansion
				&& y < ScreenMid.y + ( RenderDistens + 1 ) * BlockDimansion
				&& x >= ScreenMid.x - RenderDistens * BlockDimansion
				&& x < ScreenMid.x + ( RenderDistens + 1 ) * BlockDimansion ) )
			{
				gfx.PutPixel( x,y,{ 128,128,128 } );
			}
		}
	}
}
