/*
** main.c
** ------
** entry point for program
*/

/* system includes */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* project includes */

/* global variables */

/* entry point of the program */
int
main(int argc, char **argv)
{
    bool is_x_turn = true;
    char grid[9] = {' ', ' ', ' ',
                    ' ', ' ', ' ',
                    ' ', ' ', ' '};
    int turn_count = 9;

    /* fancy title thingy */
    printf("=======================\n");
    printf("====== TicTacToe ======\n");
    printf("=======================\n");

    /* game loop */
    while(true)
    {
        /* tmp_input_char is being used to catch newlines and invalid input */
        int input_char = 0;
        int tmp_input_char = 0;
        int chars_read = -1;

        /* determines when to fill in grid and run logic */
        int next_fill = -1;

        /* this could be neater... so anyways */
        printf("|1|2|3|\t\t");
        printf("|%c|%c|%c|\n", grid[0], grid[1], grid[2]);
        printf("|4|5|6|\t\t");
        printf("|%c|%c|%c|\n", grid[3], grid[4], grid[5]);
        printf("|7|8|9|\t\t");
        printf("|%c|%c|%c|\n", grid[6], grid[7], grid[8]);
        printf("%c's turn! Choose a number between 1 and 9: ", (is_x_turn) ?
                                                               'X' : 'O');

        /* reads input, we only care about the first char tho */
        while(tmp_input_char != '\n' && tmp_input_char != EOF)
        {
            tmp_input_char = getchar();

            if(chars_read == -1)
                input_char = tmp_input_char;

            chars_read++;
        }

        /* don't spam input */
        if(chars_read > 1)
        {
            printf("\nToo much input, type a number between 1 and 9.\n\n");
            chars_read = -1;
            continue;
        }
        /* input something */
        if(input_char == '\n')
        {
            printf("\nNo input, type a number between 1 and 9.\n\n");
            continue;
        }
        /* ya killed STDIN and IDK how to fix it so bye */
        if(input_char == EOF)
        {
            printf("\n\nEnd-Of-File detected on STDIN, exiting...\n");
            break;
        }

        /* neater than doing lots of if statments, saving that for later */
        for(int i = 0; i <= 8; i++)
        {
            if(input_char == '1' + i)
            {
                /* no erasing */
                if(grid[i] != ' ')
                {
                    printf("\nGrid spot already taken, choose another.\n\n");
                    next_fill = -1;
                }
                else
                    next_fill = i;

                break;
            }
            else if(i == 8)
                printf("\nInvalid input, type a number between 1 and 9.\n\n");
        }

        if(next_fill != -1)
        {
            char winner_found = 0;

            if(is_x_turn)
                grid[next_fill] = 'X';
            else
                grid[next_fill] = 'O';

            /* top row */
            if(grid[0] == grid[1] && grid[1] == grid[2] && grid[0] != ' ')
                winner_found = grid[0];
            /* middle row */
            else if(grid[3] == grid[4] && grid[4] == grid[5] && grid[3] != ' ')
                winner_found = grid[3];
            /* bottom row */
            else if(grid[6] == grid[7] && grid[7] == grid[8] && grid[6] != ' ')
                winner_found = grid[6];
            /* left column */
            else if(grid[0] == grid[3] && grid[3] == grid[6] && grid[0] != ' ')
                winner_found = grid[0];
            /* middle column */
            else if(grid[1] == grid[4] && grid[4] == grid[7] && grid[1] != ' ')
                winner_found = grid[0];
            /* right column */
            else if(grid[2] == grid[5] && grid[5] == grid[8] && grid[2] != ' ')
                winner_found = grid[2];
            /* diagonal (\) */
            else if(grid[0] == grid[4] && grid[4] == grid[8] && grid[0] != ' ')
                winner_found = grid[0];
            /* diagonal (/) */
            else if(grid[2] == grid[4] && grid[4] == grid[6] && grid[2] != ' ')
                winner_found = grid[2];

            turn_count--;
            if(turn_count == 0)
            {
                printf("|1|2|3|\t\t");
                printf("|%c|%c|%c|\n", grid[0], grid[1], grid[2]);
                printf("|4|5|6|\t\t");
                printf("|%c|%c|%c|\n", grid[3], grid[4], grid[5]);
                printf("|7|8|9|\t\t");
                printf("|%c|%c|%c|\n", grid[6], grid[7], grid[8]);
                printf("=======================\n");
                printf("==== Nobody wins! =====\n");
                printf("=======================\n");
                break;
            }

            if(winner_found != 0)
            {
                printf("|1|2|3|\t\t");
                printf("|%c|%c|%c|\n", grid[0], grid[1], grid[2]);
                printf("|4|5|6|\t\t");
                printf("|%c|%c|%c|\n", grid[3], grid[4], grid[5]);
                printf("|7|8|9|\t\t");
                printf("|%c|%c|%c|\n", grid[6], grid[7], grid[8]);
                printf("=======================\n");
                printf("======= %c wins! =======\n", winner_found);
                printf("=======================\n");
                break;
            }

            is_x_turn = !is_x_turn;
        }
    }

//cleanup:
    return 0;
}
