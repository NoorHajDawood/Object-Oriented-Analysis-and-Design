#include "TicTacToeRandom.h"

void TicTacToeRandom::setComputerMove() // randomly chosen move from available moves
{
    srand(time(nullptr));
    int index = rand()%state->validLength;
    board[state->validSpots[index]] = 'O';
    state->validSpots[index] = state->validSpots[--state->validLength];
    winCondition();
};