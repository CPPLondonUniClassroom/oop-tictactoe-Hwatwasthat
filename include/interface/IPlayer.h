#pragma once

#include <vector>
#include "../BoardPosition.h"

class IPlayer {
public:
    virtual const char Symbol() const = 0;
    virtual const BoardPosition TakeTurn(const std::vector<BoardPosition>& positions) = 0;
};
