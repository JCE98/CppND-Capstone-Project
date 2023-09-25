#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

#include<player.h>

class Board
{
    public:
        //Constructor & Destructor
        Board();
        ~Board();
        //Copy Constructor
        Board(const Board &source);
        //Getters & Setters
        vector<vector<char>> getBoardState() const;
        void updateBoard(int move, Player player);
        bool gameStatus();
        //Supporting Methods
        void displayHeader();
        void displayBoard();
        void displayOutcome(Player player);
    private:
        vector<vector<char>> _boardState;
        bool _gameOver;
        bool _draw;
};
#endif