#include "game.h"
#include <random>
#include "block.h"

Game:: Game(){
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("Sounds/rotate.mp3");
    clearSound = LoadSound("Sounds/clear.mp3");
};

Game :: ~Game(){
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
    
}

std :: vector<Block> Game :: getAllBlocks(){
    return {LBlock(), JBlock(), IBlock(), OBlock() ,SBlock()};
};

Block Game :: getRandomBlock(){
    if(blocks.empty()){
        blocks = getAllBlocks();
    }
    int randomIndex = rand()%blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin()+randomIndex);
    return block;
};

void Game ::  Draw(){
    grid.Draw();
    currentBlock.Draw(11,11);
    switch (nextBlock.id)
    {
    case 3:
        /* code */
        nextBlock.Draw(255,290);
        break;
    case 4:
        nextBlock.Draw(255,280);
        break;
    default:
        nextBlock.Draw(270,270);
        break;
    }
}

void Game::handleInput(){
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed != 0){
        gameOver = false;
        Reset();
    }
    switch(keyPressed){
        case KEY_LEFT:
            moveBlockLeft();
            break;
        case KEY_RIGHT:
            moveBlockRight();
            break;
        case KEY_DOWN:
            moveBlockDown();
            updateScore(0,1);
            break;
        case KEY_UP:
            rotateBlock();
            break;
    }
}

void Game :: moveBlockLeft(){
    if(!gameOver){
    currentBlock.Move(0,-1);
    if(isBlockOutside()|| blockFits() == false) currentBlock.Move(0,1);
}
}
void Game :: moveBlockRight(){
    if(!gameOver){
    currentBlock.Move(0,1);
    if(isBlockOutside()|| blockFits() == false) currentBlock.Move(0,-1);}
}
void Game :: moveBlockDown(){
    if(!gameOver){
    currentBlock.Move(1,0);
    if(isBlockOutside() || blockFits() == false){
        currentBlock.Move(-1,0);
        lockBlock();
    }
}
}

void Game::lockBlock(){
    std :: vector<Position> tiles =  currentBlock.getCellPositions();
    for(Position item : tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(blockFits() == false){
        gameOver = true;
    }
    nextBlock = getRandomBlock();
    int rowsCleared = grid.clearFullRows();

    if(rowsCleared > 0){ 
        PlaySound(clearSound);
        updateScore(rowsCleared, 0);
    }

}

bool Game::blockFits()
{
    std :: vector <Position> tiles = currentBlock.getCellPositions();
    for(auto item : tiles){
        if(!(grid.isCellEmpty(item.row, item.column))) return false;
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    score = 0;
}

void Game::updateScore(int linesCleared, int moveDownPts)
{
    switch (linesCleared)
    {
    case 1:
        score+=100;
        break;
    case 2:
        score+=300;
        break;
    case 3:
        score+=500;
        break;
    
    default:
        break;
    }
    score += moveDownPts;
}

bool Game::isBlockOutside(){
    std :: vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item: tiles ){
        if(grid.isCellOutside(item.row, item.column)) return true;
    }
    return false;
}

void Game::rotateBlock(){
    currentBlock.rotate();
    if(isBlockOutside()|| blockFits() == false){
        currentBlock.undoRotate();
    }else{
        PlaySound(rotateSound);
    }
}
