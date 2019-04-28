#pragma once

#include <vector>
#include "BoardPosition.h"
#include "interface/IPlayer.h"

class Board {
public:
    Board();
    const std::vector<BoardPosition> FreePositions() const noexcept;
    void OccupyPosition(const BoardPosition& pos, const IPlayer& player);
    const std::vector<char> CurrentState() const noexcept;
private:
    std::vector<char> board;
};
