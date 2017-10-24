#include "PlayerClimbHorizontalMoveState.h"
#include "Player.h"

PlayerClimbHorizontalMoveState::PlayerClimbHorizontalMoveState()
{
}

PlayerClimbHorizontalMoveState::PlayerClimbHorizontalMoveState(Player * player, GameObject *horizontalBar) : PlayerState(player, PlayerState::StateName::ClimbHorizontalMove)
{
	_animation = new Animation(ResourceManager::GetInstance()->GetAladdinAnimationXML(), "ClimbHorizontalMove", ResourceManager::GetInstance()->GetAladdinTexture(), 0.7f);
	_animation->FlipVertical(!_player->IsRight());

	_animation->SetPosition(_player->GetPosition());
	_player->SetWidth(_animation->GetWidth());
	_player->SetHeight(_animation->GetHeight());

	_player->SetAccelerationY(0);
	_player->SetVelocityY(0);

	//fix position when jump over height
	_horizontalBar = horizontalBar;
	_player->SetPositionY(_horizontalBar->GetBound().top + _player->GetHeight() / 2.0f);
}


PlayerClimbHorizontalMoveState::~PlayerClimbHorizontalMoveState()
{
}

void PlayerClimbHorizontalMoveState::Update(float deltaTime)
{
	PlayerState::Update(deltaTime);

	if (_player->GetVelocity().x == 0)//change state
	{
		_player->SetState(new PlayerClimbHorizontalIdleState(_player, _horizontalBar));
		return;
	}

	//check if at the left or right of bar || press D
	if (Input::GetInstance()->IsKeyPressed(DIK_D) || _player->GetPosition().x < _horizontalBar->GetBound().left || _player->GetPosition().x > _horizontalBar->GetBound().right)
	{
		//move player out of horizontal-bar (prevent loop idle->fall->idle)
		PlayerState *newState = new PlayerFallState(_player);
		_player->SetPositionY(_player->GetPosition().y + 20);
		_player->SetState(newState);
		return;
	}
}
