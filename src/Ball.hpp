#pragma once
#include "include/raylib.h"
#include "Paddle.hpp"
#include "CpuPaddle.hpp"

class Ball{

public:
    float x_, y_;
    float speed_x_, speed_y_; 
    int radius_;
    Ball();
    Ball(const double& x, const double& y,const float& speed_x, const float& speed_y, const int& radius);
    void draw(Color color);
    void update(Paddle& player, CpuPaddle& cpu);//Updates position
    void onCollision(Paddle& player, CpuPaddle& cpu);
    void resetBall();
};