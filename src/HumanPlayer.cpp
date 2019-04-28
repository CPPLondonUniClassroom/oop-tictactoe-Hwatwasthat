#include "HumanPlayer.h"
#include <iostream>
#include <iterator>
#include <algorithm>

static bool valid_move(const std::vector<BoardPosition>& positions, int pos) {
    return std::any_of(positions.begin(),
                       positions.end(),
    [pos] (BoardPosition position) {
        return static_cast<BoardPosition>(pos) == position;
    });
}

const char HumanPlayer::Symbol() const {
    return this->player_symbol;
}

const BoardPosition HumanPlayer::TakeTurn(const std::vector<BoardPosition>& positions) {
    int player_pos;

    do {
        std::cout << "Positions available:\n";

        std::transform(positions.begin(),
                       positions.end(),
                       std::ostream_iterator<std::string>(std::cout),
        [] (BoardPosition pos) {return BoardPositionString[static_cast<int>(pos)] + "\n";});

        player_pos = 0;
        std::cout << "Please select a position (0 - 8): ";
        std::cin >> player_pos;
    } while (player_pos < 0 ||
             8 < player_pos ||
             !valid_move(positions, player_pos));

    return static_cast<BoardPosition>(player_pos);
}
