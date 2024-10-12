#include "LongT.h"

LongT::LongT(int x, int y, std::vector<std::vector<int>>* matrix) {
    leftX = x;
    leftY = y;
    rotation = 0;
    val = 6;
    boardMatrix = matrix;
    boardWidth = (*matrix)[0].size();
    boardHeight = (*matrix).size();
}

void LongT::spawn() {
    if (rotation == 0) {
        (*boardMatrix)[leftY][leftX] = val;
        (*boardMatrix)[leftY][leftX + 1] = val;
        (*boardMatrix)[leftY][leftX + 2] = val;
        (*boardMatrix)[leftY - 1][leftX + 1] = val;
    }
    else if (rotation == 1) {
        (*boardMatrix)[leftY][leftX] = val;
        (*boardMatrix)[leftY + 1][leftX] = val;
        (*boardMatrix)[leftY + 2][leftX] = val;
        (*boardMatrix)[leftY + 1][leftX + 1] = val;
    }
    else if (rotation == 2) {
        (*boardMatrix)[leftY][leftX] = val;
        (*boardMatrix)[leftY][leftX - 1] = val;
        (*boardMatrix)[leftY][leftX - 2] = val;
        (*boardMatrix)[leftY + 1][leftX - 1] = val;
    }
    else if (rotation == 3) {
        (*boardMatrix)[leftY][leftX] = val;
        (*boardMatrix)[leftY - 1][leftX] = val;
        (*boardMatrix)[leftY - 2][leftX] = val;
        (*boardMatrix)[leftY - 1][leftX - 1] = val;
    }
}

bool LongT::canSpawn() {
    if (rotation == 0) {
        if ((*boardMatrix)[leftY][leftX] == 0 &&
            (*boardMatrix)[leftY][leftX + 1] == 0 &&
            (*boardMatrix)[leftY][leftX + 2] == 0 &&
            (*boardMatrix)[leftY-1][leftX + 1] == 0) {
            return true;
        }
    }
    else if (rotation == 1) {
        if ((*boardMatrix)[leftY][leftX] == 0 &&
            (*boardMatrix)[leftY + 1][leftX] == 0 &&
            (*boardMatrix)[leftY + 2][leftX] == 0 &&
            (*boardMatrix)[leftY + 1][leftX+1] == 0) {
            return true;
        }
    }
    else if (rotation == 2) {
        if ((*boardMatrix)[leftY][leftX] == 0 &&
            (*boardMatrix)[leftY][leftX - 1] == 0 &&
            (*boardMatrix)[leftY][leftX - 2] == 0 &&
            (*boardMatrix)[leftY+1][leftX - 1] == 0) {
            return true;
        }
    }
    else if (rotation == 3) {
        if ((*boardMatrix)[leftY][leftX] == 0 &&
            (*boardMatrix)[leftY - 1][leftX] == 0 &&
            (*boardMatrix)[leftY - 2][leftX] == 0 &&
            (*boardMatrix)[leftY - 1][leftX-1] == 0) {
            return true;
        }
    }
    return false;
}

void LongT::remove() {
    if (rotation == 0) {
        (*boardMatrix)[leftY][leftX] = 0;
        (*boardMatrix)[leftY][leftX + 1] = 0;
        (*boardMatrix)[leftY][leftX + 2] = 0;
        (*boardMatrix)[leftY - 1][leftX + 1] = 0;
    }
    else if (rotation == 1) {
        (*boardMatrix)[leftY][leftX] = 0;
        (*boardMatrix)[leftY + 1][leftX] = 0;
        (*boardMatrix)[leftY + 2][leftX] = 0;
        (*boardMatrix)[leftY + 1][leftX + 1] = 0;
    }
    else if (rotation == 2) {
        (*boardMatrix)[leftY][leftX] = 0;
        (*boardMatrix)[leftY][leftX - 1] = 0;
        (*boardMatrix)[leftY][leftX - 2] = 0;
        (*boardMatrix)[leftY + 1][leftX - 1] = 0;
    }
    else if (rotation == 3) {
        (*boardMatrix)[leftY][leftX] = 0;
        (*boardMatrix)[leftY - 1][leftX] = 0;
        (*boardMatrix)[leftY - 2][leftX] = 0;
        (*boardMatrix)[leftY - 1][leftX - 1] = 0;
    }
}

void LongT::moveDown() {
    if (canMoveDown()) {
        if (rotation == 0 || rotation == 3) {
            remove();
            leftY++;
            spawn();
        }
        else if (rotation == 1) {
            remove();
            leftY++;
            spawn();
        }
        else if (rotation == 2) {
            remove();
            leftY++;
            spawn();
        }
    }
}

