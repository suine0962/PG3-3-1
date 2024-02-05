#pragma once
#include "IScene.h"

#include <memory>

#include "Player.h"
#include "Enemy.h"

// ゲームシーン
class StageScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private: //関数
	/// <summary>
	/// 衝突判定と応答
	/// </summary>
	void CheckAllCollisions();

private:// メンバ変数

	// 自キャラ
	std::unique_ptr<Player> player_;

	// 自弾
	std::unique_ptr<PlayerBullet> playerBullet_;

	// 敵キャラ
	std::unique_ptr<Enemy> enemy_ = nullptr;

	bool isEnemyAlive = 1;
};

