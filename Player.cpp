
#include "Player.h"
#include <Novice.h>

void Player::Initialize(char* keys, char* preKeys)
{
	keys_ = keys;
	preKeys_ = preKeys;

	pos = { 640.0f,660.0f };
}

void Player::Update()
{
	// デスフラグの立った弾を削除
	bullets_.remove_if([](PlayerBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
		});

	Vector2 move{ 0,0 };

	const float kSpeed = 5.0f;

	if (keys_[DIK_W] || keys_[DIK_UP]) {
		move.y -= kSpeed;
	}

	if (keys_[DIK_S] || keys_[DIK_DOWN]) {
		move.y += kSpeed;
	}

	if (keys_[DIK_A] || keys_[DIK_LEFT]) {
		move.x -= kSpeed;
	}

	if (keys_[DIK_D] || keys_[DIK_RIGHT]) {
		move.x += kSpeed;
	}

	pos.x += move.x;
	pos.y += move.y;

	//攻撃処理
	Attack();

	//弾更新
	for (PlayerBullet* bullet : bullets_) {
		bullet->Update();
	}
}

void Player::Draw()
{
	Novice::DrawEllipse((int)pos.x, (int)pos.y, size_, size_, 0.0f, WHITE, kFillModeSolid);

	//弾の描画
	for (PlayerBullet* bullet : bullets_) {
		bullet->Draw();
	}
}

void Player::Attack()
{
	if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] == 0) {
		const float kBulletSpeed = 5.0f;
		Vector2 pPos = GetPosition();

		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Initialize(pPos, kBulletSpeed);

		bullets_.push_back(newBullet);
	}
}

Vector2 Player::GetPosition()
{
	Vector2 gPos;

	gPos.x = pos.x;
	gPos.y = pos.y;

	return gPos;
}