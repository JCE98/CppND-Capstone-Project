#include<stdlib.h>
#include<iostream>
#include<vector>
#include<board.h>
#include<player.h>
using namespace std;

int main()
{
    Board gameBoard;
    Player player;

    gameBoard.displayHeader();
    gameBoard.displayBoard();

    while (gameBoard.gameStatus() == false)
    {
        player.switchPlayer();
        int move = player.takeTurn(gameBoard.getBoardState());
        gameBoard.updateBoard(move,player);
        gameBoard.displayHeader();
        gameBoard.displayBoard();
    }

    gameBoard.displayOutcome(player);

    return 0;
};

/*
[1] 'C++ Tic Tac Toe Game Project', STechies.com, 13 Nov 2020, https://www.stechies.com/tic-tac-toe-cpp/
[2] 'Introduction to Evaluation Function of Minimax Algorithm in Game Theory', GeeksForGeeks.org,
https://www.geeksforgeeks.org/introduction-to-evaluation-function-of-minimax-algorithm-in-game-theory/
[3] 'Finding optimal move in Tic-Tac-Toe using Minimax Algorithm in Game Theory', GeeksForGeeks.org,
https://www.geeksforgeeks.org/finding-optimal-move-in-tic-tac-toe-using-minimax-algorithm-in-game-theory/
*/