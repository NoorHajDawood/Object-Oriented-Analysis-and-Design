#pragma once
#include "BoardGame.h"
#include "ConsoleUI.h"
#include <memory>
#include <vector>
#include "TicTacToeEducated.h"
#include "TicTacToeRandom.h"

class GameController
{
public:
    GameController(BoardGameUI *ui);
    void play();
private:
    vector<unique_ptr<BoardGame *>> games;
    BoardGame *game;
    BoardGameUI *ui;
    void gameoverCheck(GameState*);
};