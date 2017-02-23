#pragma once
class Vector2
{
public:
	float X;
	float Y;

	Vector2();
	Vector2(float x, float y);
	float Length();
	Vector2 Normalize()
	{
		this->X = this->X / Length();
		this->Y = this->Y / Length();

		return *this;
	}
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
	Vector2 operator*(const Vector2 v)
	{
		return Vector2(this->X * v.X, this->Y * v.Y);
	}
	void operator+=(const Vector2 v)
	{
		this->X = this->X + v.X;
		this->Y = this->Y + v.Y;
	}
	~Vector2();
};

