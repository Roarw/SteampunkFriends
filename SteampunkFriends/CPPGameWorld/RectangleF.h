#pragma once
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

	RectangleF();
	RectangleF(float x, float y, float width, float height);
	bool Intersects(RectangleF other);
	~RectangleF();
};

