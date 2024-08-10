gcc conways_shaders.c -o conways_game_of_life_shaders.exe -std=c99 -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
.\conways_game_of_life_shaders.exe