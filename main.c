
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
 * 2 Players : first player selected at random
 * Each player is shown current game state and a list of moves they can make
 * Player enters integer value of space they want to occupy
 * Game checks after each move if the player won or if game is a draw
 * If a player wins the game displays a message congratulating player
 *
 *
 *
 *******************************************************************************/
//-------------------------------------
//       Import Statements
//-------------------------------------

#include "game.h"

int main(int argc, char* argv[])
{

    play_game();                      // Play the game

    return 0;
}
