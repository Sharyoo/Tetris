#include <vector>
#include <iostream>

class Shapes {

public:

    int leftX;
    int leftY;
    int rotation;
    int val;
    std::vector<std::vector<int>>* boardMatrix;
    int boardWidth;
    int boardHeight;

    virtual void spawn() = 0;
    virtual bool canSpawn() = 0;
    virtual void remove() = 0;
    virtual void moveDown() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void rotate() = 0;
    virtual bool canMoveDown() = 0;
    virtual bool canMoveLeft() = 0;
    virtual bool canMoveRight() = 0;
};