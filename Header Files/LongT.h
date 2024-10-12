#include <vector>

#ifndef SHAPES_H
#define SHAPES_H
#include "Shapes.h"
#endif

class LongT : public Shapes {
public:

    LongT(int x, int y, std::vector<std::vector<int>>* matrix);
    void spawn();
    bool canSpawn();
    void remove();
    void moveDown();
    void moveLeft();
    void moveRight();
    void rotate();
    bool canMoveDown();
    bool canMoveLeft();
    bool canMoveRight();
};