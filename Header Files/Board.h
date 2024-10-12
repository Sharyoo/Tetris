#include <vector>
#include <string>

class Board {
public:
    int width;
    int height;
    std::vector<std::vector<int>> boardMatrix;
    int score = 0;

    std::vector<float> corners
    {
        100.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 0.0f, 0.0f, 0.0f, 0.0f,

        600.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 1000.0f, 0.0f, 0.0f, 0.0f,

        600.0f, 1000.0f, 0.0f, 0.0f, 0.0f,
        100.0f, 1000.0f, 0.0f, 0.0f, 0.0f,
        
        100.0f, 1000.0f, 0.0f, 0.0f, 0.0f,
        100.0f, 0.0f, 0.0f, 0.0f, 0.0f
    };

    std::vector<float> verticalLines
    {
        150.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        150.0f, 1000.0f, 0.0f, 0.0f, 0.0f,

        200.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        200.0f, 1000.0f, 0.0f, 0.0f, 0.0f,

        250.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        250.0f, 1000.0f, 0.0f, 0.0f, 0.0f,

        300.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        300.0f, 1000.0f, 0.0f, 0.0f, 0.0f,

        350.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        350.0f, 1000.0f, 0.0f, 0.0f, 0.0f,

        400.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        400.0f, 1000.0f, 0.0f, 0.0f, 0.0f,

        450.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        450.0f, 1000.0f, 0.0f, 0.0f, 0.0f,
        
        500.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        500.0f, 1000.0f, 0.0f, 0.0f, 0.0f,
         
        550.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        550.0f, 1000.0f, 0.0f, 0.0f, 0.0f
    };

    std::vector<float> horizontalLines
    {
        100.0f, 50.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 50.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 100.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 100.0f, 0.0f, 0.0f, 0.0f,
         
        100.0f, 150.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 150.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 200.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 200.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 250.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 250.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 300.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 300.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 350.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 350.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 400.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 400.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 450.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 450.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 500.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 500.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 550.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 550.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 600.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 600.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 650.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 650.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 700.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 700.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 750.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 750.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 800.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 800.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 850.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 850.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 900.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 900.0f, 0.0f, 0.0f, 0.0f,

        100.0f, 950.0f, 0.0f, 0.0f, 0.0f,
        600.0f, 950.0f, 0.0f, 0.0f, 0.0f
    };

    std::vector<float> squares{};

public:
    Board(int width, int height);
    std::string toString();
    int checkLineClear(); // return -1 if no line clear, row if there is line clear
    int clearLine(); // return -1 for no clear, 1 for clear
    void clearAllLines();
    int findFurthestNonZero(int row, int col); // returns furthest down row that is non-zero and below input row
    void findSquares();
    void checkGameOver();
};