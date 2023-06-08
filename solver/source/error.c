/*
** EPITECH PROJECT, 2023
** dante solve
** File description:
** error
*/

#include "solver.h"

//check if the line is valid
int is_invalid_str(char *str)
{
    for (int col = 0; str[col] != '\0'; col++) {
        if (str[col] != 'X' && str[col] != '*') {
            return 1;
        }
    }
    return (0);
}

//check if the maze is valid
int error_maze(t_maze *maze)
{
    int save_len = 0;

    for (int row = 0; maze->maze[row] != NULL; row++) {
        if (strlen(maze->maze[row]) != save_len && row != 0) {
            return (84);
        }
        if (is_invalid_str(maze->maze[row]) == 1) {
            return (84);
        }
        save_len = strlen(maze->maze[row]);
    }
    return (0);
}
