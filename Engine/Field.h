#pragma once
#include "Graphics.h"
#include "Vector.h"

class Field
{
public:
	Field( Graphics& gfx );
	void DrawSeenField( const Vector& player_pos );
	void Border() const;
private:
	static constexpr int BlockDimansion = 20;
	static constexpr unsigned char FieldWidth = 255;
	static constexpr unsigned char FieldHeight = 255;
	bool HasBlock[FieldWidth * FieldHeight] = { false };
	Graphics& gfx;
};