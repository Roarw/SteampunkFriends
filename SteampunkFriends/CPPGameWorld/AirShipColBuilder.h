#ifndef AIRSHIPCOLBUILDER_H
#define AIRSHIPCOLBUILDER_H

#include "GameObject.h"
#include "Vector2.h"
#include "Physics.h"

#include "Transform.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "Enemy.h"
#include "Wall.h"

class AirShipColBuilder
{
public:
	GameObject * Build(GameWorld * aGameWorld, Vector2 * aPosition, Vector2 * aSize)
	{
#pragma region HELLO IM AN AIRSHUP, DANK DANK

		GameObject * airShipCol = new GameObject(aGameWorld);
		Transform * airShipColTransform = new Transform(airShipCol, aPosition);
		Collider * airShipColCollider =
			new Collider
			(
				airShipCol,
				airShipColTransform,
				RectangleF(aPosition->X, aPosition->Y, aSize->X, aSize->Y)
			);
		Wall * airShipColWall = new Wall(airShipCol);

		airShipCol->AddComponent(airShipColTransform);
		airShipCol->AddComponent(airShipColCollider);
		airShipCol->AddComponent(airShipColWall);

#pragma endregion

		return airShipCol;
	}
};

#endif // !ENEMYBUILDER_H

