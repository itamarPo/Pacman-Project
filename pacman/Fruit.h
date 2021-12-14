#pragma once
#include "GameObject.h"

const int MovesDisappear = 6;
//enum class Direction { Up_F, Down_F, Left_F, Right_F };
class Fruit : public GameObject
{
public:
    Fruit();
    void setStartPos(vector<vector<GameBoard>> board);
    void setScore();
    void setAppear();
    void updateStatus(vector<vector<GameBoard>> board);
    void setMovesAppear();
    
    bool checkAppear() const;
   
    void Print() const;
    void Movement(vector<vector<GameBoard>> board);

private:
    bool _appear;
    int _scoreNum;
    int _moves;
    int _movesAppear;
    Direction _direction;
};

