#include"ClearScene.h"
#include <Novice.h>

void ClearScene::Init()
{
}

void ClearScene::Update()
{
	if (keys_[DIK_RETURN] && !preKeys_[DIK_RETURN]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(1280 / 2, 720 / 2, "ClearScene");
}
