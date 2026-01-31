#pragma once
#include <vector>

class Grid {
    private:
        int rows;
        int columns;
        int cell_size;
        std::vector<std::vector<int>> cells; 

    public:
        Grid(int width, int height, int cell_size):
            rows(height/cell_size), 
            columns(width/cell_size), 
            cell_size(cell_size), 
            cells(rows, std::vector<int>(columns, 0)) {}; //put 0 in every column for every row of cells which is 2d vector
        
        void Draw();
        void SetValue(int row, int column, int value);
};