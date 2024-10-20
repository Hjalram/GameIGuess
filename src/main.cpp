#include <iostream>
#include "raylib/raylib.h"
#include "SpaceMass.hpp"

#define WIDTH 950
#define HEIGHT 650

int main()
{
    InitWindow(WIDTH, HEIGHT, "Game I Guess");
    SetTargetFPS(60);

    SpaceMass jupiter = SpaceMass("./assets/jupiter.png");
    SpaceMass moon = SpaceMass("./assets/moon.png");

    jupiter.mass = 100;
    
    moon.position = (Vector2){400, 700};
    moon.velocity.x = 0;

    jupiter.position = (Vector2){WIDTH/2, HEIGHT/2};

    while (!WindowShouldClose())
    {   
        jupiter.update();

        moon.noticeGravity(jupiter);
        moon.update();

        // Draw phase
        BeginDrawing();
            ClearBackground({0, 0, 0, 255});
            
            jupiter.draw();
            moon.draw();
        EndDrawing();
    }

    jupiter.destroy();
    moon.destroy();

    CloseWindow();

    return 0;
}