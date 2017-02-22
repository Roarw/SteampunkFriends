#ifndef PLAYERBUILDER_H
#define PLAYERBUILDER_H

#include "GameObject.h"
#include "Vector2.h"

#include "Transform.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "Player.h"
#include "Gun.h"

class PlayerBuilder 
{
public:
	GameObject * Build(GameWorld * gameWorld, Vector2 * position) 
	{
		GameObject * go = new GameObject(gameWorld);
		Transform * transform = new Transform(go, position);
		SpriteRenderer * spriteRenderer = new SpriteRenderer(go, transform, ".\\Player.png");
		Collider * collider = new Collider(go, transform, spriteRenderer);
		Player * player = new Player(go, transform);
		go->AddComponent(transform);
		go->AddComponent(spriteRenderer);
		go->AddComponent(collider);
		go->AddComponent(player);

		return go;
	}
};

#endif // !PLAYERBUILDER_H

