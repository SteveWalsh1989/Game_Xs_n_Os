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
    printf("Xs and Os!\n");                                     //  title for game

    struct game* p_game_info = 0;                               //  create structure for game info

    p_game_info = (struct game * ) malloc(sizeof(struct game)); // create pointer to malloc structure for game info

     printf("Structure pointer is: %p", p_game_info ) ;         // TEST : Prints pointer to structure in console

    //-------------------------------------
    //        Starting game
    //-------------------------------------

    initialise_game (p_game_info, "John", "Annie");             // initialise the game

    draw_banner();                                              // show games banner

    display_board(p_game_info->board);

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

    p_game_info->status         = P1_TURN;                        // set status to be player 1's turn

    strncpy(p_game_info->playerNames[0], name1,MAX_NAME_LEN);     // set player 1's name

    strncpy(p_game_info->playerNames[1], name2,MAX_NAME_LEN);     // set player 2's name

    p_game_info->finished       = False;                          // set game status finished to be false

    for(int innerIndex = 0; innerIndex < 4; innerIndex++){        // loop for first coord

        for (int outerIndex = 0; outerIndex < 4; outerIndex++) {  // loop for second coord

            p_game_info->board[innerIndex][outerIndex] = SPACE;   // sets selected area to be Empty space
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

   // for(int i = 0; i <=15; i++){                      // print 15 empty lines : Defined in project spec
   //     printf("\n");                                 // commenting out whilst building program
   // }
    printf("\n   -------------------       ");
    printf("\n       Game Status           ");     // prints banner
    printf("\n   -------------------       ");

    printf("\n\n");                                     // spaces beneath banner

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



