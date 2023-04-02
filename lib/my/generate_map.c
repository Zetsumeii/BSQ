/*
** EPITECH PROJECT, 2022
** generate maps bsq
** File description:
** ouais
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../include/square_params.h"

int my_strlen(char *str);
char **get_map(char const *buffer, char **result, int nb_rows, int nb_cols);
char **get_map_by_gen(char *buffer, char **result, int len);

int verif_gen_map(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i += 1) {
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n'
                && buffer[i] != '\0')
            return -1;
    }
    return 0;
}

int get_nb_rows2(char *nb_row)
{
    int nb_rows = 0;
    for (int i = 0; nb_row[i] != '\0'; i += 1) {
        if (nb_row[i] < 48 || nb_row[i] > 57 || nb_row[0] == '\0')
            return -1;
        nb_rows = nb_rows * 10;
        nb_rows += nb_row[i] - '0';
    }
    return nb_rows;
}

char *get_buffer(char *pattern, int nb_row)
{
    int len = (nb_row * nb_row) + nb_row;
    char *buffer = malloc(sizeof(char) * (len + 1));
    int pattern_len = my_strlen(pattern);
    int j = 0;
    buffer[len] = '\0';
    for (int i = 1; i < len; i += 1) {
        if (j == pattern_len)
            j = 0;
        if (i % (nb_row + 1) == 0 && i != 0) {
            buffer[i - 1] = '\n';
            i += 1;
        }
        buffer[i - 1] = pattern[j];
        j += 1;
    }
    return buffer;
}

char **generate_map(char *nb_row, char *pattern, params_t *pr)
{
    int len = get_nb_rows2(nb_row);
    if (len == -1 || pattern == NULL || len == 0)
        return NULL;
    char *buffer = get_buffer(pattern, len);
    if (verif_gen_map(buffer) == -1 || verif_gen_map(pattern) == -1)
        return NULL;
    pr->nb_r = len;
    pr->nb_c = len;
    char **result = malloc(sizeof(char *) * (pr->nb_r + 1));
    result[pr->nb_r] = NULL;
    for (int tab = 0; tab < pr->nb_r; tab += 1) {
        result[tab] = malloc(sizeof(char) * (pr->nb_c + 1));
        result[tab][pr->nb_c] = '\0';
    }
    get_map_by_gen(buffer, result, len);
    free(buffer);
    return result;
}
