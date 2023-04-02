/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq
*/

#include "include/my.h"
#include "include/square_params.h"

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_square_of_size(char **map, params_t *pr)
{
    int i = 0, count = 0, begin_col = pr->y, row = pr->x, col = pr->y;
    if (map[row][col] == '.' && pr->sq_s == 1)
        return 1;
    while (i < ((pr->sq_s) * (pr->sq_s)) && row < pr->nb_r && col < pr->nb_c) {
        if (map[row][col] == 'o')
            return -1;
        if ((i + 1) % (pr->sq_s) == 0) {
            col = begin_col;
            row += 1;
            i += 1;
            continue;
        }
        if (map[row][col] == '.') {
            col += 1;
            count += 1; i += 1;
        }
    }
    if (count == ((pr->sq_s) * (pr->sq_s)) - (pr->sq_s))
        return count;
    return -1;
}

void display_result(char **map, params_t *pr)
{
    for (int i = pr->x0; i < (pr->x0 + pr->max); i += 1) {
        for (int j = pr->y0; j < (pr->y0 + pr->max); j += 1) {
            map[i][j] = 'x';
        }
    }
    my_show_word_array(map);
}

void bsq(char **map, params_t *pr)
{
    while (is_square_of_size(map, pr) > pr->max) {
        pr->max = pr->sq_s;
        pr->sq_s += 1;
        pr->x0 = pr->x;
        pr->y0 = pr->y;
    }
}

void free_map(char **map, params_t *pr)
{
    for (int i = 0; i < pr->nb_r; i += 1) {
        free(map[i]);
    }
    free(map);
    free(pr);
}

int main(int argc, char **argv)
{
    params_t *pr = malloc(sizeof(params_t));
    pr->max = 0; pr->sq_s = 1;
    char **map = NULL;
    if (argc < 2 || argc > 3)
        return 84;
    if (argc == 3) {
        map = generate_map(argv[1], argv[2], pr);
    } else
        map = load_2d_array_from_file(argv[1], pr);
    if (map == NULL)
        return 84;
    for (int x = 0; x < pr->nb_r; x += 1) {
        for (int y = 0; y < pr->nb_c; y += 1) {
            pr->x = x;
            pr->y = y;
            bsq(map, pr);
        }
    }
    display_result(map, pr); free_map(map, pr);
    return 0;
}
