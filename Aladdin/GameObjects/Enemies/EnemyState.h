#pragma once

#include "../../GameComponents/Animation.h"

class Enemy;

class EnemyState
{
public:
	enum StateName
	{
		Idle, Walk, Attack, Injured
	};
	EnemyState();
	EnemyState(Enemy *enemy, StateName name = StateName::Idle);
	~EnemyState();

	virtual void Update(float deltaTime);
	virtual void OnCollision(GameObject *target, GameCollision::SideCollisions side) {};

	Animation* GetAnimation();
	void SetAnimation(Animation* newAnimation);

	StateName GetName();
protected:
	StateName _name;
	Enemy* _enemy;
	Animation* _animation;
};

