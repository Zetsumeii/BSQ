/*
** EPITECH PROJECT, 2022
** ouais
** File description:
** ouais
*/

#include <criterion/criterion.h>

int my_strlen(char *str);

Test(my_strlen1, len10) {
    int len = my_strlen("0123456789");
    cr_assert_eq(len, 10);
}
