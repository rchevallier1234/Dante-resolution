/*
** EPITECH PROJECT, 2023
** dante
** File description:
** solve_maze
*/

#include "solver.h"

//find the nbr of option for the current pos in the maze
int find_nb_option(char **array, int row, int col)
{
    int nb_option_v = 0;
    if (col > 0 && (array[row][col - 1] == '*')) {
        nb_option_v++;
    }
    if (row > 0 && (array[row - 1][col] == '*')) {
        nb_option_v++;
    }
    if (array[row][col + 1] == '*') {
        nb_option_v++;
    }
    if ((array[row + 1] != 0) &&
        (array[row + 1][col] == '*')) {
        nb_option_v++;
    }
    return (nb_option_v);
}

int chose_way(t_maze *maze)
{
    if (maze->cols > 0 && maze->maze[maze->row][maze->cols - 1] == '*') {
        maze->cols--;
        return (1);
    }
    if (maze->row > 0 && (maze->maze[maze->row - 1][maze->cols] == '*')) {
        maze->row--;
        return (1);
    }
    if (maze->maze[maze->row][maze->cols + 1] == '*') {
        maze->cols++;
        return (1);
    }
    if ((maze->maze[maze->row + 1] != 0) &&
        (maze->maze[maze->row + 1][maze->cols] == '*')) {
        maze->row++;
        return (1);
    }
    return (0);
}

//create the first current, the start on the algorithm
struct open_s *creat_first_current(struct node_s *current, struct open_s *open,
    t_maze *maze)
{
    maze->nb_move = 0;
    while (find_nb_option(maze->maze, maze->row, maze->cols) == 1) {
        maze->maze[maze->row][maze->cols] = 'o';
        chose_way(maze);
        current->move++;
    }
    maze->maze[maze->row][maze->cols] = 'o';
    current->row = maze->row;
    current->cols = maze->cols;
    current->move_left = current->row + current->cols;
    current->parent = NULL;
    open->node = current;
    open->next = NULL;
    return (open);
}

//create the open and the close list

void set_list( struct open_s **open,
    struct open_s **close)
{
    *open = malloc(sizeof(struct open_s));
    (*open)->node = malloc(sizeof(struct node_s));
    (*open)->next = NULL;
    *close = malloc(sizeof(struct open_s));
    (*close)->node = malloc(sizeof(struct node_s));
    (*close)->next = NULL;
}

struct node_s *a_star(t_maze *maze)
{
    struct open_s *open = NULL;
    struct open_s *close = NULL;
    struct node_s *current = NULL;

    set_list(&open, &close);
    current = malloc(sizeof(struct node_s));

    open = creat_first_current(current, open, maze);
    while (1) {
        current = find_lowest_f_cost(open);
        if (current->move_left == 1) {
            return (current);
        }
        move_to_closed(&open, &close, current);
        open = creat_neighbour_main(open, close, current, maze->maze);
        if (open == NULL) {
            printf("no solution found");
            return (NULL);
        }
    }
}
