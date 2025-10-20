#pragma once
#include "include/raylib.h"

class Paddle{
    public:
    float x_, y_;
    float width_, height_;
    int speed_;
    int score_;
    
    Paddle();
    Paddle(const float& pos_x, const float& pos_y,const float& w, const float& h, const int& s);
    void draw();
    void update();//Updates position
    void limitMovement();
};