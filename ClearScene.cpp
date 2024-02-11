#include "ClearScene.h"
#include "Novice.h"
void ClearScene::Initilize()
{

}

void ClearScene::Update()
{
	// シーン遷移
	if (input_->TriggerKey(DIK_SPACE)) {
		sceneNo_ = TITLE;
	}
}
void ClearScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE, kFillModeSolid);
}


// ゲームを終了
int ClearScene::GameClose()
{
	if (input_->TriggerKey(DIK_ESCAPE)) {
		return true;
	}
	return false;
}