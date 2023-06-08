/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main_solver
*/

#include "solver.h"

//displays the maze solved by a-star

void display_solved(struct node_s *current, t_maze *maze)
{
    if (current != NULL) {
        maze->maze[0][0] = 'o';
        while (current->parent != NULL) {
            maze->maze[current->row][current->cols] = 'o';
            current = current->parent;
        }
        print_array(maze->maze, maze->cols);
    }
}

//displays the maze solved by depth_first

void display_solved2(struct node2_s *current, t_maze *maze)
{
    if (current != NULL) {
        maze->maze[0][0] = 'o';
        while (current->parent != NULL) {
            maze->maze[current->row][current->cols] = 'o';
            current = current->parent;
        }
        print_array(maze->maze, maze->cols);
    }
}

//replaces the c by * in the maze

void clean_maze(t_maze *maze)
{
    for (int row = 0; maze->maze[row] != NULL; row++) {
        for (int cols = 0; maze->maze[row][cols] != '\0'; cols++) {
            maze->maze[row][cols] = (maze->maze[row][cols] == 'c')
                ? '*' : maze->maze[row][cols];
        }
    }
}

// selected the right solver according to the size of the maze

void chose_solver(t_maze *maze, struct node_s **current,
    struct node2_s **current2)
{
    if (maze->cols + maze->row <= 160) {
        *current = a_star(maze);
    } else {
        *current2 = depth_first(maze);
        clean_maze(maze);
    }
}

int main(int argc, char **argv)
{
    t_maze maze;
    struct node_s *current = NULL;
    struct node2_s *current2 = NULL;

    if (get_argv(&maze, argv, argc) == 84 || error_maze(&maze) == 84) {
        exit(84);
    }
    chose_solver(&maze, &current, &current2);
    display_solved2(current2, &maze);
    display_solved(current, &maze);
    exit(0);
}
