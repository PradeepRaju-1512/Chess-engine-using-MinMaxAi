# Chess Engine with Minimax AI

A complete chess game featuring a custom C++ backend and a colorful graphical user interface. This project demonstrates core Object-Oriented Programming (OOP) concepts, algorithmic AI decision-making, and full-stack integration using a local web server.

## Features

* **Deep Inheritance Hierarchy:** Utilizes a `Piece` base class with derived classes for specific pieces like `Knight`, `Rook`, `Pawn`, `Bishop`, `Queen`, and `King`.


* **Polymorphism:** Implements a pure virtual `getValidMoves()` function, forcing each derived piece to calculate its own unique movement rules.


* **Minimax AI Engine:** Calculates future moves using the Minimax algorithm combined with a matrix evaluation function to score the board state.


* **Local Web Server Bridge:** Uses the `cpp-httplib` library to host a local HTTP server that communicates between the native C++ backend and the web browser.


* **Graphical User Interface:** Built with HTML, CSS, and JavaScript to provide a colorful, interactive 8x8 chessboard layout.



## Project Structure

* **`backend/`**: Contains all C++ logic.


* `Piece.h` / `Piece.cpp`: The abstract base class.


* `Knight.h`, `Rook.h`, `Pawn.h`, etc.: Derived piece classes.


* `Board.h` / `Board.cpp`: Manages the 8x8 grid and tracks piece locations.


* `AI.h` / `AI.cpp`: Contains the Minimax algorithm and matrix evaluation.


* `httplib.h`: Single-header web server library.


* `main.cpp`: The core server entry point that hosts the HTTP endpoints.




* **`frontend/`**: Contains the visual interface.


* `index.html`: The structure of the chessboard.


* `style.css`: Visual layout and colors.


* `script.js`: Handles user clicks, board generation, and sends moves to the backend.





## Prerequisites

* A standard C++ compiler (e.g., `g++`).
* A terminal/command-line environment (Linux, macOS, or Windows).

## Installation and Setup

1. **Clone the repository:**
```bash
git clone <YOUR_GITHUB_REPO_URL>
cd ChessProject

```


2. **Compile the C++ backend:**
Run the following command in the root project folder to compile the engine (the `-pthread` flag is required for Linux environments to support the web server):
```bash
g++ backend/*.cpp -o chess_engine -pthread

```


3. **Run the local server:**
Execute the compiled program:
```bash
./chess_engine

```


4. **Play the game:**
Once the terminal successfully prints `Chess Engine Server starting at http://localhost:8080`, leave the terminal running, open a web browser, and navigate to `http://localhost:8080` to view the graphical user interface.
