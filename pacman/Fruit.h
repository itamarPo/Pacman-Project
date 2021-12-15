#pragma once
#include "GameObject.h"

const int MovesDisappear = 12;
//enum class Direction { Up_F, Down_F, Left_F, Right_F };
class Fruit : public GameObject
{
public:
    Fruit();
    void setStartPos(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board);
    void setScore();
    void setAppear();
    void updateStatus(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board);
    void setMovesAppear();
    void Eaten();
    
    bool checkAppear() const;
    int getScore() const;

    void Print() const;
    //void Movement(vector<vector<GameBoard>> board);

private:
    bool _appear;
    int _scoreNum;
    int _moves;
    int _movesAppear;
};

