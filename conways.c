#include "include/raylib.h"
#include "cell.c"
#define NUM_CELLS 200


int main(void)
{
    // Initialization
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    float positionX = screenWidth / 2;
    float positionY = screenHeight / 2;
    float radius = 2;
    Color color = RAYWHITE;


    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

    struct cell myCell = create_cell(300, 300, radius, color);

    struct cell cells[NUM_CELLS];
    spawn_cell(cells, NUM_CELLS, radius, color);

    SetTargetFPS(60); 

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        for (int i = 0; i < NUM_CELLS; i++) {
            for (int j = i + 1; j < NUM_CELLS; j++) {
                check_collisions(&cells[i], &cells[j]);
            }
        }
        
        // TODO: Update your variables here
         move_cell(&myCell);
        
        // Draw
      
        BeginDrawing();

            ClearBackground(BLACK);


            for (int i = 0; i < NUM_CELLS; i++) {
            draw_cell(cells[i]); // Draw each cell
            move_cell(&cells[i]);
        }
            DrawFPS(10, 10);

        
          
        EndDrawing();
      
    }

    CloseWindow(); 
    return 0;
}