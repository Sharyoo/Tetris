#include <string>
#include <vector>

#ifndef SHAPES_H
#define SHAPES_H
#include "Shapes.h"
#endif

class Square : public Shapes {
public:

    Square(int x, int y, std::vector<std::vector<int>>* boardMatrix);
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