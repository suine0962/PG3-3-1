﻿#pragma once
#include "Input.h"
// シーン名を列挙型(Enum)で定義
enum SCENE { TITLE, STAGE, CLEAR };
class IScene
{
protected:
	// シーン番号を管理する変数
	static int sceneNo_;
	Input* input_ = Input::GetInstance();

public:
	// 継承先で実装される関数
	// 抽象クラスなので純粋仮想関数とする
	virtual void Initilize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual int GameClose() = 0;

	// 仮想デストラクタを用意しないと警告される
	virtual ~IScene();

	// シーン番号のゲッター
	int GetSceneNo();
private:
	//Input* input_ = nullptr;
};