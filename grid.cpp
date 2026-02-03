#include <iostream>
#include <raylib.h>
#include "grid.hpp"


void Grid::Draw() {
    for(int row=0; row<rows; row++) {
        for(int column=0; column<columns; column++) {
            //if 1(true) then color it with green else gray
            Color color = cells[row][column] ? Color{GREEN} : Color{29, 29, 29, 255};

            //it takes for args: col, row, width, height and color. 
            //as we need our cells to be grid not just a single coordinate point, we mutiply the coordinate by cell_size
            //width-1 and height-1 to see the borders, change the background color in main.cpp to see it
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

void Grid::Noise() {
    for(int row=0; row<rows; row++) {
        for(int column=0; column<columns; column++) {
            int random_value = GetRandomValue(0, 4);
            cells[row][column] = (random_value == 4) ? 1 : 0; //assign 1(cell being alive at the start) only if random_value is 4  
        }
    }
}

void Grid::Clear() {
    for (int row=0; row<rows; row++) {
        for (int column=0; column<columns; column++) {
            cells[row][column] = 0;
        }
    }
}

void Grid::TogleCell(int row, int column) {
    if (IsWithinBounds(row, column)) {
        cells[row][column] = !cells[row][column]; //inverse it's current state
    }
}
