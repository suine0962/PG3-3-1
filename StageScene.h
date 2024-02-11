﻿#pragma once
#include "IScene.h"
#include "Vector2.h"
class StageScene : public IScene
{
public:
	void Initilize() override;
	void Update()override;
	void Draw()override;
	int GameClose()override;
private:

	Vector2 playerPos_;
	bool isShot_;
	Vector2 bulletPos_;


	Vector2 enemyPos_;
	bool isAlive_;

};