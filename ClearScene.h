#pragma once
#include "IScene.h"
class ClearScene : public IScene
{
public:
	void Initilize() override;
	void Update()override;
	void Draw()override;
	int GameClose()override;
private:

};