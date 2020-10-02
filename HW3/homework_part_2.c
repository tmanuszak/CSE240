#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
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

    while (strcmp(input_string, "Q") != 0 && strcmp(input_string, "q") != 0)
    {
        game_piece_init(&piece, input_string);

        /* get the location to place the piece */
        printf("Please enter a row for the piece.\n");
        scanf("%d", &row);

        printf("Please enter a column for the piece.\n");
        scanf("%d", &col);

        /* verify the space is valid then add the piece to the board */
        if (game_board_is_space_valid(&board, row, col))
        {
            if (game_board_add_piece(&board, &piece, row, col))
            {
                printf("New piece \"%s\" added.\n", game_piece_get_label(&piece));
            }
            else
            {
                printf("A piece is already at that space.\n");
            }
        }
        else
        {
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

    while (strcmp(input_string, "Y") == 0 || strcmp(input_string, "y") == 0)
    {
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
            game_board_is_space_valid(&board, destRow, destCol))
        {
            if (game_board_move_piece(&board, row, col, destRow, destCol))
            {
                printf("Piece moved to new space.\n");
            }
            else
            {
                printf("A piece is already in that space.\n");
            }
        }
        else
        {
            printf("A row or column is invalid. No piece moved.\n");
        }

        /* print the board and check if the user wants move another piece */
        game_board_print(&board);
        printf("Would you like to move a piece? Enter \"Y\" to move a piece.\n");
        scanf("%s", input_string);
    }

    return 0;
}