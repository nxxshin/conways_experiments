#include <stdio.h>
#include "include/raylib.h"
#include "cell.c"
#define NUM_CELLS 200

int main(void)
{
    // Initialization
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

    // Load shader and create render texture
    Shader bloomShader = LoadShader(0, "resources/shaders/bloom.fs");
    if (bloomShader.id == 0) {
        printf("Failed to load shader\n");
        return -1;
    }
    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);

    float radius = 2;
    Color color = WHITE;  // Changed to WHITE for visibility on black background

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
        
        move_cell(&myCell);
        
        // Render to texture
        BeginTextureMode(target);
            ClearBackground(BLACK);
            for (int i = 0; i < NUM_CELLS; i++) {
                draw_cell(cells[i]);
                move_cell(&cells[i]);
            }
          
            DrawFPS(10, 10);
        EndTextureMode();

        // Render to screen with shader
        BeginDrawing();
            ClearBackground(BLACK);
            BeginShaderMode(bloomShader);
                // Draw the render texture to the screen, flipping it vertically
                DrawTextureRec(target.texture, 
                    (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height },
                    (Vector2){ 0, 0 }, WHITE);
            EndShaderMode();
        EndDrawing();
    }

    // Unload resources
    UnloadRenderTexture(target);
    UnloadShader(bloomShader);

    CloseWindow();
    return 0;
}