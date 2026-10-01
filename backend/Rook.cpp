#include "Rook.h"
#include "Board.h"

std::vector<std::pair<int, int>> Rook::getValidMoves(const Board& board) const {
    std::vector<std::pair<int, int>> moves;
    
    // Rooks move in 4 straight directions: Up, Down, Left, Right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 

    for (int i = 0; i < 4; ++i) {
        int r = row + directions[i][0];
        int c = col + directions[i][1];
        
        // Continue sliding in the given direction until hitting the edge or a piece
        while (r >= 0 && r < 8 && c >= 0 && c < 8) {
            Piece* target = board.getPiece(r, c);
            if (target == nullptr) {
                moves.push_back({r, c}); // Empty square
            } else {
                if (target->getColor() != this->color) {
                    moves.push_back({r, c}); // Capture enemy piece
                }
                break; // Stop sliding past any piece
            }
            r += directions[i][0];
            c += directions[i][1];
        }
    }
    return moves;
}