#include <vector>

#ifndef SHAPES_H
#define SHAPES_H
#include "Shapes.h"
#endif

class ReverseL : public Shapes {

public:

    ReverseL(int x, int y, std::vector<std::vector<int>>* matrix);
    void spawn();
    bool canSpawn();
    void remove();
    void rotate();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool canMoveDown();
    bool canMoveLeft();
    bool canMoveRight();
};