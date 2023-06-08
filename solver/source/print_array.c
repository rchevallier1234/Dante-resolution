/*
** EPITECH PROJECT, 2023
** dante
** File description:
** print_array
*/

#include "solver.h"

void print_array(char **array, int max_len)
{
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s" ,array[i]);
        if (array[i + 1] != NULL) {
            printf("\n");
        }
    }
}
