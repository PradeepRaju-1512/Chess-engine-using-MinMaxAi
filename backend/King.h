#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(Color c, int r, int c_pos) : Piece(c, r, c_pos) {}
    char getSymbol() const override { return color == Color::WHITE ? 'K' : 'k'; }
    std::vector<std::pair<int, int>> getValidMoves(const Board& board) const override;
};

#endif