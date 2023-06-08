/*
** EPITECH PROJECT, 2023
** dante
** File description:
** solver_get_argv
*/

#include "solver.h"

//get the maze in the file give as argument

int get_argv(t_maze *maze, char **argv, int argc)
{
    int fd = 0;
    char *buf = NULL;
    struct stat s;

    if (argc != 2) {
        return (84);
    }
    fd = open(argv[1], O_RDONLY);
    if (access(argv[1], R_OK) == -1 || fd == -1) {
        return (84);
    }
    stat(argv[1], &s);
    buf = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buf, s.st_size);
    maze->maze = my_str_to_word_array(buf, '\n');
    maze->cols = strlen(maze->maze[0]) - 1;
    maze->row = my_array_len(maze->maze) - 1;
    return (0);
}
