#include "Vector2.h"
#include <math.h>


Vector2::Vector2()
{
	X = 0;
	Y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->X = x;
	this->Y = y;
}

float Vector2::Length()
{
	return sqrt(pow(this->X, 2) + pow(this->Y, 2));
}

void Vector2::Normalize()
{
	float length = this->Length();

	this->X = this->X / length;
	this->Y = this->Y / length;
}


Vector2::~Vector2()
{
}
