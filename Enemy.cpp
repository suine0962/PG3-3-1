#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialize(const Vector2& position, const float& speed)
{
	pos = position;

	speed_ = speed;
}

void Enemy::Update()
{
	switch (phase_) {
	case Phase::RIGHT: // 接近
		RIGHT();
		break;
	case Phase::LEFT: // 離脱
		LEFT();
		break;
	}
}

void Enemy::Draw()
{
	//Novice::DrawBox((int)pos.x, (int)pos.y, size_, size_, 0.0f, BLACK, kFillModeSolid);
	Novice::DrawEllipse((int)pos.x, (int)pos.y, size_, size_, 0.0f, BLACK, kFillModeSolid);
}

void Enemy::OnCollision()
{
	isDead_ = true;
}

Vector2 Enemy::GetPosition()
{
	Vector2 gPos;

	gPos.x = pos.x;
	gPos.y = pos.y;

	return gPos;
}

void Enemy::RIGHT()
{
	pos.x += speed_;
	if (pos.x >= 1280) {
		phase_ = Phase::LEFT;
	}
}

void Enemy::LEFT()
{
	pos.x -= speed_;
	if (pos.x <= 0) {
		phase_ = Phase::RIGHT;
	}
}