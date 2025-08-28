#include "block.h"

Block :: Block(){
    cellSize = 30;
    rotationState = 0;
    colors = getCellColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block :: Draw(int offsetX, int offsetY){
    std :: vector <Position> tiles = getCellPositions();
    for(Position item : tiles){
        DrawRectangle(item.column*cellSize+offsetX, item.row*cellSize+offsetY, cellSize-1, cellSize-1, colors[id]);
    }
}
void Block::Move(int rows, int column) {
    rowOffset+=rows;
    colOffset+=column;
};

std :: vector<Position> Block:: getCellPositions(){
    std :: vector<Position> tiles = mpp[rotationState];
    std :: vector<Position> movedTiles;
    for(auto it : tiles){
        Position newPos = Position(it.row + rowOffset, it.column + colOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::rotate(){
    rotationState++;
    if(rotationState == (int) mpp.size()) rotationState = 0;
}

void Block::undoRotate(){
    rotationState--;
    if(rotationState  == -1) rotationState = 0;
}
