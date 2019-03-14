//
// Created by Jessica on 2018-09-19.
//

#include "Board.h"
#include <iostream>

using namespace std;

void Board::displayBoard(){

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j <3; j++){
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
}

