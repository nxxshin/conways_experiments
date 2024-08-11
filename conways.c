#include <stdio.h>
#include "include/raylib.h"
#include "cell.c"

#include "grid_config.h"

struct cell grid[GRID_HEIGHT][GRID_WIDTH];


int main(void)
{
    // Initialization

    
    const int screenWidth = 800;
    const int screenHeight = 450;


    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

    struct cell cells[NUM_CELLS];

    srand(time(NULL));
    
    spawn_grid(grid);
    

    SetTargetFPS(60); 

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //for (int i = 0; i < NUM_CELLS; i++) {
        //    for (int j = i + 1; j < NUM_CELLS; j++) {
        //        check_neighbours(&cells[i], &cells[j]);
        //   }
        //}

        // check_neighbours(cells, NUM_CELLS);
        
        // TODO: Update your variables here

        
        // Draw
      
        BeginDrawing();

            ClearBackground(BLACK);
            

        for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            draw_cell(grid[y][x]);
        }
}
            DrawFPS(10, 10);

        
          
        EndDrawing();
      
    }

    CloseWindow(); 
    return 0;
}