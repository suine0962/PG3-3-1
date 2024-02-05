#pragma once
#include "Vector2.h"
#include "PlayerBullet.h"
#include <list>

class Player
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(char* keys, char* preKeys);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

public:
	std::list<PlayerBullet*> bullets_;

	const std::list<PlayerBullet*>& GetBullets() const { return bullets_; }

	Vector2 GetPosition();

private:
	void Attack();

private:
	const char* keys_;
	const char* preKeys_;

	Vector2 pos;
	int size_ = 30;
};