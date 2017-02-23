#ifndef AIRSHIPBUILDER_H
#define AIRSHIPBUILDER_H

#include "GameObject.h"
#include "Vector2.h"

#include "Transform.h"
#include "SpriteRenderer.h"

class AirShipBuilder
{
public:
	GameObject * Build(GameWorld * gameWorld, Vector2 * position)
	{
#pragma region HELLO IM AN AIRSHUP, DANK DANK

		GameObject * airShip = new GameObject(gameWorld);

		Transform * airShipTransform = new Transform(airShip, position);
		SpriteRenderer * airShipSpriteRenderer = new SpriteRenderer(airShip, airShipTransform, ".\\Pokeball.png");

		airShip->AddComponent(airShipTransform);
		airShip->AddComponent(airShipSpriteRenderer);

#pragma endregion

		return airShip;
	}
};

#endif // !ENEMYBUILDER_H

