#pragma once
#include "command.h"
#include<Novice.h>
class InputHandle
{
public:

	ICommand* HandleInput();

	void AssignMoveLeftPressA();
	void AssignMovrRightPressD();

private:

	ICommand* pressKeyD_;
	ICommand* pressKeyA_;

};

