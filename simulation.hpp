#pragma once
#include "grid.hpp"

class Simulation {
    private:
        Grid grid;
        Grid temp_grid;
        bool run;

    public:
        Simulation(int width, int height, int cell_size):
            //temp_grip for storing grid value that will be assigned to grid after all the grid cells have been checked
            grid(width, height, cell_size), temp_grid(width, height, cell_size), run(false) {}; 

        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountAliveNeighbour(int row, int column);
        void Update(); //checks the cells and their neighbours and updates the grid
        bool IsRunning() {return run;}
        void Start() {run = true;}
        void Stop() {run = false;}
        void ClearGrid();
        void CreateRandomState();
        void ToggleCell(int row, int column);
};