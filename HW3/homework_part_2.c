/*
 * Assignment: Homework #3
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Program that simulates a games board that adds, removes, and moves game pieces.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game_piece {
    char label[30];
};

struct game_board {
    int rows, columns;
    struct game_piece **board;
};

/*
Function:  game_piece_init_default
--------------------
Initializes a game piece to "$$$".

Parameters:
    struct game_piece *piece: The piece being initialized to "$$$".
*/
void game_piece_init_default(struct game_piece *piece) {
    strcpy(piece->label, "$$$"); // Copy "$$$" to piece->label
}

/*
Function:  game_piece_init
--------------------
Initializes a game piece to a new label value.

Parameters:
    struct game_piece *piece: The piece that is having it's label changed.
    char *new_label: The new label of the piece.
*/
void game_piece_init(struct game_piece *piece, char *new_label) {
    strcpy(piece->label, new_label);
}

/*
Function:  game_piece_get_label
--------------------
Function to get the label of a game piece.

Parameters:
    struct game_piece *piece: The piece that we want the label of.

Returns:
    char *: A pointer to the piece's label.
*/
char *game_piece_get_label(struct game_piece *piece) {
    return piece->label;
}

/*
Function:  game_piece_to_string
--------------------
Function to get the first three characters in a piece's label.

Parameters:
    struct game_piece *piece: The piece that we want to turn into a string.

Returns:
    char *: Returns the first 3 characters of the piece's label.
*/
char *game_piece_to_string(struct game_piece *piece) {
    char *three_letter_str = malloc(4 * sizeof(char));
    int see_null = 0; // If we see '\0' in *((*piece).label + i), then turn to 1
    for (char i = 0; i < 3; i++) {
        if (piece->label[i] != '\0' && see_null == 0) {
            three_letter_str[i] = piece->label[i];
        } else {
            three_letter_str[i] = ' ';
            see_null = 1;
        }
    }

    three_letter_str[3] = '\0';

    return three_letter_str;
}

/*
Function:  game_board_init
--------------------
Creates a 2d, rows x cols, array of game pieces and initializes them to "$$$".

Parameters:
    struct game_board *game_board: The pointer to the game board to be created.
    int rows: Number of rows the game board should be.
    int cols: Number of columns the game board should be.
*/
void game_board_init(struct game_board *game_board, int rows, int cols) {
    game_board->board = malloc(rows * sizeof(struct game_piece *));
    for (int i = 0; i < rows; ++i) {
        game_board->board[i] = malloc(cols * sizeof(struct game_piece));
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            game_piece_init_default(&(game_board->board[i][j]));
        }
    }

    game_board->rows = rows;
    game_board->columns = cols;
}

/*
Function:  game_board_is_space_valid
--------------------
Checks to see if the index of row and col exist for the game board.

Parameters:
    struct game_board *game_board: Pointer to the game board.
    int row: Row index
    int col: Column index

Returns:
    int: 1 if indices exist, 0 otherwise.
*/
int game_board_is_space_valid(struct game_board *game_board, int row, int col) {
    if ((col >= 0 && col < game_board->columns) && (row >= 0 && row < game_board->rows)) {
        return 1;
    } else {
        return 0;
    }
}

/*
Function:  game_board_add_piece
--------------------
Adds a piece to the game board.

Parameters:
    struct game_board *game_board: Pointer to the game board.
    struct game_piece *piece: Pointer to the game piece to be added.
    int row: Row index
    int col: Column index

Returns:
    int: 1 if added, 0 otherwise.
*/
int game_board_add_piece(struct game_board *game_board, struct game_piece *piece, int row,
                         int col) {
    if (game_board_is_space_valid(game_board, row, col) == 1 &&
        strcmp(game_piece_to_string(&(game_board->board[row][col])), "$$$") == 0) {
        game_board->board[row][col] = *piece;
        return 1;
    } else {
        return 0;
    }
}

