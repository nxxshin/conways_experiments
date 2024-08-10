#include "include/raylib.h"

struct cell {
    int positionX;
    int positionY;
    int radius;
    Color color;
    Vector2 position;
};

struct cell create_cell(int positionX, int positionY, int radius, Color color) {
    struct cell c;
    c.positionX = positionX;
    c.positionY = positionY;
    c.radius = radius;
    c.color = color;
    return c;
}

void draw_cell(struct cell c) {
    DrawCircle(c.positionX, c.positionY, c.radius, c.color);
}

void move_cell(struct cell *c) {
    c->positionX += GetRandomValue(-1,1);
    c->positionY += GetRandomValue(-1,1);
}

void spawn_cell(struct cell cells[], int numCells, int radius, Color color) {
        // DrawCircle(centerX + GetRandomValue(-1000, 1000), centerY + GetRandomValue(-1000, 1000), radius, color); 
       
        for (int i = 0; i < numCells; i++) {
            int posX = 1920 / 2 + GetRandomValue(-100,100);
            int posY = 1080 / 2 + GetRandomValue(-100,100);
            cells[i] = create_cell(posX, posY, radius, color);
        }
       
    }

void check_collisions(struct cell *a, struct cell *b) {
    Vector2 positionA = {a->positionX, a->positionY};
    Vector2 positionB = {b->positionX, b->positionY};
     
    if (CheckCollisionCircles(positionA, a->radius, positionB, b->radius)) {
        a->positionX += GetRandomValue(-4,8);
        a->positionY += GetRandomValue(-8,4);
        b->positionX += GetRandomValue(-10,10);
        b->positionY += GetRandomValue(-10,10);
    }
}