void LongT::moveLeft() {
    if (canMoveLeft()) {
        if (rotation == 0 || rotation == 1) {
            remove();
            leftX--;
            spawn();
        }
        else if (rotation == 2) {
            remove();
            leftX--;
            spawn();
        }
        else if (rotation == 3) {
            remove();
            leftX--;
            spawn();
        }
    }
}

void LongT::moveRight() {
    if (canMoveRight()) {
        if (rotation == 0) {
            remove();
            leftX++;
            spawn();
        }
        else if (rotation == 1) {
            remove();
            leftX++;
            spawn();
        }
        else if (rotation == 2 || rotation == 3) {
            remove();
            leftX++;
            spawn();
        }
    }
}

void LongT::rotate() {
    if (rotation == 0) {
        if (leftY + 1 < boardHeight) {
            remove();
            leftX++;
            leftY--;
            rotation++;
            spawn();
        }
    }
    else if (rotation == 1) {
        if (leftX - 1 >= 0) {
            remove();
            leftX++;
            leftY++;
            rotation++;
            spawn();
        }
    }
    else if (rotation == 2) {
        if (leftY - 1 >= 0) {
            remove();
            leftX--;
            leftY++;
            rotation++;
            spawn();
        }
    }
    else if (rotation == 3) {
        if (leftX + 1 < boardWidth) {
            remove();
            leftX--;
            leftY--;
            rotation = 0;
            spawn();
        }
    }
}

bool LongT::canMoveDown() {
    if (rotation == 0) {
        if (leftY + 1 < boardHeight) {
            if ((*boardMatrix)[leftY + 1][leftX] == 0 &&
                (*boardMatrix)[leftY + 1][leftX + 1] == 0 &&
                (*boardMatrix)[leftY + 1][leftX + 2] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 1) {
        if ((leftY + 2) + 1 < boardHeight) {
            if ((*boardMatrix)[leftY + 3][leftX] == 0 &&
                (*boardMatrix)[leftY + 2][leftX + 1] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 2) {
        if ((leftY + 1) + 1 < boardHeight) {
            if ((*boardMatrix)[leftY + 1][leftX] == 0 &&
                (*boardMatrix)[leftY + 2][leftX - 1] == 0 &&
                (*boardMatrix)[leftY + 1][leftX - 2] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 3) {
        if (leftY + 1 < boardHeight) {
            if ((*boardMatrix)[leftY + 1][leftX] == 0 &&
                (*boardMatrix)[leftY][leftX - 1] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool LongT::canMoveLeft() {
    if (rotation == 0) {
        if (leftX - 1 >= 0) {
            if ((*boardMatrix)[leftY][leftX - 1] == 0 &&
                (*boardMatrix)[leftY - 1][leftX] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 1) {
        if (leftX - 1 >= 0) {
            if ((*boardMatrix)[leftY][leftX - 1] == 0 &&
                (*boardMatrix)[leftY + 1][leftX - 1] == 0 &&
                (*boardMatrix)[leftY + 2][leftX - 1] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 2) {
        if ((leftX - 2) - 1 >= 0) {
            if ((*boardMatrix)[leftY][leftX - 3] == 0 &&
                (*boardMatrix)[leftY + 1][leftX - 2] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 3) {
        if ((leftX - 1) - 1 >= 0) {
            if ((*boardMatrix)[leftY][leftX - 1] == 0 &&
                (*boardMatrix)[leftY - 1][leftX - 2] == 0 &&
                (*boardMatrix)[leftY - 2][leftX - 1] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool LongT::canMoveRight() {
    if (rotation == 0) {
        if ((leftX + 2) + 1 < boardWidth) {
            if ((*boardMatrix)[leftY][leftX + 3] == 0 &&
                (*boardMatrix)[leftY - 1][leftX + 2] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 1) {
        if ((leftX + 1) + 1 < boardWidth) {
            if ((*boardMatrix)[leftY][leftX + 1] == 0 &&
                (*boardMatrix)[leftY + 1][leftX + 2] == 0 &&
                (*boardMatrix)[leftY + 2][leftX + 1] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 2) {
        if (leftX + 1 < boardWidth) {
            if ((*boardMatrix)[leftY][leftX + 1] == 0 &&
                (*boardMatrix)[leftY + 1][leftX] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 3) {
        if (leftX + 1 < boardWidth) {
            if ((*boardMatrix)[leftY][leftX + 1] == 0 &&
                (*boardMatrix)[leftY - 1][leftX + 1] == 0 &&
                (*boardMatrix)[leftY - 2][leftX + 1] == 0) {
                return true;
            }
        }
    }
    return false;
}