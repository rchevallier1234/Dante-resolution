/*
** EPITECH PROJECT, 2023
** dante solver
** File description:
** depth_first
*/

#include "solver.h"

//create the open list
void set_open_list( struct open2_s **open)
{
    *open = malloc(sizeof(struct open2_s));
    (*open)->next = NULL;
}

//create the first current, the start on the algorithm

struct open2_s *dfs_creat_first_current(struct node2_s *current,
    struct open2_s *open, t_maze *maze)
{
    maze->nb_move = 0;
    while (find_nb_option(maze->maze, maze->row, maze->cols) == 1) {
        maze->maze[maze->row][maze->cols] = 'o';
        chose_way(maze);
    }
    maze->maze[maze->row][maze->cols] = 'o';
    current->row = maze->row;
    current->cols = maze->cols;
    current->parent = NULL;
    open->node = current;
    open->next = NULL;
    return (open);
}

//return 1 if the solution was found
int is_finish(struct node2_s *current)
{
    if (current->row == 0) {
        if (current->cols == 0 || current->cols == 1) {
            return (1);
        }
    }
    return (0);
}

struct node2_s *depth_first(t_maze *maze)
{
    struct open2_s *open = NULL;
    struct node2_s *current = NULL;
    set_open_list(&open);
    current = malloc(sizeof(struct node2_s));
    open = dfs_creat_first_current(current, open, maze);
    while (1) {
        current = open->node;
        if (is_finish(current) == 1) {
            return (current);
        }
        if (maze->maze[current->row][current->cols] != 'o') {
            maze->maze[current->row][current->cols] = 'c';
        }
        dfs_move_to_closed(&open, current);
        open = dfs_create_neighbour_main(open, current, maze->maze);
        if (open == NULL) {
            printf("no solution found");
            return (NULL);
        }
    }
}
