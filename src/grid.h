#pragma once
#include <raylib.h>
#include <vector>

class Grid{
    public:
        Grid();
        void printGrid();
        void Initialize();
        int grid[20][10];
        void Draw();
        bool isCellOutside(int row, int  column);
        bool isCellEmpty(int row, int column);
        int clearFullRows();
    private:
        // std::vector<Color> getCellColors();
        int numRows, numCols;
        int  cellSize;
        std :: vector<Color> colors;
        bool isRowFull(int row);
        void clearRow(int row);
        void moveRowDown(int rows, int numRows);
};
