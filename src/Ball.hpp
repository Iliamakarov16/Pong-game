#pragma once
#include "include/raylib.h"
#include "Paddle.hpp"
#include "CpuPaddle.hpp"
#include <cstdlib>
#include <ctime>

class Ball{

public:
    float x, y;
    float start_speed_x, start_speed_y;
    float speed_x, speed_y; 
    int radius;
    Ball();
    Ball(const double& x, const double& y,const float& speed_x, const float& speed_y, const int& radius);
    void draw(Color color);
    void update(Paddle& player, CpuPaddle& cpu);//Updates position
    void onCollision(Paddle& player, CpuPaddle& cpu);
    void onCollision(Paddle& player, CpuPaddle& cpu, float multiplier);
    void resetBall();
    float randomizeDirection();
};