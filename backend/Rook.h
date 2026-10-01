#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(Color c, int r, int c_pos) : Piece(c, r, c_pos) {}
    char getSymbol() const override { return color == Color::WHITE ? 'R' : 'r'; }
    std::vector<std::pair<int, int>> getValidMoves(const Board& board) const override;
};

#endif