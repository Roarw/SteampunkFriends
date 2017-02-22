#pragma once
class Vector2
{
public:
	float X;
	float Y;

	Vector2();
	Vector2(float x, float y);
	float Length();
	void Normalize();
	Vector2 operator-(const Vector2 v)
	{
		return Vector2(this->X - v.X, this->Y - v.Y);
	}
	Vector2 operator+(const Vector2 v)
	{
		return Vector2(this->X + v.X, this->Y + v.Y);
	}
	Vector2 operator*(const float f)
	{
		return Vector2(this->X * f, this->Y * f);
	}
	void operator+=(const Vector2 v)
	{
		this->X += v.X;
		this->Y += v.Y;
	}
	~Vector2();
};

