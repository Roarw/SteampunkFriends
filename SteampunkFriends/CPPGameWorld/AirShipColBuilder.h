#ifndef AIRSHIPCOLBUILDER_H
#define AIRSHIPCOLBUILDER_H

#include "GameObject.h"
#include "Vector2.h"

#include "Transform.h"
#include "Collider.h"
#include "Wall.h"

class AirShipColBuilder
{
public:
	GameObject * Build(GameWorld * aGameWorld, Vector2 * aPosition, Vector2 * aSize, SIDEWALL wallSide)
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
		Wall * airShipColWall = new Wall(airShipCol, wallSide);

		airShipCol->AddComponent(airShipColTransform);
		airShipCol->AddComponent(airShipColCollider);
		airShipCol->AddComponent(airShipColWall);

		//delete aSize;

#pragma endregion

		return airShipCol;
	}
};

#endif // !ENEMYBUILDER_H

