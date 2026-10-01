#include "King.h"
#include "Board.h"

std::vector<std::pair<int, int>> King::getValidMoves(const Board& board) const {
    std::vector<std::pair<int, int>> moves;
    
    // Kings move 1 step in any of the 8 directions
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
                            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; 

    for (int i = 0; i < 8; ++i) {
        int r = row + directions[i][0];
        int c = col + directions[i][1];
        
        if (r >= 0 && r < 8 && c >= 0 && c < 8) {
            Piece* target = board.getPiece(r, c);
            if (target == nullptr || target->getColor() != this->color) {
                moves.push_back({r, c});
            }
        }
    }
    return moves;
}