#pragma once
#include "Vector2.h"

class Enemy
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

	void OnCollision();

public:
	Vector2 GetPosition();

public:
	bool IsDead() const { return isDead_; }

private:
	void RIGHT();

	void LEFT();

private:
	enum class Phase {
		RIGHT, // 接近する
		LEFT,    // 離脱する
	};

	//フェーズ
	Phase phase_ = Phase::RIGHT;

	Vector2 pos;

	float speed_;

	int size_ = 30;

	//デスフラグ
	bool isDead_ = false;
};
