#pragma once
#include "IScene.h"

class ClearScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:// メンバ変数


};