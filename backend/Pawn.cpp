#include "Pawn.h"
#include "Board.h"

std::vector<std::pair<int, int>> Pawn::getValidMoves(const Board& board) const {
    std::vector<std::pair<int, int>> moves;
    
    // Direction depends on color (White moves "up" the board, Black moves "down")
    int direction = (this->color == Color::WHITE) ? -1 : 1;
    
    // 1. Move forward one square
    int forwardRow = row + direction;
    if (forwardRow >= 0 && forwardRow < 8 && board.getPiece(forwardRow, col) == nullptr) {
        moves.push_back({forwardRow, col});
        
        // 2. Move forward two squares (only from starting position)
        int startRow = (this->color == Color::WHITE) ? 6 : 1;
        if (row == startRow) {
            int doubleRow = row + (2 * direction);
            if (board.getPiece(doubleRow, col) == nullptr) {
                moves.push_back({doubleRow, col});
            }
        }
    }
    
    // 3. Diagonal captures
    int captureCols[2] = {col - 1, col + 1};
    for (int i = 0; i < 2; ++i) {
        int c = captureCols[i];
        if (forwardRow >= 0 && forwardRow < 8 && c >= 0 && c < 8) {
            Piece* target = board.getPiece(forwardRow, c);
            if (target != nullptr && target->getColor() != this->color) {
                moves.push_back({forwardRow, c});
            }
        }
    }
    
    return moves;
}