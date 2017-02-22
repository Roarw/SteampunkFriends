#ifndef ENEMYBUILDER_H
#define ENEMYBUILDER_H

#include "GameObject.h"
#include "Vector2.h"

#include "Transform.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "Enemy.h"

class EnemyBuilder
{
public:
	GameObject * Build(GameWorld * gameWorld, Vector2 * position, Vector2 * target)
	{
		GameObject * go = new GameObject(gameWorld);
		Transform * transform = new Transform(go, position);
		SpriteRenderer * spriteRenderer = new SpriteRenderer(go, transform, ".\\Enemy.png");
		Collider * collider = new Collider(go, transform, spriteRenderer);
		Enemy * enemy = new Enemy(go, transform, target);
		go->AddComponent(transform);
		go->AddComponent(spriteRenderer);
		go->AddComponent(collider);
		go->AddComponent(enemy);

		return go;
	}
};

#endif // !ENEMYBUILDER_H

