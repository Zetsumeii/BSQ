/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** ouais
*/

#include <stddef.h>

void my_putchar(char c);
int my_putstr(char *str);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i = i + 1) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
