#pragma once
#include "BoardGameUI.h"
#include <iostream>

class ConsoleUI : public BoardGameUI
{
public:
    void displayBoard(GameState*);
    Move getPlayerMove();
    void printString(string);
    void initialize();
    int gameSelect(vector<unique_ptr<BoardGame*>> &games);
};