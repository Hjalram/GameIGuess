#include <iostream>
#include "raylib/raylib.h"

#define WIDTH 600
#define HEIGHT 500

int main()
{
    InitWindow(WIDTH, HEIGHT, "Game I Guess");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground({200, 200, 200, 255});
        EndDrawing();
    }

    CloseWindow();

    return 0;
}