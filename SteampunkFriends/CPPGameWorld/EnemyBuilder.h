#ifndef ENEMYBUILDER_H
#define ENEMYBUILDER_H

#include "GameObject.h"
#include "Vector2.h"

#include "Transform.h"
#include "SpriteRenderer.h"
#include "Collider.h"

class EnemyBuilder
{
public:
	GameObject * Build(GameWorld * gameWorld, Vector2 * position)
	{
		GameObject * go = new GameObject(gameWorld);
		Transform * transform = new Transform(go, position);
		SpriteRenderer * spriteRenderer = new SpriteRenderer(go, transform, ".\\Enemy.png");
		Collider * collider = new Collider(go, transform, spriteRenderer);
		go->AddComponent(transform);
		go->AddComponent(spriteRenderer);
		go->AddComponent(collider);

		return go;
	}
};

#endif // !ENEMYBUILDER_H

