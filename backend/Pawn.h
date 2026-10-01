#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color c, int r, int c_pos) : Piece(c, r, c_pos) {}
    char getSymbol() const override { return color == Color::WHITE ? 'P' : 'p'; }
    std::vector<std::pair<int, int>> getValidMoves(const Board& board) const override;
};

#endif