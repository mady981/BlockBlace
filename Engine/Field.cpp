#include "Field.h"

Field::Field( Graphics& gfx )
	:
	gfx( gfx )
{
}

void Field::DrawSeenField( const VectorI& player_pos )
{
	for ( int y = player_pos.y - RenderDistens; y <= player_pos.y + RenderDistens; ++y )
	{
		for ( int x = player_pos.x - RenderDistens; x <= player_pos.x + RenderDistens; ++x )
		{
			if ( HasBlock[y * FieldWidth + x] )
			{
				gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,{ 0,255,0 } );
			}
		}
	}
}

void Field::PlaceBlock( const VectorI& mouse_pos,const VectorI& player_pos )
{
	assert( mouse_pos.x < ScreenMid.x + RenderDistens * BlockDimansion );
	assert( mouse_pos.x > ScreenMid.x - RenderDistens * BlockDimansion );
	assert( mouse_pos.y < ScreenMid.y + RenderDistens * BlockDimansion );
	assert( mouse_pos.y > ScreenMid.y - RenderDistens * BlockDimansion );
	VectorI topleft = { ScreenMid - VectorI( RenderDistens * BlockDimansion,RenderDistens * BlockDimansion ) };
	VectorI block = { player_pos + ( ( mouse_pos - topleft ) / BlockDimansion ) - VectorI( RenderDistens,RenderDistens ) };
	HasBlock[block.y * FieldWidth + block.x] = true;
}

void Field::Border() const
{
	for ( int y = int( ScreenMid.y ) -  RenderDistens * BlockDimansion - 5; y <= ScreenMid.y + ( RenderDistens + 1 ) * BlockDimansion + 5; ++y )
	{
		for ( int x = int( ScreenMid.x ) - RenderDistens * BlockDimansion - 5; x <= ScreenMid.x + ( RenderDistens + 1 ) * BlockDimansion + 5; ++x )
		{
			if ( !( y >= ScreenMid.y - RenderDistens * BlockDimansion
				&& y < ScreenMid.y + ( RenderDistens + 1 ) * BlockDimansion
				&& x >= ScreenMid.x - RenderDistens * BlockDimansion
				&& x < ScreenMid.x + ( RenderDistens + 1 ) * BlockDimansion ) )
			{
				gfx.PutPixel( x,y,{ 128,128,128 } );
			}
		}
	}
}
