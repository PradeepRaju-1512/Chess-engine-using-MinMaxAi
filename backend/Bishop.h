#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(Color c, int r, int c_pos) : Piece(c, r, c_pos) {}
    char getSymbol() const override { return color == Color::WHITE ? 'B' : 'b'; }
    std::vector<std::pair<int, int>> getValidMoves(const Board& board) const override;
};

#endif