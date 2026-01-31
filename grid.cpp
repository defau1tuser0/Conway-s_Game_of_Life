#include <raylib.h>
#include "grid.hpp"


void Grid::Draw() {
    for(int row=0; row<rows; row++) {
        for(int column=0; column<columns; column++) {
            //if 1(true) then color it with green else gray
            Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};

            //it takes for args: col, row, width, height and color. 
            //as we need our cells to be grid not just a single coordinate point, we mutiply the coordinate by cell_size
            //width-1 and height-1 to see the borders
            DrawRectangle(column*cell_size, row*cell_size, cell_size-1, cell_size-1, color);
        }
    }
}

bool Grid::IsWithinBounds(int row, int column) {
    if (row>=0 && row<rows && column>=0 && column<columns) {
        return true;
    }
    return false;
}

void Grid::SetValue(int row, int column, int value) {
    if (IsWithinBounds(row, column)) {
        cells[row][column] = value;
    }
}

int Grid::GetValue(int row, int column) {
    if (IsWithinBounds(row, column)) {
        return cells[row][column];
    }
    return 0;
}
