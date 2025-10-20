#include "Paddle.hpp"

Paddle::Paddle() : x_(GetScreenWidth() - 35), y_(GetScreenHeight() / 2), width_(25), height_(120), speed_(10){
}

Paddle::Paddle(const float& x, const float& y,const float& width, const float& height, const int& speed) : x_(x), y_(y), width_(width), height_(height), speed_(speed){
}

void Paddle::draw(){
    DrawRectangleRounded({x_, y_, width_, height_}, 0.8, 0, WHITE);
}
void Paddle::update(){
    if (IsKeyDown(KEY_W)){//Moving up when W is pressed
        y_ -= speed_;
    }
    if (IsKeyDown(KEY_S)){//Moving down when S is pressed
        y_ += speed_;
    }
    limitMovement();
}
void Paddle::limitMovement() {
    if (y_ <= 0) {
        y_ = 0;
    }
    if (y_ + height_ >= GetScreenHeight()) {
        y_ = GetScreenHeight() - height_;
    }
}
