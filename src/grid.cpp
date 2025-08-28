#include "grid.h"
#include <iostream>
// using namespace std;
#include "colors.h"

Grid::Grid(){
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = getCellColors();
};

void Grid :: Initialize(){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            grid[i][j] = 0;
        }
    }
};

void Grid :: printGrid(){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            std::cout<<grid[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void Grid :: Draw(){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            int cellValue = grid[i][j];
            DrawRectangle(j*cellSize + 11, i*cellSize +11, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column){
    if(row >= 0 && row<numRows && column>=0 && column<numCols) return false;
    return true;
}

bool Grid::isCellEmpty(int row, int column)
{
    if(grid[row][column] == 0) return true;
    return false;
}

int Grid::clearFullRows()
{
    int completedRows = 0;
    for(int row = numRows-1;row>=0;row--){
        if(isRowFull(row)){
            clearRow(row);
            completedRows++;
        }else if(completedRows >0){
            moveRowDown(row,completedRows);
        }
    }
    return completedRows;
}

bool Grid::isRowFull(int row)
{
    // return false;
    for(int col=0;col<numCols;col++){
        if(grid[row][col] == 0) return false;
    }
    return true;
}

void Grid::clearRow(int row)
{
    for(int col = 0;col<numCols;col++){
        grid[row][col] = 0;
    }
}

void Grid::moveRowDown(int rows, int numRowsDown)
{
    for(int col = 0;col<numCols;col++){
        grid[rows + numRowsDown][col] = grid[rows][col];
        grid[rows][col] = 0;
    }
}
