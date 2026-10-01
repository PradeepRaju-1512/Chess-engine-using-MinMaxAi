#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <utility>

// Forward declaration to avoid circular dependency
class Board;

enum class Color { WHITE, BLACK };

class Piece {
protected:
    Color color;
    int row;
    int col;

public:
    Piece(Color c, int r, int c_pos) : color(c), row(r), col(c_pos) {}
    virtual ~Piece() = default;

    Color getColor() const { return color; }
    std::pair<int, int> getPosition() const { return {row, col}; }
    void setPosition(int r, int c) { row = r; col = c; }
    virtual char getSymbol() const = 0; 

    // Pure virtual function enforcing deep inheritance implementation
    virtual std::vector<std::pair<int, int>> getValidMoves(const Board& board) const = 0;
};

#endif