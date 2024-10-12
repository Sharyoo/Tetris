#ifndef BOARD_H
#define BOARD_H
#include "Board.h"
#endif

Board::Board(int width, int height) {
    this->width = width;
    this->height = height;
    this->boardMatrix = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
    for (int i = 0; i < boardMatrix.size(); i++) {
        for (int j = 0; j < boardMatrix[0].size(); j++) {
            boardMatrix[i][j] = 0;
        }
    }
}

std::string Board::toString() {
    std::string ans = "";
    for (int i = 0; i < boardMatrix.size(); i++) {
        ans += "[";
        for (int j = 0; j < boardMatrix[0].size(); j++) {
            if (j != boardMatrix[0].size() - 1) ans += std::to_string(boardMatrix[i][j]) + ", ";
            else ans += std::to_string(boardMatrix[i][j]);
        }
        ans += "]\n";
    }
    return ans;
}

int Board::checkLineClear() {
    for (int row = 0; row < boardMatrix.size(); row++) {
        for (int col = 0; col < boardMatrix.size(); col++) {
            if (boardMatrix[row][col] == 0) break;
            else if (col == width - 1 && boardMatrix[row][col] != 0) return row;
        }
    }
    return -1;
}

int Board::clearLine() {
    int rowToClear = checkLineClear();
    if (rowToClear != -1) {
        if (rowToClear == 0) {
            for (int col = 0; col < width; col++) {
                boardMatrix[rowToClear][col] = 0;
            }
            return 1;
        }
        else {
            int furthestRow = 0;
            for (int col = 0; col < width; col++) {
                boardMatrix[rowToClear][col] = 0;
            }
            for (int row = rowToClear; row > 0; row--) {
                boardMatrix[row] = boardMatrix[row - 1];
            }
            for (int col = 0; col < width; col++) {
                boardMatrix[0][col] = 0;
            }
            return 1;
        }

    }
    else {
        return -1;
    }
}

void Board::clearAllLines() {
    while (true) {
        int x = clearLine();
        if (x == -1) break;
        score++;
    }
}

int Board::findFurthestNonZero(int row, int col) {
    int ans = row;
    for (int r = row + 1; r < height; r++) {
        if (boardMatrix[r][col] == 1) return ans;
        if (boardMatrix[r][col] == 0) ans = r;
    }
    return ans;
}

std::vector<float> appendVector(std::vector<float> v1, std::vector<float> v2);

void Board::findSquares() {
    this->squares = {};
    std::vector<float> currentSquare{};
    for (int i = 0; i < height; i++) {
        currentSquare = {};
        for (int j = 0; j < width; j++) {
            if (boardMatrix[i][j] != 0) {

                if (boardMatrix[i][j] == 1) {
                    currentSquare =
                    {
                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 1.0f, 0.0f, 0.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f) - 50), 1.0f, 0.0f, 0.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 1.0f, 0.0f, 0.0f,

                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 1.0f, 0.0f, 0.0f,
                        (j * 50.0f) + 100, (1000 - (i * 50.0f)), 1.0f, 0.0f, 0.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 1.0f, 0.0f, 0.0f
                    };
                }

                else if (boardMatrix[i][j] == 2) {
                    currentSquare =
                    {
                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 0.0f, 1.0f, 0.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f) - 50), 0.0f, 1.0f, 0.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 0.0f, 1.0f, 0.0f,

                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 0.0f, 1.0f, 0.0f,
                        (j * 50.0f) + 100, (1000 - (i * 50.0f)), 0.0f, 1.0f, 0.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 0.0f, 1.0f, 0.0f
                    };
                }

                else if (boardMatrix[i][j] == 3) {
                    currentSquare =
                    {
                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 0.0f, 0.0f, 1.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f) - 50), 0.0f, 0.0f, 1.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 0.0f, 0.0f, 1.0f,

                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 0.0f, 0.0f, 1.0f,
                        (j * 50.0f) + 100, (1000 - (i * 50.0f)), 0.0f, 0.0f, 1.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 0.0f, 0.0f, 1.0f
                    };
                }

                else if (boardMatrix[i][j] == 4) {
                    currentSquare =
                    {
                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 1.0f, 1.0f, 0.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f) - 50), 1.0f, 1.0f, 0.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 1.0f, 1.0f, 0.0f,

                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 1.0f, 1.0f, 0.0f,
                        (j * 50.0f) + 100, (1000 - (i * 50.0f)), 1.0f, 1.0f, 0.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 1.0f, 1.0f, 0.0f
                    };
                }

                else if (boardMatrix[i][j] == 5) {
                    currentSquare =
                    {
                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 0.0f, 1.0f, 1.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f) - 50), 0.0f, 1.0f, 1.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 0.0f, 1.0f, 1.0f,

                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 0.0f, 1.0f, 1.0f,
                        (j * 50.0f) + 100, (1000 - (i * 50.0f)), 0.0f, 1.0f, 1.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 0.0f, 1.0f, 1.0f
                    };
                }

                else if (boardMatrix[i][j] == 6) {
                    currentSquare =
                    {
                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 1.0f, 0.0f, 1.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f) - 50), 1.0f, 0.0f, 1.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 1.0f, 0.0f, 1.0f,

                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 1.0f, 0.0f, 1.0f,
                        (j * 50.0f) + 100, (1000 - (i * 50.0f)), 1.0f, 0.0f, 1.0f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 1.0f, 0.0f, 1.0f
                    };
                }

                else if (boardMatrix[i][j] == 7) {
                    currentSquare =
                    {
                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 1.0f, 0.5f, 0.25f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f) - 50), 1.0f, 0.5f, 0.25f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 1.0f, 0.5f, 0.25f,

                        (j * 50.0f) + 100, (1000 - (i * 50.0f) - 50), 1.0f, 0.5f, 0.25f,
                        (j * 50.0f) + 100, (1000 - (i * 50.0f)), 1.0f, 0.5f, 0.25f,
                        (j * 50.0f) + 100 + 50, (1000 - (i * 50.0f)), 1.0f, 0.5f, 0.25f
                    };
                }
                this->squares = appendVector(this->squares, currentSquare);
            }
        }
    }
}

void Board::checkGameOver() {

}