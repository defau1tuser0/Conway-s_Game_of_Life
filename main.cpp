#include <raylib.h>
#include <iostream>
#include <string>
#include "simulation.hpp"

int main() {
    std::string window_width;
    std::string window_height;
    std::cout << "Enter the width of simulation screen(press Enter for default 1200): ";
    std::getline(std::cin, window_width);
    std::cout << "Enter the height of simulation screen(press Enter for default 800): ";
    std::getline(std::cin, window_height);

    int new_window_width;
    int new_window_height;
    //if input is empyt(Enter key) set the value to default
    if (window_width.empty() || window_height.empty()) {
        new_window_width = 1200;
        new_window_height = 800;
    }
    else { //else change the strong to int
        new_window_width = std::stoi(window_width);
        new_window_height = std::stoi(window_height);
    }
    
    
    //minimum size should be 500
    const int WINDOW_WIDTH = (new_window_width<300)? 300 : new_window_width;
    const int WINDOW_HEIGHT = (new_window_height<300)? 300 : new_window_height;
    std::cout << "Window Width: " << WINDOW_WIDTH << std::endl;
    std::cout << "Window Height: " << WINDOW_HEIGHT << std::endl;

    int cell_size;
    std::cout << "Enter the size of cells: ";
    std::cin >> cell_size;
    const int CELL_SIZE = (cell_size<=1)? 2 : cell_size;
    int cell_count;
    std::cout << "Cell Size: " << CELL_SIZE << std::endl;
    std::cout << "Cell Count: " << int(WINDOW_HEIGHT * WINDOW_WIDTH) / CELL_SIZE << std::endl;

    int FPS = 12;

    //Color GREY = {29, 29, 29, 255};
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE}; //Drawing of grid

    //Simulation Loop
    while(WindowShouldClose() == false) {
        // 1. Event handling
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition(); //the the mouse cursor position
            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;
            simulation.ToggleCell(row, column);
        }
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
        else if (IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState();
        }
        else if (IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
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

