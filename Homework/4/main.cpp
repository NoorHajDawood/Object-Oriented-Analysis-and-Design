#include "GameController.h"
#include "TicTacToeRandom.h"
#include "TicTacToeEducated.h"

int main(int argc, char const *argv[])
{
    BoardGameUI *ui = new ConsoleUI();
    GameController controller(ui);
    controller.play();
    return 0;
}
