/*
** EPITECH PROJECT, 2022
** load array
** File description:
** load the map
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../include/square_params.h"

char **get_map(char const *buffer, char **result, int nb_rows, int nb_cols);
int my_show_word_array(char * const * tab);
int my_strlen(char *str);

int get_nb_cols(char *buffer)
{
    int nb_cols = 0;
    int index = 0;
    for (int i = 0; buffer[i] != '\n'; i += 1)
        index += 1;
    for (int x = index + 1; buffer[x] != '\n'; x += 1)
        nb_cols += 1;
    return nb_cols;
}

int get_nb_rows(char *buffer)
{
    int nb_rows = 0;
    for (int i = 0; buffer[i] != '\n'; i += 1) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            nb_rows = nb_rows * 10;
            nb_rows += (buffer[i] - '0');
        }
    }
    return nb_rows;
}

int fd_is_valid(char const *filepath)
{
    int fd = open(filepath, 0);
    if (fd == -1)
        return -1;
    return fd;
}

int verif_map(char *buffer)
{
    int start = 0;
    for (int i = 0; buffer[i] != '\n'; i += 1)
        start += 1;
    for (int i = start + 1; buffer[i] != '\0'; i += 1) {
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n'
                && buffer[i] != '\0')
            return -1;
    }
    return 0;
}

char **load_2d_array_from_file(char const *filepath, params_t *pr)
{
    struct stat st;
    int fd = fd_is_valid(filepath);
    if (fd == -1)
        return NULL;
    if (stat(filepath, &st) == -1 || st.st_size <= 0)
        return NULL;
    char *buffer = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, buffer, (st.st_size));
    if (verif_map(buffer) == -1)
        return NULL;
    pr->nb_c = get_nb_cols(buffer); pr->nb_r = get_nb_rows(buffer);
    char **result = malloc(sizeof(char *) * (pr->nb_r + 1));
    result[pr->nb_r] = NULL;
    for (int tab = 0; tab < pr->nb_r; tab += 1) {
        result[tab] = malloc(sizeof(char) * (pr->nb_c + 1));
        result[tab][pr->nb_c] = '\0';
    }
    get_map(buffer, result, pr->nb_r, pr->nb_c);
    free(buffer);
    return result;
}
