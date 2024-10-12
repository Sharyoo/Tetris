#ifndef SQUARE_H
#define SQUARE_H
#include "Square.h"
#endif

Square::Square(int x, int y, std::vector<std::vector<int>>* matrix) {
    leftX = x;
    leftY = y;
    rotation = 0;
    val = 1;
    boardMatrix = matrix;
    boardWidth = (*matrix)[0].size();
    boardHeight = (*matrix).size();
}

void Square::spawn() {
    (*boardMatrix)[leftY][leftX] = val;
    (*boardMatrix)[leftY][leftX+1] = val;
    (*boardMatrix)[leftY+1][leftX] = val;
    (*boardMatrix)[leftY+1][leftX+1] = val;
}

bool Square::canSpawn() {
    if ((*boardMatrix)[leftY][leftX] == 0 &&
        (*boardMatrix)[leftY][leftX + 1] == 0 &&
        (*boardMatrix)[leftY + 1][leftX] == 0 &&
        (*boardMatrix)[leftY + 1][leftX + 1] == 0) {
            return true;
    }
    return false;
}

void Square::remove() {
    (*boardMatrix)[leftY][leftX] = 0;
    (*boardMatrix)[leftY][leftX+1] = 0;
    (*boardMatrix)[leftY+1][leftX] = 0;
    (*boardMatrix)[leftY+1][leftX+1] = 0;
}

void Square::moveDown() {
    if (canMoveDown()) {
        remove();
        leftY++;
        spawn();
    }
}

void Square::moveLeft() {
    if (canMoveLeft()) {
        remove();
        leftX -= 1;
        spawn();
    }
}

void Square::moveRight() {
    if (canMoveRight()) {
        remove();
        leftX += 1;
        spawn();
    }
}

void Square::rotate() {

}

bool Square::canMoveDown() {
    if ((leftY + 1) + 1 < boardHeight) {
        if ((*boardMatrix)[leftY + 2][leftX] == 0) {
            if ((*boardMatrix)[leftY + 2][leftX + 1] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool Square::canMoveLeft() {
    if (leftX - 1 >= 0) {
        if ((*boardMatrix)[leftY][leftX - 1] == 0) {
            if ((*boardMatrix)[leftY + 1][leftX - 1] == 0) {
                return true;
            }

        }
    }
    return false;
}

bool Square::canMoveRight() {
    if ((leftX + 1) + 1 < boardWidth) {
        if ((*boardMatrix)[leftY][leftX + 2] == 0) {
            if ((*boardMatrix)[leftY + 1][leftX + 2] == 0) {
                return true;
            }
        }
    }
    return false;
}