#include "Line.h"

Line::Line(int x, int y, std::vector<std::vector<int>>* matrix) {
    leftX = x;
    leftY = y;
    rotation = 0;
    val = 2;
    boardMatrix = matrix;
    boardWidth = (*matrix)[0].size();
    boardHeight = (*matrix).size();
}

void Line::spawn() {

    if (rotation == 0) {
        (*boardMatrix)[leftY][leftX] = val;
        (*boardMatrix)[leftY][leftX + 1] = val;
        (*boardMatrix)[leftY][leftX + 2] = val;
        (*boardMatrix)[leftY][leftX + 3] = val;
    }
    else if (rotation == 1) {
        (*boardMatrix)[leftY][leftX] = val;
        (*boardMatrix)[leftY + 1][leftX] = val;
        (*boardMatrix)[leftY + 2][leftX] = val;
        (*boardMatrix)[leftY + 3][leftX] = val;
    }
    else if (rotation == 2) {
        (*boardMatrix)[leftY][leftX] = val;
        (*boardMatrix)[leftY][leftX - 1] = val;
        (*boardMatrix)[leftY][leftX - 2] = val;
        (*boardMatrix)[leftY][leftX - 3] = val;
    }
    else if (rotation == 3) {
        (*boardMatrix)[leftY][leftX] = val;
        (*boardMatrix)[leftY - 1][leftX] = val;
        (*boardMatrix)[leftY - 2][leftX] = val;
        (*boardMatrix)[leftY - 3][leftX] = val;
    }
}

bool Line::canSpawn() {
    if (rotation == 0) {
        if ((*boardMatrix)[leftY][leftX] == 0 &&
            (*boardMatrix)[leftY][leftX + 1] == 0 &&
            (*boardMatrix)[leftY][leftX + 2] == 0 &&
            (*boardMatrix)[leftY][leftX + 3] == 0) {
                return true;
        }
    }
    else if (rotation == 1) {
        if ((*boardMatrix)[leftY][leftX] == 0 &&
            (*boardMatrix)[leftY+1][leftX] == 0 &&
            (*boardMatrix)[leftY+2][leftX] == 0 &&
            (*boardMatrix)[leftY+3][leftX] == 0) {
            return true;
        }
    }
    else if (rotation == 2) {
        if ((*boardMatrix)[leftY][leftX] == 0 &&
            (*boardMatrix)[leftY][leftX - 1] == 0 &&
            (*boardMatrix)[leftY][leftX - 2] == 0 &&
            (*boardMatrix)[leftY][leftX - 3] == 0) {
            return true;
        }
    }
    else if (rotation == 3) {
        if ((*boardMatrix)[leftY][leftX] == 0 &&
            (*boardMatrix)[leftY-1][leftX] == 0 &&
            (*boardMatrix)[leftY-2][leftX] == 0 &&
            (*boardMatrix)[leftY-3][leftX] == 0) {
            return true;
        }
    }
    return false;
}

void Line::remove() {
    if (rotation == 0) {
        (*boardMatrix)[leftY][leftX] = 0;
        (*boardMatrix)[leftY][leftX + 1] = 0;
        (*boardMatrix)[leftY][leftX + 2] = 0;
        (*boardMatrix)[leftY][leftX + 3] = 0;
    }
    else if (rotation == 1) {
        (*boardMatrix)[leftY][leftX] = 0;
        (*boardMatrix)[leftY + 1][leftX] = 0;
        (*boardMatrix)[leftY + 2][leftX] = 0;
        (*boardMatrix)[leftY + 3][leftX] = 0;
    }
    else if (rotation == 2) {
        (*boardMatrix)[leftY][leftX] = 0;
        (*boardMatrix)[leftY][leftX - 1] = 0;
        (*boardMatrix)[leftY][leftX - 2] = 0;
        (*boardMatrix)[leftY][leftX - 3] = 0;
    }
    else if (rotation == 3) {
        (*boardMatrix)[leftY][leftX] = 0;
        (*boardMatrix)[leftY - 1][leftX] = 0;
        (*boardMatrix)[leftY - 2][leftX] = 0;
        (*boardMatrix)[leftY - 3][leftX] = 0;
    }
}

