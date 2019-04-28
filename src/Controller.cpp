#include "Controller.h"
#include <iostream>
#include <algorithm>

static bool row_check(const std::vector<char>::const_iterator& start,
                      const std::vector<char>::const_iterator& end,
                      char symbol) {
    return std::all_of(start,
                       end,
    [symbol] (char c) {  return c == symbol;});
}

static bool col_check(const std::vector<char>::const_iterator& start,
                      const std::vector<char>::const_iterator& end,
                      char symbol) {
    int count = 0;

    for (auto iter = start; iter < end; iter += 3) {
        if (*iter == symbol) { ++count;}
    }

    return count == 3;
}

static bool diagonal_check(const std::vector<char>& board_vec,
                           char symbol) {
    if (board_vec[0] == symbol &&
        board_vec[4] == symbol &&
        board_vec[8] == symbol
       ) {return true;}

    if (board_vec[2] == symbol &&
        board_vec[4] == symbol &&
        board_vec[6] == symbol
       ) {return true;}

    return false;
}

static bool has_won(const Board& board, const IPlayer& curr) {
    const std::vector<char> board_vec = board.CurrentState();

    for (int i = 0; i < 3; ++i) {
        if (row_check(board_vec.begin() + (3 * i),
                      board_vec.begin() + (3 * (i + 1)),
                      curr.Symbol())) { return true;}

        if (col_check(board_vec.begin() + i,
                      board_vec.end(),
                      curr.Symbol())) { return true;}
    }

    return diagonal_check(board_vec, curr.Symbol());
}

Controller::Controller(IPlayer& player1, IPlayer& player2, IRenderer& renderer)
    : player1{player1}, player2{player2}, renderer{renderer} {}

void Controller::PlayGame() {
    for (std::size_t count = 1; count <= 9; ++count) {
        IPlayer& curr = (count & 1) ? player1 : player2;
        board.OccupyPosition(curr.TakeTurn(board.FreePositions()),
                             curr);
        renderer.RenderBoard(board.CurrentState());

        if (has_won(board, curr)) {
            if (curr.Symbol() == player1.Symbol()) {
                std::cout << "Player 1 wins!\n";
                return;
            } else if (curr.Symbol() == player2.Symbol()) {
                std::cout << "Player 2 wins!\n";
                return;
            }
        }
    }

    std::cout << "No winner!\n";
}
