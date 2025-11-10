/*#include <stdlib.h>
#include <stdio.h>
#include "interface.h"
#include "move.h"
#include "game.h"
Board* create_board() {
    Board* board = (Board*)malloc(sizeof(Board));
    if (board != NULL) {
        init_board(board);
    }
    return board;
}

void free_board(Board* board) {
    if (board != NULL) {
        free(board);
    }
}

void display_board(Board* board) {
    if (board != NULL) {
        print_board(board);
    }
}*/
#include "game.h"
#include "interface.h"
#include "move.h"

#include <stdlib.h>
#include <stdio.h>
Board* create_board() {
    Board* board = (Board*)malloc(sizeof(Board));
    if (board != NULL) {
        init_board(board);
    }
    return board;
}

void free_board(Board* board) {
    if (board != NULL) {
        free(board);
    }
}

void display_board(Board* board) {
    if (board != NULL) {
        print_board(board);
    }
}


int make_move_with_history(Board* board, int from, int to, GameStack* stack) {
    if (board == NULL) return 0;
    if (!on_board(from) || !on_board(to)) return 0;

    Piece p = board->squares[from];
    if (p.type == EMPTY) return 0;
    if (p.color != board->current_turn) return 0;

    if (!is_valid_move(board, from, to)) return 0;

    // Save current state before move
    push_state(stack, board);

    // Execute move
    board->squares[to] = p;
    board->squares[from].type = EMPTY;
    board->squares[from].color = NO_COLOR;

    // Promotion
    int to_rank = to >> 4;
    if (p.type == PAWN) {
        if ((p.color == WHITE && to_rank == 7) || (p.color == BLACK && to_rank == 0)) {
            board->squares[to].type = QUEEN;
        }
    }

    // Switch turn
    board->current_turn = (board->current_turn == WHITE) ? BLACK : WHITE;

    return 1;
}

int undo(Board* board, GameStack* stack) {
    return undo_move(stack, board);
}

int redo(Board* board, GameStack* stack) {
    return redo_move(stack, board);
}


/*int make_move(Board* board, int from, int to) {
    if (board == NULL) return 0;
    if (!on_board(from) || !on_board(to)) return 0;

    Piece p = board->squares[from];
    if (p.type == EMPTY) return 0;
    if (p.color != board->current_turn) return 0;

    // Use move validation
    if (!is_valid_move(board, from, to)) return 0;

    // Make move
    board->squares[to] = p;
    board->squares[from].type = EMPTY;
    board->squares[from].color = NO_COLOR;
// Pawn promotion: if pawn reaches final rank
    int to_rank = to >> 4;
    if (p.type == PAWN) {
        if ((p.color == WHITE && to_rank == 7) ||
            (p.color == BLACK && to_rank == 0)) {
            // promote to queen
            board->squares[to].type = QUEEN;
        }}
    // Switch turn
    board->current_turn = (board->current_turn == WHITE) ? BLACK : WHITE;

    return 1;
}*/
