#include "StageScene.h"
#include "Novice.h"
void StageScene::Initilize()
{
	input_ = Input::GetInstance();

	playerPos_ = { 640,500 };
	isShot_ = false;

	bulletPos_ = { playerPos_.x ,playerPos_.y - 30 };

	enemyPos_ = { 640,50 };
	isAlive_ = true;


}

void StageScene::Update()
{
	// 弾の発射
	if (input_->TriggerKey(DIK_SPACE)) {
		isShot_ = true;
	}

	if (isShot_) {
		bulletPos_.y -= 5;
	}
	// 当たり判定
	if (bulletPos_.y - 10 <= enemyPos_.y + 40) {
		isAlive_ = false;
	}

	// シーン遷移
	if (!isAlive_) {
		sceneNo_ = CLEAR;
	}


}
void StageScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, RED, kFillModeSolid);
	Novice::DrawEllipse((int)playerPos_.x, (int)playerPos_.y, 40, 40, 0.0f, WHITE, kFillModeSolid);
	if (isShot_) {
		Novice::DrawEllipse((int)bulletPos_.x, (int)bulletPos_.y, 10, 10, 0.0f, WHITE, kFillModeSolid);
	}

	if (isAlive_) {
		Novice::DrawEllipse((int)enemyPos_.x, (int)enemyPos_.y, 40, 40, 0.0f, BLACK, kFillModeSolid);
	}
}
// ゲームを終了
int StageScene::GameClose()
{
	if (input_->TriggerKey(DIK_ESCAPE)) {
		return true;
	}
	return false;
}