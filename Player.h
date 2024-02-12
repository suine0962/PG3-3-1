#pragma once
#include "Vector2.h"

class Player
{
private:
	Vector2 pos_;
	float speed_;


public:
	Player();

	void Initilize();
	void Update();
	void Draw();

	// キーごとにコマンドを作る
	void MoveRight();
	void MoveLeft();

};