/*
** EPITECH PROJECT, 2023
** dante solver
** File description:
** parsing_list.c
*/

#include "solver.h"

//return 1 if an element of the list is equal to the position indicated
int is_in_closed(struct open_s *close, int row, int cols)
{
    if (close == NULL) {
        return (0);
    }
    while (close != NULL) {
        if (close->node->cols == cols && close->node->row == row) {
            return (1);
        }
        close = close->next;
    }
    return (0);
}

//return the node with the lowest f_cost
struct node_s *find_lowest_f_cost(struct open_s *open)
{
    struct node_s *node;

    node = open->node;
    while (open != NULL) {
        if (open->node->move_left == 0) {
            return open->node;
        }
        if (node->move_left + node->move >
            open->node->move_left + open->node->move) {
            node = open->node;
        }
        open = open->next;
    }
    return node;
}

//return 1 if the neighbour have a shorter path that he who is already in the open list
int is_a_sorter_path(struct open_s *open, int row, int cols,
    struct node_s *neighbour)
{
    while (open != NULL) {
        if (open->node->row == row && open->node->cols == cols &&
            open->node->move + open->node->move_left >
            neighbour->move + neighbour->move_left) {
            return 1;
        }
        open = open->next;
    }
    return 0;
}
