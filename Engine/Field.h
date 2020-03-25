#pragma once
#include "Graphics.h"
#include "Vector.h"
#include <assert.h>

class Field
{
public:
	Field( Graphics& gfx );
	void DrawSeenField( const Vector& player_pos );
	void PlaceBlock( const Vector& mouse_pos );
	void Border() const;
private:
	static constexpr int BlockDimansion = 20; //pixel , one block
	static constexpr unsigned char FieldWidth = 255; //blocks
	static constexpr unsigned char FieldHeight = 255; //blocks
	static constexpr int RenderDistens = 10; //blocks
	bool HasBlock[FieldWidth * FieldHeight] = { false };
	const Vector ScreenMid = { Graphics::ScreenWidth / 2,Graphics::ScreenHeight / 2 }; //Pixel
	Graphics& gfx;
};