#pragma once
#include "IScene.h"
#include "Vector2.h"
class StageScene : public IScene
{
public:
	void Init() override;
	void Update()override;
	void Draw()override;
	int GameClose()override;
private:

	Vector2 playerPos;
	bool isShot;
	Vector2 bulletPos;


	Vector2 enemyPos;
	bool isAlive;

};