#pragma once
#include "IScene.h"
class TitleScene : public IScene
{
public:
	void Initilize() override;
	void Update()override;
	void Draw()override;
	int GameClose()override;
};