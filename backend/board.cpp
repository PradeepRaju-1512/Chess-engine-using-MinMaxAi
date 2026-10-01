#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <iostream>

Board::Board() {
    for (int r = 0; r < 8; ++r)
        for (int c = 0; c < 8; ++c)
            grid[r][c] = nullptr;
}

Board::~Board() {
    for (int r = 0; r < 8; ++r)
        for (int c = 0; c < 8; ++c)
            delete grid[r][c];
}

void Board::setupBoard() {
    // Example setup for Knights and Rooks to demonstrate inheritance
    grid[0][1] = new Knight(Color::BLACK, 0, 1);
    grid[0][6] = new Knight(Color::BLACK, 0, 6);
    grid[7][1] = new Knight(Color::WHITE, 7, 1);
    grid[7][6] = new Knight(Color::WHITE, 7, 6);
    
    grid[0][0] = new Rook(Color::BLACK, 0, 0);
    grid[7][0] = new Rook(Color::WHITE, 7, 0);
    
    // Add remaining pieces (Pawns, Bishops, Queens, Kings) following this pattern
}

Piece* Board::getPiece(int row, int col) const {
    if (row >= 0 && row < 8 && col >= 0 && col < 8) return grid[row][col];
    return nullptr;
}

bool Board::movePiece(int startRow, int startCol, int endRow, int endCol) {
    Piece* p = grid[startRow][startCol];
    if (p) {
        // In a full implementation, check if {endRow, endCol} is in p->getValidMoves(*this)
        delete grid[endRow][endCol]; // Capture piece if exists
        grid[endRow][endCol] = p;
        grid[startRow][startCol] = nullptr;
        p->setPosition(endRow, endCol);
        return true;
    }
    return false;
}