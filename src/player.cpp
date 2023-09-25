#include<stdlib.h>
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

#include<player.h>

//Constructor
Player::Player()
{
    _currentPlayer = _players::Opponent;
};

//Destructor
Player::~Player()
{
    
};

//Getters
_players Player::getCurrentPlayer()
{
    return _currentPlayer;
};

//Setters
void Player::switchPlayer()
{
    if (_currentPlayer == _players::User)
    {
        _currentPlayer = _players::Opponent;
    }
    else
    {
        _currentPlayer = _players::User;
    }
};

//Supporting Functions
int heuristicFunction(char board[3][3])
{
    //Check rows and columns for victory of either player
    for(int idx=0; idx<3; idx++)
    {
        if((board[idx][0] == board[idx][1] && board[idx][0] == board[idx][2]) || 
        (board[0][idx] == board[1][idx] && board[0][idx] == board[2][idx]))
        {
            if(board[idx][0]=='X' || board[0][idx]=='X')
            {
                return -10;
            }
            else if(board[idx][0]=='O' || board[0][idx]=='O')
            {
                return 10;
            }
        }
    }
    //Check diagonals for victory of either player
    if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || 
    (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
    {
        if(board[0][0]=='X' || board[0][2]=='X')
        {
            return -10;
        }
        else if(board[0][0]=='O' || board[0][2]=='O')
        {
            return 10;
        }
    }
    //Neither player has won yet
    return 0;
};

int miniMax(char board[3][3], int depth, bool opponentMove)
{
    int bestMoveScore = heuristicFunction(board);
    if(opponentMove)
    {
        bestMoveScore = -1000;  //Set a baseline score to improve upon
        //Explore all available positions 
        for(int i=0; i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                //If the position is empty
                if(!(board[i][j]=='X' || board[i][j]=='O'))
                {
                    //Make a hypothetical move
                    auto tempBoard = board;
                    tempBoard[i][j] = 'O';
                    //Explore outcome by recursive function call
                    bestMoveScore = max(bestMoveScore,miniMax(tempBoard, depth+1, !opponentMove));
                }
            }
        }
    }
    else
    {
        bestMoveScore = 1000;
        for(int i=0; i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                //If the position is empty
                if(!(board[i][j]=='X' || board[i][j]=='O'))
                {
                    //Make a hypothetical move for the user
                    auto tempBoard = board;
                    tempBoard[i][j] = 'X';
                    //Explore outcome by recursive function call
                    bestMoveScore = max(bestMoveScore,miniMax(tempBoard, depth+1, !opponentMove));

                }
            }
        }
    }
    return bestMoveScore;
};

int findBestMove(char board[3][3])
{
    //Algorithm inspired by Ref. [1]
    int bestVal = -1000;
    int bestMove;
    char tempBoard[3][3];
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            //If the position is empty
            if(!(board[i][j]=='X' || board[i][j]=='O'))
            {
                auto tempBoard = board;
                tempBoard[i][j] = 'X';
                int moveVal = miniMax(board, 0, true); //Explore this move by calling Player::minMax recursively
                if(moveVal > bestVal)
                {
                    bestVal = moveVal;
                    bestMove = (i*3 + j + 1);     //Determine which of the spots 1-9 this move corresponds to
                }
            }
        }
    }
    return bestMove;
};

//Supporting Methods
int Player::takeTurn(char board[3][3])
{
    //_tempBoardState = board;
    if(_currentPlayer = _players::User)
    {
        cout << "Your move: ";
        cin >> _move;
    }
    else
    {
        _move = findBestMove(board);
    }
    return _move;
};
