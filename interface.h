#ifndef INTERFACE_H
#define INTERFACE_H

#include "game.h"
// Updated make_move with history support
int make_move_with_history(Board* board, int from, int to, GameStack* stack);

// Undo / Redo
int undo(Board* board, GameStack* stack);
int redo(Board* board, GameStack* stack);


// Initialize and return pointer to a new board
Board* create_board();

// Free allocated board memory
void free_board(Board* board);

// Print the board state (for debug)
void display_board(Board* board);


#endif
