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
        Board(const Board &board);
        //Getters & Setters
        auto getBoardState();
        void updateBoard(int move, Player player);
        bool gameStatus();
        //Supporting Methods
        void displayHeader();
        void displayBoard();
        void displayOutcome(Player player);
    private:
        char _boardState[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
        bool _gameOver;
        bool _draw;
};