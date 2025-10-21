#pragma once
#include "include/raylib.h"
#include "Paddle.hpp"

class Ball;

class CpuPaddle : public Paddle{
public:
    float target_x, target_y;
    CpuPaddle();
    CpuPaddle(const float& x, const float& y,const float& width, const float& height, const int& speed);
    void update(Ball& ball);//Updates position
    float lerp(float start, float end, float t);//linear interpolation (smoothing movement function)
};
