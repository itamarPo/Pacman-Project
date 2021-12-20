#pragma once
#include "GameObject.h"

const int MovesDisappear = 12;
class Fruit : public GameObject
{
public:
    Fruit();
    void setStartPos(const int& maxRow, const int& maxCol, vector<vector<GameBoard>>& board);
    void setScore();
    void setAppear();
    void updateStatus(const int& maxRow, const int& maxCol, vector<vector<GameBoard>>& board);
    void setMovesAppear();
    void Eaten();
    
    bool checkAppear() const;
    int getScore() const;

    void Print() const;

private:
    bool _appear;
    int _scoreNum;
    int _moves;
    int _movesAppear;
};

