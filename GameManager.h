#pragma once

#include <memory>		// std::unique_ptrを使うために必要
#include "IScene.h"		// 基底クラスを読み込む
#include "TitleScene.h" // 各シーンを読み込む
#include "StageScene.h"
#include "ClearScene.h"

class GameManager
{
private:
	//シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	// どのステージを呼び出すか管理する変数
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_; // 前のシーン
	// キー入力結果を受け取る箱
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

public:
	GameManager(); // コンストラクタ
	~GameManager(); // デストラクタ

	int Run();  //この関数でゲームループを呼び出す
};