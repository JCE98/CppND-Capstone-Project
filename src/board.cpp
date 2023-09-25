#include <stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
#include<board.h>
#include<player.h>

//Constructor
Board::Board()
{
    _gameOver = false;
    _draw = false;
};

//Destructor
Board::~Board(){};

//Copy Constructor
Board::Board(const Board &board)
{
    copy(begin(board._boardState), end(board._boardState), begin(_boardState));
    _gameOver = board._gameOver;
    _draw = board._draw;
};

//Supporting Methods
void Board::displayHeader()
{
    cout<<"tttT I C K -- T A C -- T O E -- G A M Ettt";
    cout<<"nttttFOR 2 PLAYERSnttt";
    cout<<"ntttPLAYER - 1 [X]tPLAYER - 2 [O]nn";
};

void Board::displayBoard()
{
    cout<<"tt     |     |     n";
    cout<<"tt  "<<_boardState[0][0]<<"  | "<<_boardState[0][1]<<"  |  "<<_boardState[0][2]<<" n";
    cout<<"tt_____|_____|_____n";
    cout<<"tt     |     |     n";
    cout<<"tt  "<<_boardState[1][0]<<"  | "<<_boardState[1][1]<<"  |  "<<_boardState[1][2]<<" n";
    cout<<"tt_____|_____|_____n";
    cout<<"tt     |     |     n";
    cout<<"tt  "<<_boardState[2][0]<<"  | "<<_boardState[2][1]<<"  |  "<<_boardState[2][2]<<" n";
    cout<<"tt     |     |     n";
};

void Board::displayOutcome(Player player)
{
    (_draw == true) ? cout<<"nnGAME DRAW!!!nn" : cout<<"nnCongratulations!The" << player.getCurrentPlayer() << " has won the game";
};

auto Board::getBoardState()
{
    return _boardState;
};

void Board::updateBoard(int move, Player player)
{
    //Convert numbered box selected to board grid coordinates
    int row, column;
    switch(move){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    //Determine which mark to apply
    char mark;
    (player.getCurrentPlayer() == _players::User) ? mark = 'X' : mark = 'O';
    //If the spot is not already filled
    if (_boardState[row][column] != 'X' && _boardState[row][column] !='O')
    {
        _boardState[row][column] = mark;
    }
    else
    {
        cout << "Position already filled!n Please choose another!nn";
    }
};

bool Board::gameStatus()
{
    //Checking rows and columns for sets of three
    for(int idx=0; idx<3; idx++)
    {
        if((_boardState[idx][0] == _boardState[idx][1] && _boardState[idx][0] == _boardState[idx][2]) || 
        (_boardState[0][idx] == _boardState[1][idx] && _boardState[0][idx] == _boardState[2][idx]))
        {
            _gameOver = true;
        }
    }
    //Checking diagonals for sets of three
    if((_boardState[0][0] == _boardState[1][1] && _boardState[0][0] == _boardState[2][2]) ||
    (_boardState[0][2] == _boardState[1][1] && _boardState[0][2] == _boardState[2][0]))
    {
        _gameOver = true;
    }
    //Checking for a draw
    bool remainingMoves = false; //Assume there are no more ways to win until one is found
    for(auto mark : {'O','X'}) //Check for both player and opponent
    {
        for(int idx=0; idx<3; idx++)
        {
            vector<char> row = {_boardState[idx][0,1,2]};
            vector<char> col = {_boardState[0,1,2][idx]};
            if((find(row.begin(),row.end(),mark) == row.end()) || (find(col.begin(),col.end(),mark) == col.end()))
            {
                remainingMoves = true;
                return _gameOver;
            }
        }
        vector<char> diag1 = {_boardState[0][0],_boardState[1][1],_boardState[2][2]};
        vector<char> diag2 = {_boardState[0][2],_boardState[1][1],_boardState[2][0]};
        if((find(diag1.begin(),diag1.end(),mark) == diag1.end()) || (find(diag2.begin(),diag2.end(),mark) == diag2.end()))
        {
            remainingMoves = true;
            return _gameOver;
        }
    }
    //If there are no more moves, the game has ended in a draw
    if(remainingMoves==false)
    {
        _gameOver = true;
        _draw = true;
    }
    return _gameOver;
};