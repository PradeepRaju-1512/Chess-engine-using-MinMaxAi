#include "AI.h"
#include <algorithm>
#include <limits>
#include <vector>

AI::AI(Color color) : aiColor(color) {}

int AI::evaluateBoard(const Board& board) const {
    int score = 0;
    // Matrix evaluation based on piece values
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            Piece* p = board.getPiece(r, c);
            if (p) {
                int pieceValue = 0;
                char symbol = p->getSymbol();
                if (symbol == 'P' || symbol == 'p') pieceValue = 10;
                if (symbol == 'N' || symbol == 'n') pieceValue = 30;
                if (symbol == 'B' || symbol == 'b') pieceValue = 30;
                if (symbol == 'R' || symbol == 'r') pieceValue = 50;
                if (symbol == 'Q' || symbol == 'q') pieceValue = 90;
                if (symbol == 'K' || symbol == 'k') pieceValue = 900;

                // Center control bonus can be expanded here[cite: 2]
                
                if (p->getColor() == Color::WHITE) score += pieceValue;
                else score -= pieceValue;
            }
        }
    }
    return score;
}

int AI::minimax(Board& board, int depth, bool isMaximizingPlayer, int alpha, int beta) {
    if (depth == 0) {
        return evaluateBoard(board);
    }

    if (isMaximizingPlayer) {
        int maxEval = std::numeric_limits<int>::min();
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                Piece* p = board.getPiece(r, c);
                if (p && p->getColor() == Color::WHITE) {
                    std::vector<std::pair<int, int>> moves = p->getValidMoves(board);
                    for (auto move : moves) {
                        // Simulate move
                        Piece* captured = board.getPiece(move.first, move.second);
                        board.movePiece(r, c, move.first, move.second);
                        
                        int eval = minimax(board, depth - 1, false, alpha, beta);
                        
                        // Undo move (Requires proper undo logic in Board class for a full engine)
                        board.movePiece(move.first, move.second, r, c);
                        if (captured) {
                            // Restore captured piece (Simplified logic)
                        }

                        maxEval = std::max(maxEval, eval);
                        alpha = std::max(alpha, eval);
                        if (beta <= alpha) break;
                    }
                }
            }
        }
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                Piece* p = board.getPiece(r, c);
                if (p && p->getColor() == Color::BLACK) {
                    std::vector<std::pair<int, int>> moves = p->getValidMoves(board);
                    for (auto move : moves) {
                        // Simulate move
                        Piece* captured = board.getPiece(move.first, move.second);
                        board.movePiece(r, c, move.first, move.second);
                        
                        int eval = minimax(board, depth - 1, true, alpha, beta);
                        
                        // Undo move
                        board.movePiece(move.first, move.second, r, c);
                        
                        minEval = std::min(minEval, eval);
                        beta = std::min(beta, eval);
                        if (beta <= alpha) break;
                    }
                }
            }
        }
        return minEval;
    }
}

std::pair<std::pair<int, int>, std::pair<int, int>> AI::getBestMove(Board& board, int depth) {
    int bestVal = (aiColor == Color::WHITE) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    std::pair<std::pair<int, int>, std::pair<int, int>> bestMove = {{-1, -1}, {-1, -1}};

    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            Piece* p = board.getPiece(r, c);
            if (p && p->getColor() == aiColor) {
                std::vector<std::pair<int, int>> moves = p->getValidMoves(board);
                for (auto move : moves) {
                    // Simulate
                    board.movePiece(r, c, move.first, move.second);
                    
                    int moveVal = minimax(board, depth - 1, aiColor == Color::BLACK, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                    
                    // Undo
                    board.movePiece(move.first, move.second, r, c);

                    if (aiColor == Color::WHITE && moveVal > bestVal) {
                        bestVal = moveVal;
                        bestMove = {{r, c}, {move.first, move.second}};
                    } else if (aiColor == Color::BLACK && moveVal < bestVal) {
                        bestVal = moveVal;
                        bestMove = {{r, c}, {move.first, move.second}};
                    }
                }
            }
        }
    }
    return bestMove;
}