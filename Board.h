//
// Created by Jessica on 2018-09-19.

#include <string>

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H


using namespace std;

class Board {


    string board[3][3] = {{"1","2","3"},{"4","5","6"},{"7","8","9"}};



public:
//    int getVal(int, int);
//    void setVal(int, int,int);
//    int  checkWinner();
    void displayBoard();
//    void movePlacement(int ,int , int);


};


#endif //TICTACTOE_BOARD_H
