#include "Paddle.hpp"

Paddle::Paddle() : x(GetScreenWidth() - 35), y(GetScreenHeight() / 2), width(25), height(120), speed(10){
}

Paddle::Paddle(const float& x, const float& y,const float& width, const float& height, const int& speed) : x(x), y(y), width(width), height(height), speed(speed){
}

void Paddle::draw(){
    DrawRectangleRounded({x, y, width, height}, 0.8, 0, WHITE);
}
void Paddle::update(){
    if (IsKeyDown(KEY_W)){//Moving up when W is pressed
        y -= speed;
    }
    if (IsKeyDown(KEY_S)){//Moving down when S is pressed
        y += speed;
    }
    limitMovement();
}
void Paddle::limitMovement() {
    if (y <= 0) {//Limits movement to upper screen bound
        y = 0;
    }
    if (y + height >= GetScreenHeight()) {//Limits movement to lower screen bound
        y = GetScreenHeight() - height;
    }
}
