#include "CpuPaddle.hpp"
#include "Ball.hpp"

CpuPaddle::CpuPaddle() {
    x_ = 10;
    y_ = GetScreenHeight() / 2;
    width_ = 25;
    height_ = 120;
    speed_ = 10;
}

CpuPaddle::CpuPaddle(const float& x, const float& y,const float& width, const float& height, const int& speed) {
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
    speed_ = speed;
}

void CpuPaddle::update(Ball& ball){

    if (y_ + height_ / 2 >= ball.y_){//Moves up when ball is higher than paddle
        y_ -= speed_;
    }
    else if (y_ + height_ / 2 <= ball.y_){//Moves down when ball is lower than paddle
        y_ += speed_;
    }
    limitMovement();
}