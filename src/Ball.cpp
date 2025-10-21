#include "Ball.hpp"
#include <iostream>

Ball::Ball() : x(GetScreenWidth() / 2), y(GetScreenHeight() / 2), speed_x(5 * randomizeDirection()), speed_y(5 * randomizeDirection()), radius(20){
    start_speed_x = speed_x;
    start_speed_y = speed_y;
}

Ball::Ball(const double& x, const double& y,const float& speed_x, const float& speed_y, const int& radius) : x(x), y(y), speed_x(speed_x), speed_y(speed_y), radius(radius){
    start_speed_x = speed_x;
    start_speed_y = speed_y;
}

void Ball::draw(Color color){
        DrawCircle(x, y, radius, color);
}

void Ball::update(Paddle& player, CpuPaddle& cpu){//Updates position
    x += speed_x;
    y += speed_y;
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {//Collision with top and bottom screen bounds
            speed_y = -speed_y;
    }
    else if (x + radius >= GetScreenWidth()){//Collision with right screen bound
        speed_x = -speed_x; 
        cpu.score++;
        resetBall();
    }
    else if (x - radius <= 0){//Collision with left screen bound
        speed_x = -speed_x;
        player.score++;
        resetBall();
    }
}
void Ball::onCollision(Paddle& player, CpuPaddle& cpu){
    if (CheckCollisionCircleRec({x, y}, radius, {player.x, player.y, player.width, player.height})) {//Collision with player paddle
            speed_x = -speed_x;
            speed_x *= 1.1f;
            speed_y *= 1.1f;
    }

    if (CheckCollisionCircleRec({x, y}, radius, {cpu.x, cpu.y, cpu.width, cpu.height})) {//Collision with CPU paddle
            speed_x = -speed_x;
            speed_x *= 1.1f;
            speed_y *= 1.1f;
    }
}
void Ball::onCollision(Paddle& player, CpuPaddle& cpu, float multiplier){
    if (CheckCollisionCircleRec({x, y}, radius, {player.x, player.y, player.width, player.height})) {
            speed_x = -speed_x;
            speed_x *= multiplier;
            speed_y *= multiplier;

    }

    if (CheckCollisionCircleRec({x, y}, radius, {cpu.x, cpu.y, cpu.width, cpu.height})) {
            speed_x = -speed_x;
            speed_x *= multiplier;
            speed_y *= multiplier;
    }
}

void Ball::resetBall(){//sets ball to the middle of the screen with randomized direction
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    speed_x = start_speed_x * randomizeDirection();
    speed_y = start_speed_x * randomizeDirection();
}

float Ball::randomizeDirection(){//randomizes ball direction
    srand(static_cast<unsigned int>(time(0)));
    return rand() % 2 == 0 ? -1.0f : 1.0f;//randomizes between -1 and 1
}
