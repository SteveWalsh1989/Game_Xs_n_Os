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
#include "game.h"


//-------------------------------------
//        Methods
//-------------------------------------

void play_game()
{
    printf("Xs and Os!\n");                                     //  title for game

    struct game* p_game_info = 0;                               //  create structure for game info

    p_game_info = (struct game * ) malloc(sizeof(struct game)); // create pointer to malloc structure for game info

     printf("Structure pointer is: %p", p_game_info ) ;          // TEST : Prints pointer to structure in console
}
