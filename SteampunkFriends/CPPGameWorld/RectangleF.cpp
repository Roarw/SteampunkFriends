#include "RectangleF.h"

RectangleF::RectangleF(float x, float y, float width, float height)
{
	this->X = x;
	this->Y = y;
	this->Width = width;
	this->Height = height;
	this->Left = x;
	this->Right = x + Width;
	this->Top = y;
	this->Bottom = y + Height;
}

bool RectangleF::Intersects(RectangleF other)
{
	return !(other.Left > this->Right ||
		other.Right < this->Left ||
		other.Top > this->Bottom ||
		other.Bottom < this->Top);
}

RectangleF::RectangleF()
{
	this->X = 0;
	this->Y = 0;
	this->Width = 0;
	this->Height = 0;
	this->Left = 0;
	this->Right = 0;
	this->Top = 0;
	this->Bottom = 0;
}


RectangleF::~RectangleF()
{
}
