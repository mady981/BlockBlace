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
			if ( placed_block[y * FieldWidth + x] != Block::Empty )
			{
				switch ( placed_block[y * FieldWidth + x] )
				{
				case Field::Block::Empty:
					break;
				case Field::Block::Green:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,{ 0,255,0 } );
					break;
				case Field::Block::Red:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,{ 255,0,0 } );
					break;
				case Field::Block::Yellow:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,{ 255,255,0 } );
					break;
				case Field::Block::GreenBlue:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,{ 0,255,255 } );
					break;
				}
			}
		}
	}
	//gfx.DrawRectDim( ScreenMid,BlockDimansion,BlockDimansion,{ 0,0,255 } );
}

void Field::PlaceBlock( const VectorI& mouse_pos,const VectorI& player_pos )
{
	assert( mouse_pos.x <= ScreenMid.x + ( RenderDistens + 1 ) * BlockDimansion );
	assert( mouse_pos.x > ScreenMid.x - RenderDistens * BlockDimansion );
	assert( mouse_pos.y <= ScreenMid.y + ( RenderDistens + 1 ) * BlockDimansion );
	assert( mouse_pos.y > ScreenMid.y - RenderDistens * BlockDimansion );
	VectorI block = { player_pos + ( ( mouse_pos - topleft ) / BlockDimansion ) - VectorI( RenderDistens,RenderDistens ) };
	if ( chosen_block == Block::Empty || placed_block[block.y * FieldWidth + block.x] == Block::Empty )
	{
		switch ( chosen_block )
		{
		case Field::Block::Empty:
			placed_block[block.y * FieldWidth + block.x] = Block::Empty;
			break;
		case Field::Block::Green:
			placed_block[block.y * FieldWidth + block.x] = Block::Green;
			break;
		case Field::Block::Red:
			placed_block[block.y * FieldWidth + block.x] = Block::Red;
			break;
		case Field::Block::Yellow:
			placed_block[block.y * FieldWidth + block.x] = Block::Yellow;
			break;
		case Field::Block::GreenBlue:
			placed_block[block.y * FieldWidth + block.x] = Block::GreenBlue;
			break;
		}
	}
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

void Field::DrawBlockBar()
{
	gfx.DrawRectHB( getBlockHitBox( 0 ),Colors::White );
	gfx.DrawRectHB( getBlockHitBox( 1 ),Colors::Green );
	gfx.DrawRectHB( getBlockHitBox( 2 ),Colors::Red );
	gfx.DrawRectHB( getBlockHitBox( 3 ),Colors::Yellow );
	gfx.DrawRectHB( getBlockHitBox( 4 ),{ 0,255,255 } );
}

const HitBoxI Field::getFieldHB() const
{
	return HitBoxI::fromCenter( VectorI( gfx.ScreenWidth / 2,gfx.ScreenHeight / 2 ),RenderDistens * BlockDimansion,RenderDistens * BlockDimansion );
}

void Field::getBlock( const VectorI& mouse_pos )
{
	if ( getBlockHitBox( 0 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Empty;
	}
	else if ( getBlockHitBox( 1 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Green;
	}
	else if ( getBlockHitBox( 2 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Red;
	}
	else if ( getBlockHitBox( 3 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Yellow;
	}
	else if ( getBlockHitBox( 4 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::GreenBlue;
	}
}

HitBoxI Field::getBlockHitBox( int nhb )
{
	if ( nhb == 1 )
	{
		return bhb[1] = { topleft - VectorI( 20 + 2 * BlockDimansion,-( 20 + 2 * BlockDimansion ) ),2 * BlockDimansion,2 * BlockDimansion };
	}
	else if ( nhb == 2 )
	{
		return bhb[2] = { topleft - VectorI( 20 + 2 * BlockDimansion,-( 40 + 2 * BlockDimansion ) ),2 * BlockDimansion,2 * BlockDimansion };
	}
	else if ( nhb == 3 )
	{
		return bhb[3] = { topleft - VectorI( 20 + 2 * BlockDimansion,-( 60 + 2 * BlockDimansion ) ),2 * BlockDimansion,2 * BlockDimansion };
	}
	else if ( nhb == 4 )
	{
		return bhb[4] = { topleft - VectorI( 20 + 2 * BlockDimansion,-( 80 + 2 * BlockDimansion ) ),2 * BlockDimansion,2 * BlockDimansion };
	}
	return bhb[0] = { topleft - VectorI( 20 + 2 * BlockDimansion,0 ),2 * BlockDimansion,2 * BlockDimansion };
}
