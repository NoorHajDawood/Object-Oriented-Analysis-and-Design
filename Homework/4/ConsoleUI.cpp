#include "ConsoleUI.h"

void printLines(int columns)
{
    cout << "   ";
    for (int i = 0; i < columns; i++)
    {
        cout << " ---";
    }
    cout << endl;
}

void printNumbers(int columns)
{
    cout << "   ";
    for (int i = 0; i < columns; i++)
    {
        cout << "  " << i + 1 << " ";
    }
    cout << endl;
}

void ConsoleUI::displayBoard(GameState *state)
{
    printString("Input Example: B3");
    printNumbers(state->j);
    printLines(state->j);
    for (int i = 0; i < state->i; i++)
    {
        cout << " " << char('A' + i);
        for (int j = 0; j < state->j; j++)
        {
            cout << " | " << state->board[i * 3 + j];
        }
        cout << " | " << char('A' + i) << endl;
        printLines(state->j);
    }
    printNumbers(state->j);
}

Move ConsoleUI::getPlayerMove()
{
    char c;
    int i;
    cout << "Move: ";
    cin >> c >> i;
    Move move;
    move.x = c - 'A';
    move.y = i - 1;
    return move;
}
void ConsoleUI::printString(string str)
{
    cout << str << endl;
}

void ConsoleUI::initialize()
{
    printString("--------------------------");
    printString("Welcome Player-One ~(^.^~)");
}
int ConsoleUI::gameSelect(vector<unique_ptr<BoardGame*>> &games)
{
    printString("--------------------------");
    printString("Please Pick a Game:");
    printString("0- To Exit");
    int i = 1, pick;
    for (auto& game : games)
    {
        printString(to_string(i++) + "- " + (*game.get())->gameName());
    }
    do
    {
        cout << "Input: ";
        cin >> pick;
    } while (!(0 <= pick && pick < i));
    printString("--------------------------");
    return pick;
}