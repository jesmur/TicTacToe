#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int play();

int main() {

    play();

    return 0;

};

int play(){

    Board board;
    Player player;
    ai aiPlayer;
    aiPlayer.init(2);

    int status = 0;
    int turnCount = 0;

    printf("Welcome to Unbeatable Tic Tac Toe!\n");
    printf("Below are the numbers corresponding to board positions: \n\n");
    printf(" 1 | 2 | 3\n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6\n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9\n");
    board.displayBoard();

    // Validate user input for first or second move
    int playerTurn = player.turnChoice();

    while(status == 0){

        if (playerTurn == 1) {
            if (!(turnCount % 2)) {
                player.playerTurn();
                status = board.checkWin();
            } else {
                aiPlayer.doMove(board);
                status = board.checkWin();
            }
        }
        else {
            if (!(turnCount % 2)) {
                aiPlayer.doMove(board);
                status = board.checkWin();
            }
            else {
                player.playerTurn();
                status = board.checkWin();
            }
        }

        turnCount++; // Increment turn count
        board.displayBoard(); // Print updated board
    }

    if(status == -1){
        printf("The game is a tie.\n");
    }
    if(status == 1){
        printf("You are the winner!\n");  // good luck getting here
    }
    if(status == 2){
        printf("The computer has won!\n");
    }

    printf("\nWould you like to continue playing? (y/n): ");
    if (player.playAgain()){
        board.resetBoard();
        main();
    }
    else{
        printf("Goodbye!");
    }
}