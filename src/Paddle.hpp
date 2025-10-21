#pragma once
#include "include/raylib.h"

class Paddle{
    public:
    float x, y;
    float width, height;
    int speed;
    int score;
    
    Paddle();
    Paddle(const float& pos_x, const float& pos_y,const float& w, const float& h, const int& s);
    void draw();
    void update();//Updates position
    void limitMovement();//Limits movement to screen bounds
};