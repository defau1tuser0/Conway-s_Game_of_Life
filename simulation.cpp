#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value) {
    grid.SetValue(row, column, value);
}

int Simulation::CountAliveNeighbour(int row, int column) {
    int alive_neighbour = 0;

    std::vector<std::pair<int, int>> neighbour_offsets = {
        {-1, 0},   //up
        {1, 0},    //down
        {0, -1},   //left
        {0, 1},    //right
        {-1, -1},  //left up
        {-1, 1},   //right up
        {1, -1},   //left down
        {1, 1}     //right down
    };

    for(const auto& offset: neighbour_offsets) {
        // TOROIDAL GRID: the neighbour of last cell is first cell and vice versa
        // new_cell = (row + offset + total_rows) % total_rows == remainder which implements TOROIDAL GRID
        int neighbour_row = (row + offset.first + grid.GetRows()) % grid.GetRows(); 
        int neighbour_column = (column + offset.second + grid.GetColumns()) % grid.GetColumns();

        alive_neighbour += grid.GetValue(neighbour_row, neighbour_column); //add all the alive neighbour to get total alive neighbour
    }

    return alive_neighbour;
}

void Simulation::Update() {
    if (IsRunning()) {
        for(int row=0; row<grid.GetRows(); row++) {
            for(int column=0; column<grid.GetColumns(); column++) {
                int alive_neighbours = CountAliveNeighbour(row, column);
                int cell_value = grid.GetValue(row, column);

                if(cell_value==1) {
                    if(alive_neighbours>3 || alive_neighbours<2) {
                        temp_grid.SetValue(row, column, 0);  //dies because of either overpopulation or loneliness
                    }
                    else {
                        temp_grid.SetValue(row, column, 1); //if has only 2-3 alive neighbours it stays alive peacefully
                    }
                }
                else {
                    if(alive_neighbours == 3) {
                        temp_grid.SetValue(row, column, 1); //if has 3 alive neighbours it comes to life *MAGIC
                    }
                    else {
                        temp_grid.SetValue(row, column, 0); //stays dead
                    }
                }
                
            }
        }
        grid = temp_grid;
    }
}

void Simulation::ClearGrid() {
    if (!IsRunning()) {
        grid.Clear();
    }
}

void Simulation::CreateRandomState() {
    if (!IsRunning()) {
        grid.Noise();
    }
}
