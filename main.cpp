#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main() {
    const int WINDOW_WIDTH = 900;
    const int WINDOW_HEIGHT = 900;
    const int CELL_SIZE = 30;
    int FPS = 12;
    float key_hold_timer = 0.0f;
    const float DELAY = 0.3f;

    //Color GREY = {29, 29, 29, 255};
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE}; //Drawing of grid

    //Simulation Loop
    while(WindowShouldClose() == false) {
        // 1. Event handling
        if (IsKeyPressed(KEY_ENTER)) { //start
            simulation.Start();
            SetWindowTitle("Game of Life is running ...");
        }
        else if (IsKeyPressed(KEY_SPACE)) { //pause
            simulation.Stop();
            SetWindowTitle("Game of Life PAUSED");
        }
        else if (IsKeyPressed(KEY_F)) { //speed up
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_S)) { //slow down but not less then 5fps
            if (FPS > 5) {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }

        // 2. Updating state
        simulation.Update();

        // 3. Drawing 
        BeginDrawing();
        ClearBackground(BLACK);
        simulation.Draw();
        EndDrawing();
    };

    CloseWindow();
}

