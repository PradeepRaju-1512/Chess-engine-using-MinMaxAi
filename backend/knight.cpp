#include "Knight.h"
#include "Board.h"

std::vector<std::pair<int, int>> Knight::getValidMoves(const Board& board) const {
    std::vector<std::pair<int, int>> moves;
    
    // The 8 possible L-shaped moves for a knight
    int rowOffsets[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int colOffsets[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; ++i) {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];

        // Check board boundaries
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            Piece* targetSquare = board.getPiece(newRow, newCol);
            // Add move if square is empty or contains an enemy piece
            if (targetSquare == nullptr || targetSquare->getColor() != this->color) {
                moves.push_back({newRow, newCol});
            }
        }
    }
    return moves;
}