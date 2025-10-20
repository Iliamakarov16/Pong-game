#include "Ball.hpp"
#include <iostream>

Ball::Ball() : x_(GetScreenWidth() / 2), y_(GetScreenHeight() / 2), speed_x_(7), speed_y_(7), radius_(20){
}

Ball::Ball(const double& x, const double& y,const float& speed_x, const float& speed_y, const int& radius) : x_(x), y_(y), speed_x_(speed_x), speed_y_(speed_y), radius_(radius){
}

void Ball::draw(Color color){
        DrawCircle(x_, y_, radius_, color);
}

void Ball::update(Paddle& player, CpuPaddle& cpu){//Updates position
    x_ += speed_x_;
    y_ += speed_y_;
    if (y_ + radius_ >= GetScreenHeight() || y_ - radius_ <= 0) {
            speed_y_ = -speed_y_;
    }
    else if (x_ + radius_ >= GetScreenWidth() - 15){
        speed_x_ = -speed_x_; 
        cpu.score_++;
        resetBall();
    }
    else if (x_ - radius_ <= 15){
        speed_x_ = -speed_x_;
        player.score_++;
        resetBall();
    }
}
void Ball::onCollision(Paddle& player, CpuPaddle& cpu){
    if (CheckCollisionCircleRec({x_, y_}, radius_, {player.x_, player.y_, player.width_, player.height_})) {
            speed_x_ = -speed_x_;
            speed_x_ *= 1.1;
            speed_y_ *= 1.1;
            std::cout << "Speed x: " << speed_x_ << " y: " << speed_y_;
    }

    if (CheckCollisionCircleRec({x_, y_}, radius_, {cpu.x_, cpu.y_, cpu.width_, cpu.height_})) {
            speed_x_ = -speed_x_;
            speed_x_ *= 1.1;
            speed_y_ *= 1.1;
    }
}

void Ball::resetBall(){
    x_ = GetScreenWidth() / 2;
    y_ = GetScreenHeight() / 2;
    speed_x_ = 7;
    speed_y_ = 7;
}


