#include "TicTacToeEducated.h"
#include <iostream>
void TicTacToeEducated::setComputerMove()
{
    bool flag = false;
    int index;
    for (index = 0; index < state->validLength; ++index)    // check if a move prevents player's win, or causes player to lose
    {
        board[state->validSpots[index]] = 'X';
        winCondition();
        if (state->result == win)   // player wins -> prevent that
        {
            board[state->validSpots[index]] = 'O';
            state->result = valid;
            winCondition();
            flag = true;
            break;
        }
        board[state->validSpots[index]] = 'O';
        winCondition();
        if (state->result == lose)  // player loses -> pick move
        {
            flag = true;
            break;
        }
        board[state->validSpots[index]] = ' ';
        state->result = valid;
    }
    if (!flag)  // no win condition is met, so pick a random available move
    {
        srand(time(nullptr));
        index = rand() % state->validLength;
        board[state->validSpots[index]] = 'O';
        winCondition();
    }
    state->validSpots[index] = state->validSpots[--state->validLength];
};