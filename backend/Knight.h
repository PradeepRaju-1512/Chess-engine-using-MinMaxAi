#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(Color c, int r, int c_pos) : Piece(c, r, c_pos) {}
    char getSymbol() const override { return color == Color::WHITE ? 'N' : 'n'; }
    std::vector<std::pair<int, int>> getValidMoves(const Board& board) const override;
};

#endif