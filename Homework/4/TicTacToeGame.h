#pragma once
#include "BoardGame.h"

class TicTacToeGame : public BoardGame
{
public:
    TicTacToeGame() : BoardGame(3, 3)
    {
        state->validSpots = new int[9];
        if (!state->validSpots)
            throw bad_alloc();
    }

    void setPlayerMove(Move move)
    {
        if (move.x < 0 || move.x >= state->i || move.y < 0 || move.y >= state->j)
        {
            state->result = invalid;
            return;
        }
        int i;
        int m = move.x * 3 + move.y;
        for (i = 0; i < 9; ++i)
        {
            if (state->validSpots[i] == m)
            {
                state->validSpots[i] = state->validSpots[--state->validLength];
                break;
            }
        }
        if (i != 9)
        {
            board[m] = 'X';
            state->result = valid;
            winCondition();
        }
        else
            state->result = invalid;
    }

    GameState *getGameState()
    {
        return state;
    }
    virtual string gameName() = 0;
    virtual void initialize()
    {
        state->validLength = 9;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                board[3 * i + j] = ' ';
                state->validSpots[3 * i + j] = 3 * i + j;
            }
        }
    }
    virtual void setComputerMove() = 0;
    // virtual ~TicTacToeGame() {}
protected:
    void winCondition()
    {
        // check if there's a winner
        if (board[0] == board[1] && board[1] == board[2])
        {
            if (board[0] != ' ')
            {
                if (board[0] == 'X')
                    state->result = win;
                else
                    state->result = lose;
                return;
            }
        }
        if (board[0] == board[3] && board[3] == board[6])
        {
            if (board[0] != ' ')
            {
                if (board[0] == 'X')
                    state->result = win;
                else
                    state->result = lose;
                return;
            }
        }
        if (board[0] == board[4] && board[4] == board[8])
        {
            if (board[0] != ' ')
            {
                if (board[0] == 'X')
                    state->result = win;
                else
                    state->result = lose;
                return;
            }
        }
        if (board[1] == board[4] && board[4] == board[7])
        {
            if (board[1] != ' ')
            {
                if (board[1] == 'X')
                    state->result = win;
                else
                    state->result = lose;
                return;
            }
        }
        if (board[2] == board[4] && board[4] == board[6])
        {
            if (board[2] != ' ')
            {
                if (board[2] == 'X')
                    state->result = win;
                else
                    state->result = lose;
                return;
            }
        }
        if (board[2] == board[5] && board[5] == board[8])
        {
            if (board[2] != ' ')
            {
                if (board[2] == 'X')
                    state->result = win;
                else
                    state->result = lose;
                return;
            }
        }
        if (board[3] == board[4] && board[4] == board[5])
        {
            if (board[3] != ' ')
            {
                if (board[3] == 'X')
                    state->result = win;
                else
                    state->result = lose;
                return;
            }
        }
        if (board[6] == board[7] && board[7] == board[8])
        {
            if (board[6] != ' ')
            {
                if (board[6] == 'X')
                    state->result = win;
                else
                    state->result = lose;
                return;
            }
        }

        // game is over & no winner -> Tie
        if (state->validLength <= 0)
            state->result = tied;
    }
};