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
				case Field::Block::Black:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,{ 16,16,16 } );
					break;
				case Field::Block::Blue:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,Colors::Blue );
					break;
				case Field::Block::Cyan:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,Colors::Cyan );
					break;
				case Field::Block::Gray:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,Colors::Gray );
					break;
				case Field::Block::Green:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,Colors::Green );
					break;
				case Field::Block::LightGray:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,Colors::LightGray );
					break;
				case Field::Block::Magenta:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,Colors::Magenta );
					break;
				case Field::Block::Red:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,Colors::Red );
					break;
				case Field::Block::White:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,Colors::White );
					break;
				case Field::Block::Yellow:
					gfx.DrawRectDim( ScreenMid + ( ( VectorI( x,y ) - player_pos ) * BlockDimansion ) + VectorI( 1,1 ),BlockDimansion - 2,BlockDimansion - 2,Colors::Yellow );
					break;
				}
			}
		}
	}
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
		case Field::Block::Black:
			placed_block[block.y * FieldWidth + block.x] = Block::Black;
			break;
		case Field::Block::Blue:
			placed_block[block.y * FieldWidth + block.x] = Block::Blue;
			break;
		case Field::Block::Cyan:
			placed_block[block.y * FieldWidth + block.x] = Block::Cyan;
			break;
		case Field::Block::Gray:
			placed_block[block.y * FieldWidth + block.x] = Block::Gray;
			break;
		case Field::Block::Green:
			placed_block[block.y * FieldWidth + block.x] = Block::Green;
			break;
		case Field::Block::LightGray:
			placed_block[block.y * FieldWidth + block.x] = Block::LightGray;
			break;
		case Field::Block::Magenta:
			placed_block[block.y * FieldWidth + block.x] = Block::Magenta;
			break;
		case Field::Block::Red:
			placed_block[block.y * FieldWidth + block.x] = Block::Red;
			break;
		case Field::Block::White:
			placed_block[block.y * FieldWidth + block.x] = Block::White;
			break;
		case Field::Block::Yellow:
			placed_block[block.y * FieldWidth + block.x] = Block::Yellow;
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
	gfx.DrawRectHB( getColorHitBox( 0 ),{ 64,64,64 } );
	gfx.DrawRectHB( getColorHitBox( 1 ),{ 16,16,16 } );
	gfx.DrawRectHB( getColorHitBox( 2 ),Colors::Blue );
	gfx.DrawRectHB( getColorHitBox( 3 ),Colors::Cyan );
	gfx.DrawRectHB( getColorHitBox( 4 ),Colors::Gray );
	gfx.DrawRectHB( getColorHitBox( 5 ),Colors::Green );
	gfx.DrawRectHB( getColorHitBox( 6 ),Colors::LightGray );
	gfx.DrawRectHB( getColorHitBox( 7 ),Colors::Magenta );
	gfx.DrawRectHB( getColorHitBox( 8 ),Colors::Red );
	gfx.DrawRectHB( getColorHitBox( 9 ),Colors::White );
	gfx.DrawRectHB( getColorHitBox( 10 ),Colors::Yellow );
}

const HitBoxI Field::getFieldHB() const
{
	return HitBoxI::fromCenter( VectorI( gfx.ScreenWidth / 2,gfx.ScreenHeight / 2 ),RenderDistens * BlockDimansion,RenderDistens * BlockDimansion );
}

void Field::getBlock( const VectorI& mouse_pos )
{
	if ( getColorHitBox( 0 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Empty;
	}
	else if ( getColorHitBox( 1 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Black;
	}
	else if ( getColorHitBox( 2 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Blue;
	}
	else if ( getColorHitBox( 3 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Cyan;
	}
	else if ( getColorHitBox( 4 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Gray;
	}
	else if ( getColorHitBox( 5 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Green;
	}
	else if ( getColorHitBox( 6 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::LightGray;
	}
	else if ( getColorHitBox( 7 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Magenta;
	}
	else if ( getColorHitBox( 8 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Red;
	}
	else if ( getColorHitBox( 9 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::White;
	}
	else if ( getColorHitBox( 10 ).isOverlappingWith( mouse_pos ) )
	{
		chosen_block = Block::Yellow;
	}
}

HitBoxI Field::getColorHitBox( int nhb )
{
	return chb[nhb] = { topleft - VectorI( 20 + 2 * BlockDimansion,-( nhb * 2 * BlockDimansion) ),2 * BlockDimansion,2 * BlockDimansion };
}
