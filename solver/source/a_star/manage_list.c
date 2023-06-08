/*
** EPITECH PROJECT, 2023
** dante solver
** File description:
** manage_list
*/

#include "solver.h"

void remove_from_list(struct open_s **list, struct node_s *current)
{
    struct open_s *open_head = *list;

    if ((current->cols == (*list)->node->cols &&
        current->row == (*list)->node->row) || ((*list)->next == NULL)) {
        (*list) = (*list)->next;
        return;
    }
    while ((*list)->next != NULL) {
        if (current->cols == (*list)->next->node->cols &&
            current->row == (*list)->next->node->row) {
            (*list)->next = (*list)->next->next;
            *list = open_head;
            return;
        }
        *list = (*list)->next;
    }
    *list = open_head;
}

struct open_s *add_to_list(struct open_s **list, struct node_s *node)
{
    struct open_s *current = NULL;

    current = malloc(sizeof(struct open_s));
    current->node = node;
    current->next = *list;
    *list = current;
    return *list;
}

//move the current in the close liste
void move_to_closed(struct open_s **open, struct open_s **close,
    struct node_s *current)
{
    remove_from_list(open, current);
    *close = add_to_list(close, current);
}

//remove the old current of the open list and add the new current to the open list
void replace_node_to_list(struct open_s **open, struct node_s *current)
{
    remove_from_list(open, current);
    *open = add_to_list(open, current);
}
