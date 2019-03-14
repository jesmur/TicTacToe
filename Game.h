//
// Created by Jessica on 2018-09-21.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

const int NO_VALUE = 0;
const int X_VALUE = 1;
const int O_VALUE = 2;
const int TIE_VALUE = -1;

class Board {
public:
    int getValue(int, int);
    void setValue(int, int, int);
    int  checkWin();
    void displayBoard();
    void resetBoard();
};

// struct used in minimax algorithm
struct aiMove {
    aiMove() {};
    aiMove(int Score) : score(Score) {};
    int x, y, score;
};

class ai{
public:
    void init(int aiPlayer);
    void doMove(Board& board);
    aiMove getBestMove(Board& board, int player);
    int _aiPlayer;
    int _player;

};

class Player{
public:
    void playerTurn();
    int turnChoice();
    bool playAgain();
};

#endif //TICTACTOE_GAME_H
