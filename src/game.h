#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game{
    public:
        Game();
        ~Game();
        void Draw();
        void handleInput();
        void moveBlockDown();
        bool gameOver;
        int score;
        Music music;
        
        
        
    private:
        std:: vector <Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Grid grid;
        bool isBlockOutside();
        Block getRandomBlock();
        std::vector<Block> getAllBlocks();
        void moveBlockLeft();
        void moveBlockRight();
        void rotateBlock();
        void lockBlock();
        bool blockFits();
        void Reset();
        void updateScore(int linesCleared, int moveDownPts);
        Sound rotateSound;
        Sound clearSound;


};