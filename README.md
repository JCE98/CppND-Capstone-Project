# CppND-Capstone-Project
This is my capstone project for the C++ nanodegree from Udacity. The project is a tic-tac-toe game that can be played in the terminal.

![image](https://github.com/JCE98/CppND-Capstone-Project/assets/143748618/caba7f34-2508-454e-a4af-71a206c9f620)

## Project Overview
The code features a minimax algorithm from game theory as a predictive model to drive the behavior of the computer program opponent. It considers the current state of the board, and explores all possible sequences of moves under the assumption that the user it is facing also plays the game in an optimal manner according to similar principles [3].

The heuristic function used for the algorithm rewards a victory by the computer, and penalizes a loss. To a lesser extent, it also penalizes a draw. One additional element included in the heuristic function is the concept of a finite time horizon. The longer the computer takes to win, the lesser it's reward. This motivates a search for not only a move set that leads to victory, but also one that leads to victory quickly [2].

## Classes
There are two classes utilized in this project: the Board class and the Player class. Below is a breakdown of the methods and attributes associated with each.

Board class
  Attributes:
    _boardState  -  The current state of the board as an array containing the applied markers from the user's and the computer's moves, and numbered spots for any spots that are empty
    _gameOver    -  A flag to indicate that the game has reached a terminal state
    _draw        -  A flag to indicate that the game has ended in a draw
  Methods:
    getBoardState    -  Getter method for the _boardState attribute
    updateBoard      -  Setter that uses information about the most recent move and the player who made it to update the _boardState attribute with the appropriate marker
    gameStatus       -  Setter to check for victory by either player, or a draw, and set the _gameOver and _draw attribute flags appropriately
    displayHeader    -  Display game title header and marker legend in the terminal
    displayBoard     -  Display the current state of the board (_boardState attribute) to the terminal in a graphical way
    displayOutcome   -  Print the outcome of the game to the terminal once the game has ended

Player class
  Attributes:
    _currentPlayer    -  An enum to identify whose turn it is that can take the values User or Opponent
    _move             -  The numbered spot on a 1-9 grid that is selected as the next move
  Methods:
    switchPlayer      -  Setter to toggle the enum _currentPlayer to change whose turn it is
    getCurrentPlayer  -  Getter for the _currentPlayer attribute
    takeTurn          -  Setter to update _move attribute by either prompt the user for a move, or initiate the minimax algorithm for the computer to select a move
  Supporting Functions:
    heuristicFunction -  Defines rewards and penalties for moves that lead to board states
    miniMax           -  Recursively called function that extrapolates moves for both players by comparing the heuristic function scores of all possible moves to select the best move
    findBestMove      -  Wrapper for the minimax algorithm that iterates through all possible first moves based on the _boardState to initiate the algorithm

## File Structure
There are three cpp files and two header files included with this project. The two header files (board.h and player.h) provide the structure for the classes described above. Two of the cpp files (board.cpp and player.cpp) contain the implementation of those classes. The last cpp file (main.cpp) is the primary code run when the program is executed that contains the game loop utilizing these classes to play the game.

![image](https://github.com/JCE98/CppND-Capstone-Project/assets/143748618/3cef043b-fa96-498c-827b-cfada5252fa6)

## Description of Game Loop
The game is started by instantiating a player object and a board object. Both are used in an while loop predicated on the status of the game. The loop ends when the game reaches a terminal state. When the game is first started, the board has boxes labeled 1-9. Each move will replace one of these numbered boxes with the marker from one of the players. Terminal states are defined as a victory (any adjacent three of the same marker) or a draw (no sequences of moves that can lead to victory for either side). On each turn, either the computer will make it's move autonomously, or the user will be prompted to make a move. This cycle continues for the duration of the game. Upon the game reaching a terminal state, the outcome will be printed to the terminal alongside the final state of the board. This ends the program.

## How to Play this Game
1. Clone this repo.
2. Make a build directory in the top level directory: mkdir build && cd build
3. Compile: cmake .. && make
4. Run it: ./tictactoe

## Project Rubric Satisfaction
This project uses several concepts learned in the nanodegree program to demonstrate mastery of the C++ programming language. Below is a breakdown of the rubric items satisfied by this project code.

### README
This README is included with the project that contains instructions on how to build and run the code. There are no additional libraries required.
The project is destribed in detail, including class and file structures, the goal of the project, and the expected behavior in the game loop.
This README contains information on which rubric points were satisfied by this project

### Compiling and Testing
The project compiles and runs without errors

### Loops, Functions, I/O
* The project demonstrates an understanding of C++ functions and control structures.
  This project uses while loops, for loops, conditional statements, switch statements, and the break keyword to control the execution flow of the code
    * While loop at main.cpp:15
    * For loop at player.cpp:37
    * Conditional statement at board.cpp:54
    * Switch statement at board.cpp:80
    * Break keyword at board.cpp:99
  These are just a few examples of these control structures used throughout the code
* The project accepts user input and processes the input.
    * This project accepts user input to select a move on the board. This information is parsed into a private class object that holds the state of the board (see player.cpp:179)
  
### Object Oriented Programming
* The project uses Object Oriented Programming techniques.
    * Per the class structure described above, the project uses classes with attributes to store information and methods to do tasks with that information (see player.cpp and board.cpp).
* Classes use appropriate access specifiers for class members.
    * The header files detail the access specifiers of the class members, private for attributes and public for methods (see player.h:13-25 and board.h:13-30)
* Classes abstract implementation details from their interfaces.
    * The class methods are named in such a way that it is clear what they are intended to do. Comments are also generously placed throughout the code for clarification. For example, the getCurrentPlayer method in the Player class is a getter method for the private _currentPlayer attribute (see player.cpp:21)
* Classes encapsulate behavior.
    * The previous example also satisfies this rubric. The private member attribute is hidden from the user (abstracted), and can only be accessed with the public method. The class structure defined above shows that behaviors related to one another were encapsulated in classes.

### Memory Management
* The project makes use of references in function declarations.
    * Supporting functions in the Player class use pass by reference in the recursive function calls to avoid computationally intensive copies of the board state when exploring all possible moves (see player.cpp:93 and player.cpp:146)
