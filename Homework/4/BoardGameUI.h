#pragma once
#include "BoardGame.h"
#include <string>
#include <vector>
#include <memory>

class BoardGameUI
{
public:
    virtual void displayBoard(GameState *) = 0;
    virtual Move getPlayerMove() = 0;
    virtual void printString(string) = 0;
    virtual void initialize() = 0;
    virtual int gameSelect(vector<unique_ptr<BoardGame*>> &games) = 0;
};
