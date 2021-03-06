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
		if(Length() != 0)
		{ 
			float length = Length();

			this->X = this->X / length;
			this->Y = this->Y / length;

			return *this;
		}
		else
		{
			return Vector2();
		}
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
	Vector2 operator/(const float f)
	{
		return Vector2(this->X / f, this->Y / f);
	}
	void operator+=(const Vector2 v)
	{
		this->X = this->X + v.X;
		this->Y = this->Y + v.Y;
	}
	~Vector2();
};

