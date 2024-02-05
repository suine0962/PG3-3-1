#include "PlayerBullet.h"
#include <Novice.h>

void PlayerBullet::Initialize(const Vector2& position, const float& speed)
{
	pos = position;

	speed_ = speed;

	size_ = 15;
}

void PlayerBullet::Update()
{
	pos.y -= speed_;

	//時間経過でデス
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}
}

void PlayerBullet::Draw()
{
	Novice::DrawEllipse((int)pos.x, (int)pos.y, size_, size_, 0.0f, RED, kFillModeSolid);
}

void PlayerBullet::OnCollision()
{
	isDead_ = true;
}

Vector2 PlayerBullet::GetPosition()
{
	Vector2 gPos;

	gPos.x = pos.x;
	gPos.y = pos.y;

	return gPos;
}
