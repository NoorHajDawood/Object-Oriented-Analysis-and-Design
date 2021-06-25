#pragma once
#include "TicTacToeGame.h"
#include <cstdlib>
#include <ctime>

class TicTacToeRandom : public TicTacToeGame
{
public:
    TicTacToeRandom() : TicTacToeGame() {}
    void setComputerMove();
    virtual string gameName() { return "Tic Tac Toe - Random"; }
};