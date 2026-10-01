#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(Color c, int r, int c_pos) : Piece(c, r, c_pos) {}
    char getSymbol() const override { return color == Color::WHITE ? 'Q' : 'q'; }
    std::vector<std::pair<int, int>> getValidMoves(const Board& board) const override;
};

#endif