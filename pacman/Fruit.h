#pragma once
#include "GameObject.h"

const int MovesDisappear = 6;
//enum class Direction { Up_F, Down_F, Left_F, Right_F };
class Fruit : public GameObject
{
public:
    Fruit();
    void setStartPos(GameBoard board[][SizeCol]);
    void setScore();
    void setAppear();
    void updateStatus(GameBoard board[][SizeCol]);
    void setMovesAppear();
    
    bool checkAppear() const;
   
    void Print() const;
    void Movement(GameBoard board[][SizeCol]);

private:
    bool _appear;
    int _scoreNum;
    int _moves;
    int _movesAppear;
    Direction _direction;
};

