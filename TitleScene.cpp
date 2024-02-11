#include "TitleScene.h"
#include "Novice.h"

void TitleScene::Initilize()
{
	input_ = Input::GetInstance();

}

void TitleScene::Update()
{
	// シーン遷移
	if (input_->TriggerKey(DIK_SPACE)) {
		sceneNo_ = STAGE;
	}
}
void TitleScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, GREEN, kFillModeSolid);
}

// ゲームを終了
int TitleScene::GameClose()
{
	if (input_->TriggerKey(DIK_ESCAPE)) {
		return true;
	}
	return false;
}