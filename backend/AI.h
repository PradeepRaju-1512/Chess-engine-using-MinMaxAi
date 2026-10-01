#ifndef AI_H
#define AI_H

#include "Board.h"
#include <utility>

class AI {
private:
    Color aiColor;
    
    // Matrix evaluation function to score the board state[cite: 2]
    int evaluateBoard(const Board& board) const;
    
    // Minimax algorithm for move generation[cite: 2]
    int minimax(Board& board, int depth, bool isMaximizingPlayer, int alpha, int beta);

public:
    AI(Color color);
    
    // Returns the best move as pairs of coordinates: {{startRow, startCol}, {endRow, endCol}}
    std::pair<std::pair<int, int>, std::pair<int, int>> getBestMove(Board& board, int depth);
};

#endif