/*
Function:  game_board_move_piece
--------------------
Moves a piece on the board to a new location and changes the old location to the default value.

Parameters:
    struct game_board *game_board: Pointer to the game board.
    int src_row: Index of the source row.
    int src_col: Index of the source column.
    int dest_row: Index of the destination row.
    int dest_col: Index of the destination column.

Returns:
    int: 1 if moved, 0 otherwise.
*/
int game_board_move_piece(struct game_board *game_board, int src_row, int src_col, int dest_row, int dest_col) {
    struct game_piece *src_pointer = &(game_board->board[src_row][src_col]);
    if (game_board_is_space_valid(game_board, src_row, src_col) == 1
        && game_board_is_space_valid(game_board, dest_row, dest_col) == 1
        && strcmp(game_piece_to_string(&(game_board->board[dest_row][dest_col])), "$$$") == 0) {
        game_board->board[dest_row][dest_col] = game_board->board[src_row][src_col];
        game_piece_init_default(src_pointer);
        return 1;
    } else {
        return 0;
    }
}

/*
Function:  game_board_print
--------------------
Prints the current state of the game board.

Parameters:
    struct game_board *game_board: Pointer to the game board.
*/
void game_board_print(struct game_board *game_board) {
    printf("The GameBoard\n---------------------------------\n");

    for (int i = 0; i < game_board->rows; ++i) {
        for (int j = 0; j < game_board->columns; ++j) {
            struct game_piece *piece_pointer = &(game_board->board[i][j]);
            printf("%s", game_piece_to_string(piece_pointer));
            printf(" ");
        }
        printf("\n");
    }
}


int main() {
    /* declare local variables */
    int row;
    int col;
    int destRow;
    int destCol;
    int rowNum;
    int colNum;
    struct game_board board;
    struct game_piece piece;
    char input_string[30];

    /* get the size of the game board */
    printf("Please enter the number of rows.\n");
    scanf("%d", &rowNum);

    printf("Please enter the number of columns.\n");
    scanf("%d", &colNum);

    game_board_init(&board, rowNum, colNum);

    /* get the first piece's label */
    printf("Please enter a label for a new piece. Enter \"Q\" when done.\n");
    scanf("%s", input_string);

    while (strcmp(input_string, "Q") != 0 && strcmp(input_string, "q") != 0) {
        game_piece_init(&piece, input_string);

        /* get the location to place the piece */
        printf("Please enter a row for the piece.\n");
        scanf("%d", &row);

        printf("Please enter a column for the piece.\n");
        scanf("%d", &col);

        /* verify the space is valid then add the piece to the board */
        if (game_board_is_space_valid(&board, row, col)) {
            if (game_board_add_piece(&board, &piece, row, col)) {
                printf("New piece \"%s\" added.\n", game_piece_get_label(&piece));
            } else {
                printf("A piece is already at that space.\n");
            }
        } else {
            printf("Invalid row and/or column.\n");
        }

        /* get the label for the next piece */
        printf("Please enter a label for a new piece. Enter \"Q\" when done.");
        scanf("%s", input_string);
    }

    /* print the board and check if user wants to move a piece */
    game_board_print(&board);
    printf("Would you like to move a piece? Enter \"Y\" to move a piece.\n");
    scanf("%s", input_string);

    while (strcmp(input_string, "Y") == 0 || strcmp(input_string, "y") == 0) {
        /* get the location of the piece */
        printf("Please enter the piece's row.");
        scanf("%d", &row);

        printf("Please enter the piece's column.");
        scanf("%d", &col);

        /* get the destination for the piece */
        printf("Please enter the piece's new row.");
        scanf("%d", &destRow);

        printf("Please enter the piece's new column.");
        scanf("%d", &destCol);

        /* verify both spaces are valid then move the piece */
        if (game_board_is_space_valid(&board, row, col) &&
            game_board_is_space_valid(&board, destRow, destCol)) {
            if (game_board_move_piece(&board, row, col, destRow, destCol)) {
                printf("Piece moved to new space.\n");
            } else {
                printf("A piece is already in that space.\n");
            }
        } else {
            printf("A row or column is invalid. No piece moved.\n");
        }

        /* print the board and check if the user wants move another piece */
        game_board_print(&board);
        printf("Would you like to move a piece? Enter \"Y\" to move a piece.\n");
        scanf("%s", input_string);
    }

    return 0;
}