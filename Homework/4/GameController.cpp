#include "GameController.h"

GameController::GameController(BoardGameUI *ui) : ui(ui)
{
    if (!ui)
        throw exception();
    games.reserve(2);
    games.push_back(make_unique<BoardGame *>(new TicTacToeRandom()));
    games.push_back(make_unique<BoardGame *>(new TicTacToeEducated()));
}

void GameController::gameoverCheck(GameState *state)
{
    if (state->result == win)
        ui->printString("You Won, Good Job! ^_^");
    else if (state->result == lose)
        ui->printString("You Lost, Better Luck Next Time >.<");
    else if (state->result == tied)
        ui->printString("You've Tied, You'll Get 'em Next Time!");
}

void GameController::play()
{
    GameState *state;
    int player = 0, pc = 0, pick = 0;
    ui->initialize();
    do
    {
        // pick game
        pick = ui->gameSelect(games);
        if (!pick)
        {
            ui->printString("Thank You For Playing (~^.^)~");
            break;
        }
        game = *games[pick - 1].get();
        game->initialize();
        state = game->getGameState();

        // ongoing game
        while (true)
        {
            ui->displayBoard(state);
            do  // player's turn
            {
                game->setPlayerMove(ui->getPlayerMove());
            } while (state->result == invalid);
            if (state->result != valid) // game over
            {
                ui->displayBoard(state);
                gameoverCheck(state);
                break;
            }
            game->setComputerMove();    // UI's turn
            if (state->result != valid) // game over
            {
                ui->displayBoard(state);
                gameoverCheck(state);
                break;
            }
        }

        if (state->result == win)
            ++player;
        else if (state->result == lose)
            ++pc;
        ui->printString("Score: You-" + to_string(player) + " PC-" + to_string(pc));    // display score
    } while (pick); // while player wants to keep going
}