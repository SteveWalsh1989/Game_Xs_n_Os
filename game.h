/******************************************************************************
 *
 * C Programming Assignment 2
 *
 * Steve Walsh
 *
 * R00151053
 *
 * 31/3/2018
 *
 * Noughts and Crosses Game
 *
 *
 *******************************************************************************/


#ifndef NOUGHTS_AND_CROSSES_GAME_GAME_H
#define NOUGHTS_AND_CROSSES_GAME_GAME_H


#define MAX_NAME_LEN 50
typedef enum Bool boolean;

//-------------------------------------
//        Lists
//-------------------------------------
enum Bool   { False, True };




//-------------------------------------
//        Structure
//-------------------------------------
struct game {
    char board[3][3];
    char playerNames[2][MAX_NAME_LEN];
    int status;
    boolean finished;
};

//-------------------------------------
//        Methods
//-------------------------------------

void play_game();







#endif //NOUGHTS_AND_CROSSES_GAME_GAME_H




