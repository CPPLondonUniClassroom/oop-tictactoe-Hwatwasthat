#include "HumanPlayer.h"
#include "Board.h"
#include "BoardPosition.h"
#include "Controller.h"
#include "Renderer.h"

int main () {
    HumanPlayer Player1('X');
    HumanPlayer Player2('O');
    Renderer renderer;
    Controller controller(Player1, Player2, renderer);
    controller.PlayGame();
    return 0;
}
