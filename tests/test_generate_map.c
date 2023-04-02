/*
** EPITECH PROJECT, 2022
** ouais
** File description:
** ouais
*/

#include <criterion/criterion.h>
#include "../include/square_params.h"
#include <stdlib.h>

char **generate_map(char *nb_rows, char *pattern, params_t *pr);

Test(generate_map1, square_even) {
    params_t *pr = malloc(sizeof(params_t));
    char *result[3] = {"...", "...", "..."};
    char **test = generate_map("3", "...", pr);
    cr_assert_str_eq(result[0], test[0]);
    cr_assert_str_eq(result[1], test[1]);
    cr_assert_str_eq(result[2], test[2]);
}
