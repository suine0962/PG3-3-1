#include "IScene.h"

//タイトルシーンで初期化
int IScene::sceneNo = TITLE;

// 仮想デストラクタの定義
// 純粋仮想関数化していないので、ここで定義出来る
IScene::~IScene() {}

// シーン番号のゲッター
int IScene::GetSceneNo() { return sceneNo; }

void IScene::SetKeys(char* keys, char* preKeys)
{
	keys_ = keys;
	preKeys_ = preKeys;
}