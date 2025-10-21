#include "CpuPaddle.hpp"
#include "Ball.hpp"

CpuPaddle::CpuPaddle() : Paddle(10, GetScreenHeight() / 2, 25, 120, 10) {
}

CpuPaddle::CpuPaddle(const float& x, const float& y,const float& width, const float& height, const int& speed)
: Paddle(x, y, width, height, speed) {}


void CpuPaddle::update(Ball& ball){

    if (target_y + height / 2 >= ball.y){//Moves up when ball is higher than paddle
        target_y -= speed;
    }
    else if (target_y + height / 2 <= ball.y){//Moves down when ball is lower than paddle
        target_y += speed;
    }

    y = lerp(y, target_y, 0.2f);//Smoothing cpu's movement
    limitMovement();//limits movement to screen bounds
}
float CpuPaddle::lerp(float start, float end, float t) {
    return start + (end - start) * t;
}