#pragma once
class Vector2
{
public:
	float X;
	float Y;

	Vector2();
	Vector2(float x, float y);
	float Length();
	Vector2 Normalize();
	Vector2 operator-(const Vector2 v)
	{
		return Vector2(this->X - v.X, this->Y - v.Y);
	}
	~Vector2();
};

