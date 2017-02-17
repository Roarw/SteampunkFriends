#ifndef IDRAW
#define IDRAW

class DrawHandler;

class IDraw
{
public:
	virtual void Draw(DrawHandler * drawHandler){}
};

#endif // !IDRAW