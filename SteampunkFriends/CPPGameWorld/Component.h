#ifndef COMPONENT_H
#define COMPONENT_H

#include "Collider.h"
#include "Enemy.h"
#include "EnemyCollision.h"
#include "Gun.h"
#include "Physics.h"
#include "Player.h"
#include "PlayerCollision.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Wall.h"

#include "Enums.h"
#include "Vector2.h"
#include "RectangleF.h"

#include "IDraw.h"
#include "IOnCollisionEnter.h"
#include "IOnCollisionExit.h"
#include "IOnCollisionStay.h"
#include "IUpdate.h"

#include "DrawHandler.h"
#include "GameWorld.h"
#include "GameObject.h"
#include "MyMath.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class GameObject;

class Component 
{
protected:
	GameObject * gameObject;
public:
	virtual std::string GetName();
	GameObject * GetGameObject();

	Component(GameObject * gameObject);
	~Component();
};

#endif // COMPONENT_H

