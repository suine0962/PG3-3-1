#pragma once

// シーン名を列挙型(Enum)で定義
enum Scene {
	TITLE,
	STAGE,
	CLEAR,
	SCENEMAX
};

class IScene
{
protected:
	//シーン番号を管理する変数
	static int sceneNo;
	char* keys_;
	char* preKeys_;

public:
	//継承先で実装される関数
	//抽象クラスなので純粋仮想関数とする
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//仮想デストラクタを用意しないと警告される
	virtual ~IScene();

	//シーン番号のゲッター
	int GetSceneNo();


	//各シーンにキー入力用のセッターを持たせる
	void SetKeys(char* keys, char* preKeys);

};

