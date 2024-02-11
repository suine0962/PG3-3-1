#include "IScene.h"

// タイトルシーンで初期化
int IScene::sceneNo_ = TITLE;


// 仮想デストラクタの定義
// 純粋仮想関数化していないのでここで定義できる
IScene::~IScene() {}

// シーン管理のゲッター
int IScene::GetSceneNo() { return sceneNo_; }