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



//-------------------------------------
//   Define Constants
//-------------------------------------
#define MAX_NAME_LEN 50
#define SPACE '-'
#define X_SYMBOL 'X'
#define O_SYMBOL '0'

typedef enum Bool boolean;

//-------------------------------------
//        Lists
//-------------------------------------
enum Bool   { False, True };

enum status { P1_TURN ,
              P2_TURN ,
              P1_WON  ,
              P2_WON  ,
              DRAW
            };

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

void play_game();                                       // start game

void initialise_game(struct game* , char* , char* );    // initialise structure

void draw_banner();                                     // display banner

void display_board( char board[3][3]);                  // display board

void print_status(struct game*);                        // displays current game state

void display_board_positions() ;                        // display board positions

void get_row_col(int* , int*)  ;                        // store player move

void process_move(struct game* , int* , int* );         // process users move

void check_winner(struct game*);                  // checks if there was a winner




#endif //NOUGHTS_AND_CROSSES_GAME_GAME_H




