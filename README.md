# Conway's Game of Life

Simple simulation of Conway's game of life in c++ with raylib.

### Compile:
```
g++ main.cpp simulation.cpp grid.cpp -o game.exe  -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
```
after compilation, run the game.exe either by running: ```.\game.exe``` or from file explorer.


### Controls:
0. Note that at start every cell in simulation will be __DEAD__
1. Click on the cell to make it Alive or Dead(only when simulation is not running)
2. press __r__ key to set a random state(only when simulation is not running)
3. press __Enter__ to run
4. press __Space__ to pause
5. press __f__ to increase the speed of simulation
6. press __s__ to slow down the speed of simulation
7. press __c__ to clear the screen to 0.


### Special Thanks to Raylib.
Offical Raylib github link: https://github.com/raysan5/raylib  
Official Raylib website link: https://www.raylib.com   
__Thanks Once Again__ 
