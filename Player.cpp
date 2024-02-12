#include "Player.h"
#include "Novice.h"
Player::Player() {

}

void Player::Initilize() {
	this->pos_ = { 640.0f,360.0f };
	this->speed_ = 2.0f;
}

void Player::Update() {

}

void Player::Draw() {
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, 20, 20, 0.0f, BLACK, kFillModeSolid);
}


void Player::MoveRight() {
	this->pos_.x += this->speed_;
}

void Player::MoveLeft() {
	this->pos_.x -= this->speed_;
}