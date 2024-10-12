#include <vector>

#ifndef SHAPES_H
#define SHAPES_H
#include "Shapes.h"
#endif

class Line : public Shapes {
public:

    Line(int x, int y, std::vector<std::vector<int>>* matrix);
    void spawn() override;
    bool canSpawn();
    void remove() override;
    void moveDown() override;
    void moveLeft() override;
    void moveRight() override;
    void rotate() override;
    bool canMoveDown() override;
    bool canMoveLeft() override;
    bool canMoveRight() override;
};