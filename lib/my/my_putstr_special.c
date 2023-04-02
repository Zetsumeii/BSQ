/*
** EPITECH PROJECT, 2022
** special putstr
** File description:
** ouais
*/

#include <unistd.h>

void my_putstr_special(char *str, int bytes)
{
    write(1, str, bytes);
}
