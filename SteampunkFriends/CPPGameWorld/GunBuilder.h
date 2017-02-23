#pragma once
#include "Player.h"
#include "GameWorld.h"
#include "Gun.h"

class GunBuilder
{
public:
	GameObject * Build(GameWorld * gw, Player * player)
	{
		GameObject * go = new GameObject(gw);
		Vector2 * playerPosition = new Vector2();
		*playerPosition = *((Transform *)player->GetGameObject()->GetComponent("Transform"))->GetPosition();
		Transform * t = new Transform(go, playerPosition);
		SpriteRenderer * spriteRenderer = new SpriteRenderer(go, t, ".\\Steam.png");
		go->AddComponent(t);
		go->AddComponent(spriteRenderer);
		Gun * g = new Gun(go, player, spriteRenderer);
		go->AddComponent(g);

		return go;
	}
};