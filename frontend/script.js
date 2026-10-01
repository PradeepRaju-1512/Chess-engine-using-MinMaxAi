const boardElement = document.getElementById('chessboard');

function createBoard() {
    for (let row = 0; row < 8; row++) {
        for (let col = 0; col < 8; col++) {
            const square = document.createElement('div');
            square.classList.add('square');
            
            // Math to determine alternating light/dark squares
            if ((row + col) % 2 === 0) {
                square.classList.add('light');
            } else {
                square.classList.add('dark');
            }
            
            // Store grid coordinates in HTML data attributes for easy access
            square.dataset.row = row;
            square.dataset.col = col;
            
            // Temporary click listener to test the highlight CSS
            square.addEventListener('click', () => {
                document.querySelectorAll('.square').forEach(s => s.classList.remove('highlight'));
                square.classList.add('highlight');
                console.log(`Clicked square at Row: ${row}, Col: ${col}`);
            });
            
            boardElement.appendChild(square);
        }
    }
}

// Initialize the visual board
createBoard();