#include "include/raylib.h"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "CpuPaddle.hpp"

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};
int main() {
    //Window set up
    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "Pong game");
    SetTargetFPS(60);

    //Objects initialization
    Ball ball;
    Paddle player;
    CpuPaddle cpu;

    //Game Loop
    while (!WindowShouldClose()){
    BeginDrawing();

    //Updating
    ball.update(player, cpu);
    player.update();
    cpu.update(ball);
    //Checking for collision
    ball.onCollision(player, cpu, 1.2f);

    //Drawing
    ClearBackground(Dark_Green);
    
    //Field drawing
    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
    DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
    DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);

    //Score drawing
    DrawText(TextFormat("%i", cpu.score), screen_width/4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player.score), 3*screen_width/4 - 20, 20, 80, WHITE);
    //Objects drawing
    ball.draw(Yellow);
    player.draw();
    cpu.draw();

    EndDrawing();
    }
    CloseWindow();
    return 0; 
}

