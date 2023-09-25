#ifndef PLAYER_H
#define PLAYER_H

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
        int takeTurn(vector<vector<char>> board);

    private:
        _players _currentPlayer;
        int _move;
};
#endif