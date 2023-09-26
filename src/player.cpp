#include<stdlib.h>
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

#include<player.h>

using namespace std;

//Constructor
Player::Player()
{
    _currentPlayer = _players::User; //Value will be switched on first run through game loop
};

//Destructor
Player::~Player(){};

//Getters
_players Player::getCurrentPlayer()
{
    return _currentPlayer;
};

//Setters
void Player::switchPlayer()
{
    _currentPlayer == _players::User ? _currentPlayer = _players::Opponent : _currentPlayer = _players::User;
};

//Supporting Functions
int heuristicFunction(vector<vector<char>> board)
{
    //Heuristic function inspired by Ref [2]
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
    //Checking for a draw
    bool remainingMoves = false; //Assume there are no more ways to win until one is found
    for(auto mark : {'O','X'}) //Check for both user and opponent
    {
        for(int idx=0; idx<3; idx++)
        {
            vector<char> row = board[idx];
            vector<char> col = {board[0][idx],board[1][idx],board[2][idx]};
            if((find(row.begin(),row.end(),mark) == row.end()) || (find(col.begin(),col.end(),mark) == col.end()))
            {
                remainingMoves = true;
            }
        }
        vector<char> diag1 = {board[0][0],board[1][1],board[2][2]};
        vector<char> diag2 = {board[0][2],board[1][1],board[2][0]};
        if((find(diag1.begin(),diag1.end(),mark) == diag1.end()) || (find(diag2.begin(),diag2.end(),mark) == diag2.end()))
        {
            remainingMoves = true;
        }
    }
    if(remainingMoves==false)
    {
        return -5;
    }
    //Neither player has won yet
    return 0;
};

int miniMax(vector<vector<char>> & board, int depth, bool opponentMove)
{
    int bestMoveScore = heuristicFunction(board);
    switch(bestMoveScore)
    {
        case(10): return bestMoveScore - depth; //Win, adjusted by the number of moves required to get there
        case(-10): return bestMoveScore + depth; //Loss, adjusted by the number of moves required to get there
        case(-5): return bestMoveScore + depth; //Draw
        default: {} //Otherwise, continue to explore additional moves
    }
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
                    board[i][j] = 'O';
                    //Explore outcome by recursive function call
                    bestMoveScore = max(bestMoveScore,miniMax(board, depth+1, !opponentMove));
                }
            }
        }
        return bestMoveScore;
    }
    else
    {
        bestMoveScore = 1000;
        //Explore all available positions
        for(int i=0; i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                //If the position is empty
                if(!(board[i][j]=='X' || board[i][j]=='O'))
                {
                    //Make a hypothetical move for the user
                    board[i][j] = 'X';
                    //Explore outcome by recursive function call
                    bestMoveScore = min(bestMoveScore,miniMax(board, depth+1, !opponentMove));

                }
            }
        }
        return bestMoveScore;
    }
};

int findBestMove(vector<vector<char>>& board)
{
    //Algorithm inspired by Ref. [3]
    int bestScore = -1000;
    int bestMove;
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            //If the position is empty
            if(!(board[i][j]=='X' || board[i][j]=='O'))
            {
                auto tempBoard = board;
                tempBoard[i][j] = 'O';
                int moveScore = miniMax(tempBoard, 0, false); //Explore this move by calling Player::minMax recursively
                //This routine is only entered if it is the opponent's move, so the next expected move would be the user's
                if(moveScore > bestScore)
                {
                    bestScore = moveScore;
                    bestMove = (i*3 + j + 1);     //Determine which of the spots 1-9 this move corresponds to
                }
            }
        }
    }
    return bestMove;
};

//Supporting Methods
int Player::takeTurn(vector<vector<char>> board)
{
    if(_currentPlayer == _players::User)
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
