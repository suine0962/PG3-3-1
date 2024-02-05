#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	// キー入力を受け取る

	if (keys_[DIK_RETURN] && !preKeys_[DIK_RETURN]) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(1280 / 2,720 / 2, "TitleScene");
}