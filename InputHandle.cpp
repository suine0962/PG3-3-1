#include "InputHandle.h"

void InputHandle::AssignMoveLeftPressA()
{
    ICommand* comand = new MoveLeftCommand();
    this->pressKeyD_ = comand;
}

void InputHandle::AssignMovrRightPressD()
{
    ICommand* comand = new MoveRightCommand();
    this->pressKeyA_ = comand;
}


ICommand* InputHandle::HandleInput()
{
    if (Novice::CheckHitKey(DIK_D))
    {
        return pressKeyD_;
    }
    if (Novice::CheckHitKey(DIK_A))
    {
        return pressKeyA_;
    }

    return nullptr;
}


