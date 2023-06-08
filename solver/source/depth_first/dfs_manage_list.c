/*
** EPITECH PROJECT, 2023
** dante solver
** File description:
** manage_list
*/

#include "solver.h"

struct open2_s *dfs_add_to_list(struct open2_s **list, struct node2_s *node)
{
    struct open2_s *current = NULL;

    current = malloc(sizeof(struct node2_s));
    current->node = node;
    current->next = *list;
    *list = current;
    return (*list);
}

void dfs_move_to_closed(struct open2_s **open,
    struct node2_s *current)
{
    struct open2_s *tmp = *open;

    (*open) = (*open)->next;
    free(tmp);
}
