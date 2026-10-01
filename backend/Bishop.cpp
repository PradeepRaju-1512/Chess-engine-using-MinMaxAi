#include "Bishop.h"
#include "Board.h"

std::vector<std::pair<int, int>> Bishop::getValidMoves(const Board& board) const {
    std::vector<std::pair<int, int>> moves;
    
    // Bishops move in 4 diagonal directions
    int directions[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; 

    for (int i = 0; i < 4; ++i) {
        int r = row + directions[i][0];
        int c = col + directions[i][1];
        
        while (r >= 0 && r < 8 && c >= 0 && c < 8) {
            Piece* target = board.getPiece(r, c);
            if (target == nullptr) {
                moves.push_back({r, c});
            } else {
                if (target->getColor() != this->color) {
                    moves.push_back({r, c});
                }
                break; 
            }
            r += directions[i][0];
            c += directions[i][1];
        }
    }
    return moves;
}