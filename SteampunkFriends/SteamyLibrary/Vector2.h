#pragma once
class Vector2
{
public:
	float X;
	float Y;

	_declspec(dllexport) Vector2();
	_declspec(dllexport) Vector2(float x, float y);
	_declspec(dllexport) float Length();
	_declspec(dllexport) void Normalize();
	_declspec(dllexport) Vector2 operator-(const Vector2 v)
	{
		return Vector2(this->X - v.X, this->Y - v.Y);
	}
	_declspec(dllexport) Vector2 operator+(const Vector2 v)
	{
		return Vector2(this->X + v.X, this->Y + v.Y);
	}
	_declspec(dllexport) Vector2 operator*(const float f)
	{
		return Vector2(this->X * f, this->Y * f);
	}
	_declspec(dllexport) void operator+=(const Vector2 v)
	{
		this->X += v.X;
		this->Y += v.Y;
	}
	_declspec(dllexport) ~Vector2();
};

