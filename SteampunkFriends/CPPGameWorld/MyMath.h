#ifndef MYMATH_H
#define MYMATH_H

class MyMath
{
public:
	static int sign(float f) 
	{
		int i;

		if (f < 0)
			i = -1;
		else if (f > 0)
			i = 1;
		else
			i = 0;

		return i;
	}
	static float SineCurve(float f)
	{
		return abs(sin(f));
	}
};

#endif // !MYMATH_H

