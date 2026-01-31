#include <raylib.h>
#include "grid.hpp"

int main() {
    const int WINDOW_WIDTH = 900;
    const int WINDOW_HEIGHT = 900;
    const int CELL_SIZE = 10;
    const int FPS = 12;

    Color GREY = {29, 29, 29, 255};
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Grid grid{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};
    grid.SetValue(0, 0, 1); //testing alive cell
    grid.SetValue(25, 16, 1);

    //Simulation Loop
    while(WindowShouldClose() == false) {
        // 1. Event handling

        // 2. Updating state

        // 3. Drawing 
        BeginDrawing();
        ClearBackground(GRAY);
        grid.Draw();
        EndDrawing();
    };

    CloseWindow();
}

