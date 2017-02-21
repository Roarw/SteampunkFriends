#pragma once
#include "Vector2.h"

class RectangleF
{
public:
	float X;
	float Y;
	float Width;
	float Height;
	float Left;
	float Right;
	float Top;
	float Bottom;
	Vector2 Size;

	RectangleF();
	RectangleF(float x, float y, float width, float height);
	bool Intersects(RectangleF other);
	~RectangleF();
};

