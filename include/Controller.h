#pragma once

#include "interface/IPlayer.h"
#include "interface/IRenderer.h"
#include "Board.h"

class Controller{
public:
    Controller(IPlayer& player1, IPlayer& player2, IRenderer& renderer);
    void PlayGame();
private:
    IPlayer& player1;
    IPlayer& player2;
    IRenderer& renderer;
    Board board;
};
