#include "StageScene.h"
#include <Novice.h>

void StageScene::Init()
{
	// 自キャラの生成
	player_ = std::make_unique<Player>();
	player_->Initialize(keys_, preKeys_);

	// 敵キャラの生成
	enemy_ = std::make_unique<Enemy>();
	Vector2 enemyPos = { 1280 / 2,200 };
	float enemySpeed = 5.0f;
	enemy_->Initialize(enemyPos, enemySpeed);
}

void StageScene::Update()
{
	player_->Update();

	if (isEnemyAlive == 1) {
		enemy_->Update();
	}

	if (keys_[DIK_RETURN] && !preKeys_[DIK_RETURN]) {
		sceneNo = CLEAR;
	}

	if (isEnemyAlive == 0) {
		sceneNo = CLEAR;
	}

	CheckAllCollisions();


	// デスフラグ
	if (enemy_->IsDead()) {
		isEnemyAlive = 0;
	}
}

void StageScene::Draw()
{
	player_->Draw();

	if (isEnemyAlive == 1) {
		enemy_->Draw();
	}

	Novice::ScreenPrintf(1280 / 2, 720 / 2, "StageScene");
}

void StageScene::CheckAllCollisions()
{
	Vector2 posA = {}, posB = {};

	//自弾リストの取得
	const std::list<PlayerBullet*>& playerBullets = player_->GetBullets();

	// 敵キャラの座標
	posA = enemy_->GetPosition();

	// 敵キャラと自弾全ての当たり判定
	for (PlayerBullet* bullet : playerBullets) {

		// 自弾の座標
		posB = bullet->GetPosition();

		float hit = (posA.x - posB.x) * (posA.x - posB.x) + (posA.y - posB.y) * (posA.y - posB.y);

		float radiusA = 30;
		float radiusB = 30;

		float radius = (radiusA + radiusB) * (radiusA + radiusB);

		if (hit == radius || hit < radius) {
			// 敵キャラの衝突時コールバックを呼び出す
			enemy_->OnCollision();
			// 自弾の衝突時コールバックを呼び出す
			bullet->OnCollision();
		}
	}

}