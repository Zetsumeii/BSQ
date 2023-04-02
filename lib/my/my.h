/*
** EPITECH PROJECT, 2022
** myh
** File description:
** ouais
*/

#include "square_params.h"

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_putstr(char *str);
int fd_is_valid(char const *filepath);
int get_buff_size(int fd);
int get_nb_cols(char const *buffer);
int get_nb_rows(char const *buffer);
char *verif_gen_map(char *buffer);
char **load_2d_array_from_file(char const *filepath, params_t *pr);
char **get_map(char const *buffer, char **result, int nb_rows, int nb_cols);
char **get_map_by_gen(char *buffer, char **result, int len);
char *get_buffer(char *pattern, int nb_row);
char **generate_map(char *nb_rows, char *pattern, params_t *pr);
int my_strlen(char const *str);
int my_show_word_array(char * const * tab);
int my_numberlen(int nb);
char *my_strcpy(char *dest, char *src);
void my_putstr_special(char *str, int bytes);

#endif // MY_H_
