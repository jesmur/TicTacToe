//
// Created by Jessica on 2018-09-21.
//

#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <regex>

using namespace std;

int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

// Getters and setters for board values
void Board::setValue(int x, int y, int value){
    board[x][y] = value;
}

int Board::getValue(int x, int y) {

    return board[x][y];
}

// Returns X or O corresponding to board coordinate value
char getCoord(int row, int col) {
    if (board[row][col] != 0) {
        if (board[row][col] == X_VALUE) {
            return 'X';
        } else if (board[row][col] == O_VALUE) {
            return 'O';
        }
    }
}//end getCoord

// prints board according to move coordinates
void Board::displayBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", getCoord(0, 0), getCoord(0, 1), getCoord(0, 2));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", getCoord(1, 0), getCoord(1, 1), getCoord(1, 2));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n\n", getCoord(2, 0), getCoord(2, 1), getCoord(2, 2));
}//end displayBoard

// function resets board for a new game
void Board::resetBoard(){
    for(int row = 0; row <= 2; row++){
        for(int col = 0; col <= 2; col++){
            board[row][col] = 0;
        }
    }
} //end resetBoard

// Check board for row, column and diagonal wins
// Returns a tie if all moves have been played and there is no winner
int  Board::checkWin() {

    int winner;

    // Check if there is a row win
    for (int i=0; i<=2; i++) {
        if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != 0) {
            winner = board[i][0];
            return winner;
        }
    }
    // Check if there is a column win
    for(int i=0; i<=2; i++) {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[0][i] != 0) {
            winner = board[0][i];
            return winner;
        }
    }
    // Check left to right diagonal win
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != 0) {
        winner = board[1][1];
        return winner;
    }

    // Check right to left diagonal win
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board [0][2] != 0) {
        winner = board[1][1];
        return winner;
    }

    // Continue playing if there is no winner and not all moves have been placed
    for(int i = 0; i <= 2; i++) {
        for(int j = 0; j <= 2; j++) {
            if(board[i][j] == NO_VALUE) {
                return NO_VALUE;
            }
        }
    }

    return TIE_VALUE;
} //end checkWin


void ai::init(int aiPlayer) {
    _aiPlayer = aiPlayer ;

    if(aiPlayer == X_VALUE){
        _player = O_VALUE;
    }
    else {
        _player = X_VALUE;
    }
}//end init

// Sets AI move
void ai::doMove(Board& board) {\
    printf("Computer's turn: \n");
    aiMove bestMove = getBestMove(board, _aiPlayer);
    board.setValue(bestMove.x, bestMove.y, _aiPlayer);
}

// Minimax algorithm assesses best move for AI
// Resources:
// https://medium.freecodecamp.org/how-to-make-your-tic-tac-toe-game-unbeatable-by-using-the-minimax-algorithm-9d690bad4b37
// https://github.com/ryancesiel/tictactoe-minimax?files=1
aiMove ai::getBestMove(Board& board, int player) {

    int rv = board.checkWin();
    if (rv == _aiPlayer){
        return aiMove(10);
    }
    else if (rv == _player){
        return aiMove(-10);

    }
    else if (rv == TIE_VALUE){
        return aiMove(0);
    }
    // construct moves vector
    std::vector<aiMove> moves;

    // recursive function calls
    for (int y = 0; y <= 2; y++) {
        for (int x = 0; x <= 2; x++) {
            if (board.getValue(x,y) == NO_VALUE) {
                aiMove move;
                move.x = x;
                move.y = y;
                board.setValue(x, y, player);

                if (player == _aiPlayer) {
                    move.score = getBestMove(board, _player).score;
                }
                else {
                    move.score = getBestMove(board, _aiPlayer).score;
                }

                moves.push_back(move);
                board.setValue(x,y,0);
            }
        }
    }

    // Choose the best move
    int bestMove = 0;
    if(player == _aiPlayer){
        int bestScore = -100000;

        for(int i=0; i < moves.size(); i++){
            if(moves[i].score > bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    else {
        int bestScore = 100000;

        for(int i=0; i < moves.size(); i++){
            if(moves[i].score < bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }

    // return the best move
    return moves[bestMove];
}//end getBestMove

// Asks player where they want to place their move and validates input
// Takes in player input as string, validates it and returns it as int
void Player::playerTurn() {

    string input;

    regex moves("[1-9]");

    printf("\nChoose your move (1-9): ");
    do {
        getline(cin, input);

        if(!(regex_match(input, moves))) {
            printf("Invalid choice. Try again. ");
        }
    } while(!(regex_match(input, moves)));

    int move = stoi(input);
    int row, col;

    // Switch statement to return row and column board coordinates
    switch(move) {
        case 1:
            row = 0;
            col = 0;
            break;
        case 2:
            row = 0;
            col = 1;
            break;
        case 3:
            row = 0;
            col = 2;
            break;
        case 4:
            row = 1;
            col = 0;
            break;
        case 5:
            row = 1;
            col = 1;
            break;
        case 6:
            row = 1;
            col = 2;
            break;
        case 7:
            row = 2;
            col = 0;
            break;
        case 8:
            row = 2;
            col = 1;
            break;
        case 9:
            row = 2;
            col = 2;
            break;
        default:
            printf("Error.");
    }

    // Check if player's chosen position has already been played before
    if (board[row][col] != NO_VALUE) {
        printf("That position has already been taken. Try again. ");
        playerTurn();
    }
    else {
        board[row][col] = X_VALUE;
    }
}; // End userMove


// Asks user for turn choice input until input is validated
// Validate player input with regex and return as an integer
int Player::turnChoice() {

    string input;

    regex turn("[1-2]");

    printf("Would you like to go first or second? (1/2):  ");
    do {
        getline(cin, input);

        if(!(regex_match(input, turn))) {
            printf("Invalid choice. Choose 1 or 2:  ");
        }
    } while(!(regex_match(input, turn)));

    return stoi(input);
}; // End turnChoice


// Asks player whether or not they would like to play again
// Validate player input with regex
bool Player::playAgain() {

    string input;

    regex yesOrNo("[y|n]");

    do {
        getline(cin, input);

        if(!(regex_match(input, yesOrNo))) {
            printf("Invalid choice. Choose y or n: ");
        }
    } while(!(regex_match(input, yesOrNo)));

    if(input == "y") {
        return true;
    }

    return false;
}; // End checkAgain.
