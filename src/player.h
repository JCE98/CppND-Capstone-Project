#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

enum _players {User,Opponent};

class Player
{
    public:
        //Constructor & Destructor
        Player();
        ~Player();
        //Getters & Setters
        void switchPlayer();
        _players getCurrentPlayer();
        //Supporting Methods
        int takeTurn(char board[3][3]);
        //int heuristicFunction(char board[3][3]);
        //int minMax(char board[3][3], int depth, bool opponentMove);
        //int findBestMove(char board[3][3]);

    private:
        _players _currentPlayer;
        int _move;
        //char _tempBoardState[3][3];
};