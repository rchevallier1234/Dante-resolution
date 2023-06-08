/*
** EPITECH PROJECT, 2023
** dante_solver
** File description:
** creat_neighbour
*/

#include "solver.h"

//get the position of the neighbour
void creat_neighbour_get_pos2(struct node2_s **neighbour,
    struct node2_s *current, int pos)
{
    if (pos == 1) {
        (*neighbour)->cols = current->cols - 1;
        (*neighbour)->row = current->row;
    }
    if (pos == 2) {
        (*neighbour)->cols = current->cols;
        (*neighbour)->row = current->row - 1;
    }
    if (pos == 3) {
        (*neighbour)->cols = current->cols + 1;
        (*neighbour)->row = current->row;
    }
    if (pos == 4) {
        (*neighbour)->cols = current->cols;
        (*neighbour)->row = current->row + 1;
    }
}

//create a new neighbour and adds it to the open list
struct open2_s *dfs_create_neighbour_set(struct open2_s *open,
    struct node2_s *current, int pos)
{
    struct node2_s *neighbour = NULL;

    neighbour = malloc(sizeof(struct node2_s));
    creat_neighbour_get_pos2(&neighbour, current, pos);
    neighbour->parent = current;
    dfs_add_to_list(&open, neighbour);
    return (open);
}

//create a new neighbour if is not a wall

struct open2_s *dfs_create_neighbour_main(struct open2_s *open,
    struct node2_s *current, char **maze)
{
    if (maze[current->row][current->cols + 1] == '*') {
        open = dfs_create_neighbour_set(open , current, 3);
    }
    if ((maze[current->row + 1] != 0) &&
        (maze[current->row + 1][current->cols] == '*')) {
        open = dfs_create_neighbour_set(open , current, 4);
    }
    if (current->cols >= 0 && maze[current->row][current->cols - 1] == '*') {
        open = dfs_create_neighbour_set(open, current, 1);
    }
    if (current->row > 0 &&
        (maze[current->row - 1][current->cols] == '*')) {
        open = dfs_create_neighbour_set(open, current, 2);
    }
    return (open);
}
