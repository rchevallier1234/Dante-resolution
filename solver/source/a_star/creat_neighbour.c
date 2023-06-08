/*
** EPITECH PROJECT, 2023
** dante_solver
** File description:
** creat_neighbour
*/

#include "solver.h"

//get the position of the neighbour

void creat_neighbour_get_pos(struct node_s **neighbour, struct node_s *current,
    int pos)
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

struct open_s *creat_neighbour_set(struct open_s *open,
    struct node_s *current, int pos)
{
    struct node_s *neighbour = NULL;

    neighbour = malloc(sizeof(struct node_s));
    creat_neighbour_get_pos(&neighbour, current, pos);
    neighbour->move = current->move + 1;
    neighbour->move_left = neighbour->cols + neighbour->row;
    if (is_in_closed(open, neighbour->row, neighbour->cols) != 1 ||
        is_a_sorter_path(open, neighbour->row, neighbour->cols, neighbour)
            == 1) {
        neighbour->parent = current;
        if (is_in_closed(open, neighbour->row, neighbour->cols) == 0) {
            add_to_list(&open, neighbour);
            return open;
        }
        if (is_a_sorter_path(open, neighbour->row, neighbour->cols, neighbour)
            == 1) {
            replace_node_to_list(&open, neighbour);
        }
    }
    return open;
}

//create a new neighbour if is not a wall and if is not in the closed list

struct open_s *creat_neighbour_main(struct open_s *open, struct open_s *close,
    struct node_s *current, char **maze)
{
    if (maze[current->row][current->cols + 1] == '*' &&
        is_in_closed(close, current->row, current->cols + 1) != 1) {
        open = creat_neighbour_set(open , current, 3);
    }
    if ((maze[current->row + 1] != 0) &&
        (maze[current->row + 1][current->cols] == '*')
        && is_in_closed(close, current->row + 1, current->cols) != 1) {
        open = creat_neighbour_set(open , current, 4);
    }
    if (current->cols >= 0 && maze[current->row][current->cols - 1] == '*'
        && is_in_closed(close, current->row, current->cols - 1) != 1) {
        open = creat_neighbour_set(open, current, 1);
    }
    if (current->row > 0 &&
        (maze[current->row - 1][current->cols] == '*')
        && is_in_closed(close, current->row - 1, current->cols) != 1) {
        open = creat_neighbour_set(open, current, 2);
    }
    return (open);
}
