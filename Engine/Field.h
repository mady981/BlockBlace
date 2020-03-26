#pragma once
#include "Graphics.h"
#include "Vector.h"
#include "HitBox.h"
#include <assert.h>

class Field
{
public:
	enum class Block
	{
		Empty,
		Black,
		Blue,
		Cyan,
		Gray,
		Green,
		LightGray,
		Magenta,
		Red,
		White,
		Yellow
	};
public:
	Field( Graphics& gfx );
	void DrawSeenField( const VectorI& player_pos );
	void PlaceBlock( const VectorI& mouse_pos,const VectorI& player_pos );
	void Border() const;
	void getBlock( const VectorI& mouse_pos );
	void DrawBlockBar();
	const HitBoxI getFieldHB() const;
	HitBoxI getColorHitBox( int nhb );
private:
	static constexpr int BlockDimansion = 16; //pixel , one block
	static constexpr unsigned char FieldWidth = 255; //blocks
	static constexpr unsigned char FieldHeight = 255; //blocks
	static constexpr int RenderDistens = 16; //blocks
	static constexpr int nColors = 5;
private:
	const VectorI ScreenMid = { ( Graphics::ScreenWidth / 2 ) - ( BlockDimansion / 2 ),( Graphics::ScreenHeight / 2 ) - ( BlockDimansion / 2 ) }; //Pixel
	const VectorI topleft = { ScreenMid - VectorI( RenderDistens * BlockDimansion,RenderDistens * BlockDimansion ) };
	Block chosen_block = { Block::Empty };
	Block placed_block[FieldWidth * FieldHeight] = { Block::Empty };
	Graphics& gfx;
	HitBoxI chb[11];
};