void Line::moveDown() {
    if (canMoveDown()) {
        if (rotation == 0 || rotation == 2 || rotation == 3) {
            remove();
            leftY += 1;
            spawn();
        }
        else if (rotation == 1) {
            remove();
            leftY += 1;
            spawn();
        }
    }
}

void Line::moveLeft() {
    if (canMoveLeft()) {
        if (rotation == 0 || rotation == 1 || rotation == 3) {
            remove();
            leftX -= 1;
            spawn();
        }
        else if (rotation == 2) {
            remove();
            leftX -= 1;
            spawn();
        }
    }
}

void Line::moveRight() {
    if (canMoveRight()) {
        if (rotation == 0) {
            remove();
            leftX++;
            spawn();
        }
        else if (rotation == 1 || rotation == 2 || rotation == 3) {
            remove();
            leftX++;
            spawn();
        }
    }
}

void Line::rotate() {
    if (rotation == 0) {
        if (leftY - 1 >= 0 && leftY + 2 < boardHeight) {
            remove();
            leftY -= 1;
            leftX += 2;
            rotation += 1;
            spawn();
        }
    }
    else if (rotation == 1) {
        if (leftX + 1 < boardWidth && leftX - 2 >= 0) {
            remove();
            leftY += 2;
            leftX += 1;
            rotation += 1;
            spawn();
        }
    }
    else if (rotation == 2) {
        if (leftY + 1 < boardHeight && leftY - 2 >= 0) {
            remove();
            leftY += 1;
            leftX -= 2;
            rotation += 1;
            spawn();
        }
    }
    else if (rotation == 3) {
        if (leftX + 2 < boardWidth && leftX - 1 >= 0) {
            remove();
            leftY -= 2;
            leftX -= 1;
            rotation = 0;
            spawn();
        }
    }
}

bool Line::canMoveDown() {
    if (rotation == 0) {
        if (leftY + 1 < boardHeight) {
            if ((*boardMatrix)[leftY + 1][leftX] == 0 &&
                (*boardMatrix)[leftY + 1][leftX+1] == 0 &&
                (*boardMatrix)[leftY + 1][leftX+2] == 0 &&
                (*boardMatrix)[leftY + 1][leftX+3] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 1) {
        if ((leftY + 3) + 1 < boardHeight) {
            if ((*boardMatrix)[leftY + 4][leftX] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 2) {
        if (leftY + 1 < boardHeight) {
            if ((*boardMatrix)[leftY + 1][leftX] == 0 &&
                (*boardMatrix)[leftY + 1][leftX - 1] == 0 &&
                (*boardMatrix)[leftY + 1][leftX - 2] == 0 &&
                (*boardMatrix)[leftY + 1][leftX - 3] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 3) {
        if (leftY + 1 < boardHeight) {
            if ((*boardMatrix)[leftY + 1][leftX] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool Line::canMoveLeft() {
    if (rotation == 1 || rotation == 3) {
        if (leftX - 1 >= 0) {
            if ((*boardMatrix)[leftY][leftX - 1] == 0 &&
                (*boardMatrix)[leftY + 1][leftX - 1] == 0 &&
                (*boardMatrix)[leftY + 2][leftX - 1] == 0 &&
                (*boardMatrix)[leftY + 3][leftX - 1] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 0) {
        if (leftX - 1 >= 0) {
            if ((*boardMatrix)[leftY][leftX - 1] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 2) {
        if ((leftX - 3) - 1 >= 0) {
            if ((*boardMatrix)[leftY][leftX - 4] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool Line::canMoveRight() {
    if (rotation == 1 || rotation == 3) {
        if (leftX + 1 < boardWidth) {
            if ((*boardMatrix)[leftY][leftX + 1] == 0 &&
                (*boardMatrix)[leftY + 1][leftX + 1] == 0 &&
                (*boardMatrix)[leftY + 2][leftX + 1] == 0 &&
                (*boardMatrix)[leftY + 3][leftX + 1] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 0) {
        if ((leftX + 3) + 1 < boardWidth) {
            if ((*boardMatrix)[leftY][leftX + 4] == 0) {
                return true;
            }
        }
    }
    else if (rotation == 2) {
        if (leftX + 1 < boardWidth) {
            if ((*boardMatrix)[leftY][leftX + 1] == 0) {
                return true;
            }
        }
    }
    return false;
}