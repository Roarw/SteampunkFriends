#ifndef ENEMYBUILDER_H
#define ENEMYBUILDER_H

#include "GameObject.h"
#include "Vector2.h"
#include "Physics.h"

#include "Transform.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "Enemy.h"
#include "EnemyCollision.h"

class EnemyBuilder
{
public:
	GameObject * Build(GameWorld * gameWorld, GameObject * rightWall, Vector2 * position, Vector2 * target)
	{
		GameObject * go = new GameObject(gameWorld);
		Transform * transform = new Transform(go, position);
		SpriteRenderer * spriteRenderer = new SpriteRenderer(go, transform, ".\\Enemy.png");
		Collider * collider = new Collider(go, transform, spriteRenderer);
		Enemy * enemy = new Enemy(go, transform, spriteRenderer, target);
		Physics * physics = new Physics(go, transform);
		EnemyCollision * enemyCollision = new EnemyCollision(go, rightWall);
		go->AddComponent(transform);
		go->AddComponent(spriteRenderer);
		go->AddComponent(collider);
		go->AddComponent(enemy);
		go->AddComponent(physics);
		go->AddComponent(enemyCollision);

		return go;
	}
};

#endif // !ENEMYBUILDER_H

