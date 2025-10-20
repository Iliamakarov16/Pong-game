#pragma once
#include "include/raylib.h"
#include "Paddle.hpp"

class Ball;

class CpuPaddle : public Paddle{
public:
    CpuPaddle();
    CpuPaddle(const float& x, const float& y,const float& width, const float& height, const int& speed);
    void update(Ball& ball);//Updates position
};
