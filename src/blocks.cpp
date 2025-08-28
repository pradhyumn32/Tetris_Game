#include "block.h"
#include "position.h"

class LBlock : public Block :: Block{
    public: 
        LBlock(){
            id = 1;
            mpp[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)};
            mpp[1] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};
            mpp[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};
            mpp[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
            Move(0,3);
    } 
};
class JBlock : public Block :: Block{
    public: 
        JBlock(){
            id = 2;
            mpp[0] = {Position(0,0), Position(1,0), Position(1,1), Position(1,2)};
            mpp[1] = {Position(0,1), Position(0,2), Position(1,1), Position(2,1)};
            mpp[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,2)};
            mpp[3] = {Position(0,1), Position(1,1), Position(2,0), Position(2,1)};
            Move(0,3);
    } 
};
class IBlock : public Block :: Block{
    public: 
        IBlock(){
            id = 3;
            mpp[0] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
            mpp[1] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
            mpp[2] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};
            mpp[3] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
            Move(-1,3);
    } 
};
class OBlock : public Block :: Block{
    public: 
        OBlock(){
            id = 4;
            mpp[0] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
            mpp[1] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
            mpp[2] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
            mpp[3] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
            Move(0,4);
            
    } 
};
class SBlock : public Block :: Block{
    public: 
        SBlock(){
            id = 5;
            mpp[0] = {Position(0,1), Position(0,2), Position(1,0), Position(1,1)};
            mpp[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
            mpp[2] = {Position(1,1), Position(1,2), Position(2,0), Position(2,1)};
            mpp[3] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
            Move(0,3);
    } 
};
class TBlock : public Block :: Block{
    public: 
        TBlock(){
            id = 6;
            mpp[0] = {Position(0,1), Position(1,0), Position(1,1), Position(1,2)};
            mpp[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,1)};
            mpp[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,1)};
            mpp[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,1)};
            Move(0,3);
    } 
};