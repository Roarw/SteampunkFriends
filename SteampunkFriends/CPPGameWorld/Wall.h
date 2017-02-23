#ifndef WALL_H
#define WALL_H

#include "Component.h"

#include "IOnCollisionEnter.h"
#include "Enums.h"
#include "Vector2.h"

class Wall :
	public Component, public IOnCollisionEnter
{
private:
	SIDEWALL wallSide;
public:
	void OnCollisionEnter(GameObject* other);

	std::string GetName();

	Wall(GameObject * gameObject, SIDEWALL wallSide);
	~Wall();
};
#endif // !WALL_H
