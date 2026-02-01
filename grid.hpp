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
        bool IsWithinBounds(int row, int column); //check if coordinates are correct
        void SetValue(int row, int column, int value);
        int GetValue(int row, int column);
        int GetRows() {return rows;}
        int GetColumns() {return columns;}
        void Noise(); //random noise/value
};