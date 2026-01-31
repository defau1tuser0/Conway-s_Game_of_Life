#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main() {
    const int WINDOW_WIDTH = 900;
    const int WINDOW_HEIGHT = 900;
    const int CELL_SIZE = 30;
    const int FPS = 12;

    Color GREY = {29, 29, 29, 255};
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE}; //Drawing of grid
    simulation.SetCellValue(5, 29, 1);
    simulation.SetCellValue(6, 0, 1);
    simulation.SetCellValue(5, 0, 1);
    simulation.SetCellValue(4, 0, 1);

    std::cout << simulation.CountAliveNeighbour(5, 29) << std::endl;

    //Simulation Loop
    while(WindowShouldClose() == false) {
        // 1. Event handling

        // 2. Updating state

        // 3. Drawing 
        BeginDrawing();
        ClearBackground(GRAY);
        simulation.Draw();
        EndDrawing();
    };

    CloseWindow();
}

