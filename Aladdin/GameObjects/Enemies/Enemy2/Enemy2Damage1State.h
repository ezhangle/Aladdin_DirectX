#pragma once

#include "../EnemyState.h"
#include "Enemy2AttackState.h"

class Enemy2Damage1State : public EnemyState
{
public:
	Enemy2Damage1State();
	Enemy2Damage1State(Enemy* enemy);
	~Enemy2Damage1State();

	void Update(float deltaTime);
};

