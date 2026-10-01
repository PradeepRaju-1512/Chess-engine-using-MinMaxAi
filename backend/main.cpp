#include "Board.h"
#include "AI.h"
#include <iostream>

int main() {
    Board gameBoard;
    gameBoard.setupBoard();
    
    AI computer(Color::BLACK);

    std::cout << "Chess Engine Initialized." << std::endl;
    // Game loop logic will go here (waiting for frontend inputs or console commands)

    return 0;
}