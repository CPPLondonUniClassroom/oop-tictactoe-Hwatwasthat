#pragma once

#include "interface/IPlayer.h"

class HumanPlayer : public IPlayer {
public:
    HumanPlayer(const char symbol) : player_symbol{symbol} {};
    const char Symbol() const override;
    const BoardPosition TakeTurn(const std::vector<BoardPosition> & positions) override;
private:
    const char player_symbol;
};
