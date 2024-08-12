#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "grid_config.h"



struct cell {
    int posX;
    int posY;
    int width;
    int height;
    Color color;
    bool on;
  
};

   
struct cell create_cell(int posX, int posY, int width, int height, Color color, bool on) {
    struct cell c;
    c.posX = posX;
    c.posY = posY;
    c.width = width;
    c.height = height;
    c.color = color;
    c.on = on;
    return c;
}

void draw_cell(struct cell c) {
    c.color = c.on ? c.color : BLACK;
    DrawRectangle(c.posX, c.posY, c.width, c.height, c.color);
}


void spawn_grid(struct cell cells[GRID_HEIGHT][GRID_WIDTH]) {
    
    int radius = 10;
    int width = radius;
    int height = radius;
    int posX = 0 + radius;
    int posY = 0 + radius;
    bool on = true;
    Color color = LIGHTGRAY;
      
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            posX = x * width + radius;
            posY = y * height + radius;
            bool on = (rand() % 25 == 5);
            cells[y][x] = create_cell(posX, posY, width, height, color, on);

        }

        }

}


void check_neighbours(struct cell cells[GRID_HEIGHT][GRID_WIDTH]) {

    // A live cell dies if it has fewer than two live neighbors.
    for (int y = 0; y < GRID_HEIGHT - 1; y++){
        for (int x = 0; x < GRID_WIDTH - 1; x++){
    if (cells[y][x].posX == (cells[y][x+1].posX) ) {
            cells[y][x].on = true;
            cells[y][x+1].on = true;
        }
    // else if (cells[y][x].posY == cells[y+1][x].posY) {
    //         cells[y][x].on = true;
    //         cells[y+2][x].on = true;
    //     }
    }
    }

    // A live cell with two or three live neighbors lives on to the next generation.

    // A live cell with more than three live neighbors dies.

    // A dead cell will be brought back to live if it has exactly three live neighbors.
}