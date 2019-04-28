#include "Board.h"
#include <algorithm>
#include <stdexcept>

Board::Board() : board(9, 0) {}


const std::vector<BoardPosition> Board::FreePositions() const noexcept {
    std::vector<BoardPosition> ret;

    for (auto i = 0; i < board.size(); ++i) {
        if (board[i] == 0) {
            ret.push_back(static_cast<BoardPosition>(i));
        }
    }

    return ret;
}

void Board::OccupyPosition(const BoardPosition& pos, const IPlayer& player) {
    if (pos < BoardPosition::TOP_LEFT || pos > BoardPosition::BOTTOM_RIGHT) {
        throw std::domain_error("Position not a valid BoardPosition\n");
    }

    if (board[static_cast<int>(pos)] != 0) {
        throw std::domain_error("Position provided is occupied\n");
    }

    board[static_cast<int>(pos)] = player.Symbol();
}

const std::vector<char> Board::CurrentState() const noexcept {
    return this->board;
}
