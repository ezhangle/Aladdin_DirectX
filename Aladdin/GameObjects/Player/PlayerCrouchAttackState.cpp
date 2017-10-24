#include "PlayerCrouchAttackState.h"
#include "Player.h"

PlayerCrouchAttackState::PlayerCrouchAttackState()
{
}

PlayerCrouchAttackState::PlayerCrouchAttackState(Player * player) :PlayerState(player, PlayerState::StateName::CrouchAttack)
{
	_animation = new Animation(ResourceManager::GetInstance()->GetAladdinAnimationXML(), "CrouchAttack", ResourceManager::GetInstance()->GetAladdinTexture(), 0.5f);
	_animation->FlipVertical(!_player->IsRight());

	_animation->SetPosition(_player->GetPosition());
	_player->SetWidth(_animation->GetWidth());
	_player->SetHeight(_animation->GetHeight());
}


PlayerCrouchAttackState::~PlayerCrouchAttackState()
{
}

void PlayerCrouchAttackState::Update(float deltaTime)
{
	PlayerState::Update(deltaTime);

	if (_animation->IsFinish())//change state
	{
		PlayerCrouchIdleState* crouchIdle = new PlayerCrouchIdleState(_player);
		crouchIdle->GetAnimation()->SeekToLastFrame();
		_player->SetState(crouchIdle);
		return;
	}
}
