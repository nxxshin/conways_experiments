#include <stdio.h>
#include "include/raylib.h"
#include "cell.c"
#define NUM_CELLS 10000


int main(void)
{
    // Initialization

    
    const int screenWidth = 800;
    const int screenHeight = 450;


    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

    struct cell cells[NUM_CELLS];
    spawn_grid(cells, NUM_CELLS);

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

        check_neighbours(cells, NUM_CELLS);
        
        // TODO: Update your variables here

        
        // Draw
      
        BeginDrawing();

            ClearBackground(BLACK);
            

            for (int i = 0; i < NUM_CELLS; i++) {
            draw_cell(cells[i]); // Draw each cell
        }
            DrawFPS(10, 10);

        
          
        EndDrawing();
      
    }

    CloseWindow(); 
    return 0;
}