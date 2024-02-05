#pragma once
#include "Vector2.h"

class PlayerBullet
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(const Vector2& position, const float& speed);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

public:
	void OnCollision();

	bool IsDead() const { return isDead_; }

	Vector2 GetPosition();

private:

	Vector2 pos;

	float speed_;

	int size_;

	//寿命<frm>
	static const int kLifeTime = 60 * 5;

	//デスタイマー
	int deathTimer_ = kLifeTime;
	//デスフラグ
	bool isDead_ = false;

};
