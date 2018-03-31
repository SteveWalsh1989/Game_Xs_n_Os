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
//-------------------------------------
//       Import Statements
//-------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "game.h"


//-------------------------------------
//        Methods
//-------------------------------------
/**
 * play_game
 *
 * Starts the game
 */
void play_game()
{

    struct game* p_game_info = 0;                                     //  create structure for game info

    p_game_info = (struct game * ) malloc(sizeof(struct game));       // create pointer to malloc structure for game info

   //  printf("Structure pointer is: %p", p_game_info ) ;             // TEST : Prints pointer to structure in console

    //-------------------------------------
    //        Starting game
    //-------------------------------------

    initialise_game (p_game_info, "    John", "Annie");                   // initialise the game

    while(!p_game_info->finished) {                                       // keep looping while game is not finised

        draw_banner();                                                    // display games banner

        display_board(p_game_info->board);                                // display board

        print_status(p_game_info);                                        // display game state

        display_board_positions();                                        // display board positions

        int row = -1;                                                     // initialise variable to store row number

        int col = -1;                                                     // initialise variable to store column number

        bool freeSpace = False;                                           // for valid command loop

        while (!freeSpace) {

            get_row_col(&row, &col);                                              // get move from user

            if (p_game_info->board[row][col] == SPACE) {                          // Scenario 1:  space is free

                process_move(p_game_info, &row, &col);                            // process users move to update board

                freeSpace = True;                                                 // if valid command  exits loop

            } else {                                                              //  Scenario 2: space already taken

                printf("\n\n\tInvalid Move: Space already taken \n\n");           // print invalid move message to user

            }
        }
    }
}
/**
 * initialise_game
 *
 * initialises the games structure and players
 *
 * @param p_game_info   pointer to game structure
 * @param name1         player 1 name
 * @param name2         player 2 name
 */
void initialise_game(struct game* p_game_info, char* name1, char* name2)
{
    strncpy(p_game_info->playerNames[0], name1, MAX_NAME_LEN);              // set player 1's name

    strncpy(p_game_info->playerNames[1], name2, MAX_NAME_LEN);              // set player 2's name

    p_game_info->finished = False;                                          // set game status finished to be false

    p_game_info->status   = P1_TURN;                                        // set status to be player 1's turn

    for(int innerIndex = 0; innerIndex < 4; innerIndex++){                  // loop for first coord

        for (int outerIndex = 0; outerIndex < 4; outerIndex++) {            // loop for second coord

            p_game_info->board[innerIndex][outerIndex] = SPACE;             // sets selected area to be Empty space
        }
    }


}


/**
 * draw_banner
 *
 * Draws main banner for game
 *
 */
void draw_banner(){

   // for(int i = 0; i <=15; i++){                                              // print 15 empty lines : Defined in project spec
   //     printf("\n");                                                         // commenting out whilst building program
   // }
    printf("\n   -------------------       ");
    printf("\n       Game Status           ");                                  // prints banner
    printf("\n   -------------------       ");

    printf("\n\n");                                                             // spaces beneath banner

}

/**
 * display_board
 *
 * Draws current game state
 *
 * @param board:  board of characters
 */
void display_board( char board[3][3]){

    printf("\n\t  %c  |  %c  |  %c  ",board[0][0],board[0][1],board[0][2] );

    printf("\n\t----- ----- -----   ");

    printf("\n\t  %c  |  %c  |  %c  ",board[1][0],board[1][1],board[1][2] );

    printf("\n\t----- ----- -----   ");

    printf("\n\t  %c  |  %c  |  %c  ",board[2][0],board[2][1],board[2][2] );

}

/**
 * print_status
 *
 * displays current game state
 *
 * @param p_game_info : takes in game structure
 */
