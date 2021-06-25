#pragma once
#include "TicTacToeGame.h"
#include <cstdlib>
#include <ctime>

class TicTacToeEducated : public TicTacToeGame
{
public:
    TicTacToeEducated() : TicTacToeGame() {}
    void setComputerMove();
    virtual string gameName() { return "Tic Tac Toe - Educated"; }
};