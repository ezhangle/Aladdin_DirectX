#pragma once

#include "PlayerState.h"
#include "PlayerIdleState.h"
#include "PlayerJumpAttackState.h"
#include "PlayerJumpThrowState.h"
#include "PlayerClimbVerticalState.h"
#include "PlayerSpringState.h"

class PlayerFallState : public PlayerState
{
public:
	PlayerFallState();
	PlayerFallState(Player* player);
	~PlayerFallState();

	void Update(float deltaTime);
	void OnCollision(GameObject *target, GameCollision::SideCollisions side);
};

