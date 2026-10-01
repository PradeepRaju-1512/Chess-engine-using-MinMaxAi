#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>

class Board {
private:
    Piece* grid[8][8];

public:
    Board();
    ~Board();

    void setupBoard();
    void displayBoard() const;
    bool movePiece(int startRow, int startCol, int endRow, int endCol);
    Piece* getPiece(int row, int col) const;
    bool isSquareOccupied(int row, int col) const;
    bool isPathClear(int startRow, int startCol, int endRow, int endCol) const;



public:
    // ... existing functions ...
    bool movePiece(int startRow, int startCol, int endRow, int endCol);
    void undoMove(int startRow, int startCol, int endRow, int endCol, Piece* capturedPiece);
};
#endif
