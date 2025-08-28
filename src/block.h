#pragma once
#include "colors.h"
#include <vector>
#include <map>
#include "position.h"

class Block{
    public:
        Block();
        int id;
        std :: map<int, std::vector<Position>> mpp;
        void Draw(int offsetX, int offsetY);
        void Move(int rows, int column);
        std::vector<Position> getCellPositions();
        void rotate();
        void undoRotate();

    private:
        int cellSize;
        int rotationState;
        std :: vector<Color> colors;
        int rowOffset, colOffset;
        // Block getRandomBlock();
};