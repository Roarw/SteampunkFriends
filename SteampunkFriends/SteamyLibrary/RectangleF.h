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

	_declspec(dllexport) RectangleF();
	_declspec(dllexport) RectangleF(float x, float y, float width, float height);
	_declspec(dllexport) bool Intersects(RectangleF other);
	_declspec(dllexport) ~RectangleF();
};

