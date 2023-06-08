/*
** EPITECH PROJECT, 2023
** dante
** File description:
** solver_header
*/

#ifndef SOLVER
    #define SOLVER

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>

typedef struct s_maze {
    char **maze;
    int cols;
    int row;
    int nb_move;
    int nb_min;
} t_maze;

struct node_s {
    struct node_s *parent;
    int row;
    int cols;
    int move;
    int move_left;
};

struct node2_s {
    struct node2_s *parent;
    int row;
    int cols;
};

struct open_s {
    struct node_s *node;
    struct open_s *next;
};

struct open2_s {
    struct node2_s *node;
    struct open2_s *next;
};

int get_argv(t_maze *maze, char **argv, int argc);
int error_maze(t_maze *maze);
char **my_str_to_word_array(char *str, char separator);
int my_array_len(char **array);
void print_array(char **array, int max_col);
void replace_x(char **array, int row, int col);
struct open_s *add_to_list(struct open_s **list, struct node_s *node);
int is_a_sorter_path(struct open_s *open, int row, int cols,
    struct node_s *neighbour);
int is_in_closed(struct open_s *close, int row, int cols);
struct node_s *find_lowest_f_cost(struct open_s *open);
struct open_s *creat_neighbour_main(struct open_s *open, struct open_s *close,
    struct node_s *current, char **maze);
void move_to_closed(struct open_s **open, struct open_s **close,
    struct node_s *current);
struct open_s *add_to_list(struct open_s **list, struct node_s *node);
void remove_from_list(struct open_s **list, struct node_s *current);
void replace_node_to_list(struct open_s **open, struct node_s *current);
struct node_s *a_star(t_maze *maze);
struct node2_s *depth_first(t_maze *maze);
void dfs_move_to_closed(struct open2_s **open, struct node2_s *current);
struct open2_s *dfs_create_neighbour_main(struct open2_s *open,
    struct node2_s *current, char **maze);
struct open2_s *dfs_add_to_list(struct open2_s **list, struct node2_s *node);
int find_nb_option(char **array, int row, int col);
int chose_way(t_maze *maze);

#endif
