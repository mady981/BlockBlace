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
		Green,
		Red,
		Yellow,
		GreenBlue
	};
public:
	Field( Graphics& gfx );
	void DrawSeenField( const VectorI& player_pos );
	void PlaceBlock( const VectorI& mouse_pos,const VectorI& player_pos );
	void Border() const;
	void getBlock( const VectorI& mouse_pos );
	void DrawBlockBar();
	const HitBoxI getFieldHB() const;
	HitBoxI getBlockHitBox( int nhb );
private:
	static constexpr int BlockDimansion = 10; //pixel , one block
	static constexpr unsigned char FieldWidth = 255; //blocks
	static constexpr unsigned char FieldHeight = 255; //blocks
	static constexpr int RenderDistens = 28; //blocks
	static constexpr int maxBlocks = 5;
	Block chosen_block = { Block::Empty };
	Block placed_block[FieldWidth * FieldHeight] = { Block::Empty };
	const VectorI ScreenMid = { ( Graphics::ScreenWidth / 2 ) - ( BlockDimansion / 2 ),( Graphics::ScreenHeight / 2 ) - ( BlockDimansion / 2 ) }; //Pixel
	const VectorI topleft = { ScreenMid - VectorI( RenderDistens * BlockDimansion,RenderDistens * BlockDimansion ) };
	Graphics& gfx;
	HitBoxI bhb[maxBlocks];
};