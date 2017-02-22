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
		Transform * t = (Transform *)player->GetGameObject()->GetComponent("Transform");
		go->AddComponent(t);
		Gun * g = new Gun(go, player);
		go->AddComponent(g);

		return go;
	}
};