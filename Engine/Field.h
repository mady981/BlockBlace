#pragma once
#include "Graphics.h"
#include "Vector.h"
#include "HitBox.h"
#include <assert.h>

class Field
{
public:
	Field( Graphics& gfx );
	void DrawSeenField( const VectorI& player_pos );
	void PlaceBlock( const VectorI& mouse_pos,const VectorI& player_pos );
	void Border() const;
	const HitBoxI getFieldHB() const;
private:
	static constexpr int BlockDimansion = 10; //pixel , one block
	static constexpr int FieldWidth = 511; //blocks
	static constexpr int FieldHeight = 511; //blocks
	static constexpr int RenderDistens = 28; //blocks
	bool HasBlock[FieldWidth * FieldHeight] = { false };
	const VectorI ScreenMid = { ( Graphics::ScreenWidth / 2 ) - ( BlockDimansion / 2 ),( Graphics::ScreenHeight / 2 ) - ( BlockDimansion / 2 ) }; //Pixel
	Graphics& gfx;
};