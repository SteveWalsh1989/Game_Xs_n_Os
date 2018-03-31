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

typedef enum Bool boolean;

//-------------------------------------
//   Define Constants
//-------------------------------------
#define MAX_NAME_LEN 50                               // max length of player name

#define SPACE '-'                                     // character for empty position on board

#define X_SYMBOL 'X'                                  // Player 1's character

#define O_SYMBOL '0'                                  // Player 2's character



//-------------------------------------
//        Lists
//-------------------------------------
enum Bool   { False, True };                           // allow boolean values

enum status { P1_TURN ,                                // if Player 1's turn

              P2_TURN ,                                // if Player 2's turn

              P1_WON  ,                                // if Player 1 won game

              P2_WON  ,                                // if Player 2 won game

              DRAW                                     // if game was a draw
            };

//-------------------------------------
//       Game Structure
//-------------------------------------
struct game {                                           // stores game structure

    char board[3][3];                                   // stores moves

    char playerNames[2][MAX_NAME_LEN];                  // stores 2 players names

    int status;                                         // holds status of the game

    boolean finished;                                   // holds if game is finished
};

//-------------------------------------
//       Game  Methods
//-------------------------------------

void play_game();                                       // start game

void initialise_game(struct game* , char* , char* );    // initialise structure

void draw_banner();                                     // display banner

void display_board( char board[3][3]);                  // display board

void print_status(struct game*);                        // displays current game state

void display_board_positions() ;                        // display board positions

void get_row_col(int* , int*)  ;                        // store player move

void process_move(struct game* , int* , int* );         // process users move

void check_winner(struct game*);                        // checks if there was a winner




#endif //NOUGHTS_AND_CROSSES_GAME_GAME_H




