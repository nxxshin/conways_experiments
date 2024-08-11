#include <raylib.h>

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
    if (c.on == false) {
        c.color = BLACK;
    }   
    DrawRectangle(c.posX, c.posY, c.width, c.height, c.color); 
}


void check_neighbours(struct cell cells[], int numCells) {
    for (int i = 0; i < numCells; i++) {
        if (cells[i].on == true && cells[i+1].on == false) {
            cells[i].on = true;
        }
        // else if (cells[i].on == true && cells[i+1].on == false) {
        //     cells[i].on = false;
        // }

        // else if (cells[i].on == true && cells[i-1].on == true) {
        //     cells[i].on = false;
        // }

        // else if (cells[i].on == false && cells[i+1].on == true) {
        //     cells[i].on = true;
        // }

        // else if (cells[i].on == false && cells[i+3].on == true) {
        //     cells[i].on = true;
        //     cells[i+3].on = false;
        // }
    }
    
}

void spawn_grid(struct cell cells[], int numCells) {

    int radius = 7;
    int width = radius;
    int height = radius;
    int posX = 0 + radius;
    int posY = 0 + radius;
    bool on = false;
    Color color = LIGHTGRAY;

      
    for (int i = 0; i < numCells; i++) {
        if (posX < 800) {
            // create double array for [x] and [y] positions
            cells[i] = create_cell(posX, posY, width, height, color, on);
            posX += radius;
            if (posX % 5 > 3) {on = !on;}
            else if (posY % 9 > 1) {on = false;}
            
        }
        if (posX > 800) {
            posX = 0;
            posY += radius;
            cells[i] = create_cell(posX, posY, width, height, color, on);
            posX += radius;
            if (posX % 4 > 0) {on = !on;}
            else if (posY % 19 > 0) {on = false;}
           
        }
        
    }

}