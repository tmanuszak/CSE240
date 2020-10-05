#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game_piece {
    char label[30];
};

void game_piece_init_default(struct game_piece *piece) {
    strcpy(piece->label, "$$$"); // Copy "$$$" to piece->ch
}

void game_piece_init(struct game_piece *piece, char *new_label) {
    strcpy(piece->label, new_label);
}

char *game_piece_get_label(struct game_piece *piece) {
    return piece->label;
}

char *game_piece_to_string(struct game_piece *piece) {
    char *three_letter_str = (char *) (sizeof(char) * 4);
    int see_null = 0; // If we see '\0' in *((*piece).label + i), then turn to 1
    for (char i = 0; i < 3; i++) {
        if (piece->label[i] != '\0' && see_null == 0) {
            *(three_letter_str + i) = *((*piece).label + i);
        } else {
            *(three_letter_str + i) = ' ';
            see_null = 1;
        }
    }

    three_letter_str[3] = '\0';

    return three_letter_str;
}

struct game_board {
    int row, column;
    struct game_piece **board;
};

void game_board_init(struct game_board *game_board, int rows, int cols) {
    *(*game_board).board = (struct game_piece *) malloc(rows * sizeof(struct game_piece *));
    for (int i = 0; i < rows; ++i) {
        game_board->board[i] = malloc(cols * sizeof(struct game_piece));
    }
//    struct game_piece temp_board[rows][cols];
//
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            game_piece_init_default(temp_board[i][j]);
//        }
//    }
//
//    (*game_board).board = temp_board;
}

int game_board_is_space_valid(struct game_board *game_board, int row, int col) {
    int total = sizeof((*game_board).board);
    int number_of_cols = sizeof((*game_board).board[0]);
    int number_of_rows = total / number_of_cols;

    if ((col >= 0 && col <= number_of_cols) && (row >= 0 && row <= number_of_rows)) {
        return 1;
    } else {
        return 0;
    }
}

int game_board_add_piece(struct game_board *game_board, struct game_piece *piece, int row, int col) {
    char *piece_string = game_piece_to_string(piece);
    int is_default = strcmp(piece_string, "$$$"); // is_default = 0 if piece is default, else is_default = 1;
    if (game_board_is_space_valid(game_board, row, col) == 1 && is_default == 0) {
        game_board->board[row][col] = *piece;
        return 1;
    } else {
        return 0;
    }
}

int game_board_move_piece(struct game_board *game_board, int src_row, int src_col, int dest_row, int dest_col) {
    struct game_piece * dest_pointer = &(game_board->board[dest_row][dest_col]);
    struct game_piece * src_pointer = &(game_board->board[src_row][src_col]);
    char *piece_string = game_piece_to_string(dest_pointer);
    int is_default = strcmp(piece_string, "$$$"); // is_default = 0 if piece is default, else is_default = 1;
    if (game_board_is_space_valid(game_board, src_row, src_col) == 1
        && game_board_is_space_valid(game_board, dest_row, dest_col) == 1
        && is_default == 0) {
        game_board->board[dest_row][dest_col] = game_board->board[src_row][src_col];
        game_piece_init_default(src_pointer);
        return 1;
    } else {
        return 0;
    }
}

void game_board_print(struct game_board * game_board) {
    int total = sizeof((*game_board).board);
    int number_of_cols = sizeof((*game_board).board[0]);
    int number_of_rows = total / number_of_cols;
    printf("The GameBoard\n---------------------------------\n");

    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_cols; ++j) {
            struct game_piece * piece_pointer = &(game_board->board[i][j]);
            printf("%s",game_piece_to_string(piece_pointer));
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