void print_status(struct game* p_game_info) {

    printf("\n\n\n\t");                                                                     // create new line for readability

    if( (p_game_info->status == P1_TURN) && (p_game_info->finished == False)) {             // Scenario 1: Player 1's turn        ( 0 0 )

                printf("%s 's Turn", p_game_info->playerNames[0]);

    } else if( (p_game_info->status == P2_TURN) && (p_game_info->finished == False)) {      // Scenario 2: Player 2's turn        ( 1 0 )

                printf("%s 's Turn", p_game_info->playerNames[1]);

    } else if ((p_game_info->status == P1_WON) && (p_game_info->finished == True)) {        // Scenario 1: Player 1 Won the game  ( 2 1 )

                printf("Well done %s, you won the Game", p_game_info->playerNames[0]);

    } else if ((p_game_info->status == P2_WON) && (p_game_info->finished == True)) {        // Scenario 2: Player 2 Won the game  ( 3 1 )

                printf("Well done %s, you won the Game", p_game_info->playerNames[1]);

    } else {                                                                                // Scenario 5: Game is a draw
                printf("Game was a Draw");
    }

    printf("\n\n");                                                                         // create new line for readability

}

/**
 * display_board_positions
 *
 * Displays board with positions player can select
 */
void display_board_positions (){

    printf("\n   -------------------       ");
    printf("\n      Select a Move          ");                                 // prints banner
    printf("\n   -------------------       ");

    printf("\n\t  0  |  1  |  2   " );

    printf("\n\t----- ----- ----- ");

    printf("\n\t  3  |  4  |  5   " );

    printf("\n\t----- ----- ----- ");

    printf("\n\t  6  |  7  |  8   " );

    printf("\n\n");                                                            // create new line


}

void get_row_col(int* row, int*column){

    printf("\n\t" );                                                    // new line

    bool validMove = False;                                             // store state if valid command entered

    int move = -1;                                                      // initialize user move variable

    while(!validMove) {                                                 // loops while validMove = False

        printf("Enter Move: ");                                         // prompt player to enter move

        scanf("%d", &move);                                             // store users move

        int dump = getchar();                                           // clear enter key

        if( move > -1 && move < 9) {                                    // checks if move is in valid range

            validMove = True;                                           // if valid exits loop

        } else {
            printf("\n\n\tInvalid Move: Enter number between 0 - 8 and press 'Enter' \n\n"); // print invalid move message to user
        }
    }
    if(move == 0 ) {                                                    // Scenario 1: user enters 0 : set row = 0 column = 0
        *row    = 0;
        *column = 0;

    } else  if(move == 1 ) {                                            // Scenario 2: user enters 1 : set row = 0 column = 1
        *row    = 0;
        *column = 1;

    } else if(move == 2 ) {                                             // Scenario 3: user enters 2 : set row = 0 column = 2
        *row    = 0;
        *column = 2;

    } else if(move == 3 ) {                                             // Scenario 4: user enters 3 : set row = 1 column = 0
        *row    = 1;
        *column = 0;

    } else if(move == 4 ) {                                             // Scenario 5: user enters 4 : set row = 1 column = 1
        *row    = 1;
        *column = 1;

    } else if(move == 5 ) {                                             // Scenario 6: user enters 5 : set row = 1 column = 2
        *row    = 1;
        *column = 2;

    } else if(move == 6 ) {                                             // Scenario 7: user enters 6 : set row = 2 column = 0
        *row    = 2;
        *column = 0;

    } else if(move == 7 ) {                                             // Scenario 8: user enters 7 : set row = 2 column = 1
        *row    = 2;
        *column = 1;

    } else if(move == 8 ) {                                             // Scenario 9: user enters 8 : set row = 2 column = 2
        *row    = 2;
        *column = 2;

    }
}

/**
 * process_move
 *
 * Processes users move to updates game board
 *
 * @param game_info  : board to be updated
 * @param row        : row num
 * @param col        : column num
 */
void process_move(struct game* game_info, int* row, int* col){

    if (game_info->status == P1_TURN){                             // Scenario 1: Player 1's turn

        game_info->board[*row][*col] = X_SYMBOL;                   // set position to X

    } else if (game_info->status == P2_TURN){                      // Scenario 2: Player 2's turn

        game_info->board[*row][*col] = O_SYMBOL;                   // set position to 0
    }
}


