#pragma once
#include <exception>
#include <string>
using namespace std;

struct Move
{
    int x;
    int y;
};

enum Result
{
    win,
    lose,
    tied,
    valid,
    invalid
};

struct GameState
{
    const char *board = nullptr;    // board state
    int i = 0, j = 0;
    Result result;
    int *validSpots = 0;            // available moves
    int validLength;
};

class BoardGame
{
public:
    virtual void setPlayerMove(Move move) = 0;
    virtual void setComputerMove() = 0;
    virtual GameState *getGameState() = 0;
    virtual string gameName() = 0;
    virtual void initialize() = 0;
    virtual ~BoardGame()
    {
        delete board;
    }
    BoardGame(int i, int j) : board(nullptr), state(nullptr)
    {
        board = new char[i * j];
        state = new GameState();
        if (!board || !state)
            throw bad_alloc();
        state->board = board;
        state->i = i;
        state->j = j;
        state->result = valid;
    }

protected:
    char *board;
    GameState *state;
};
