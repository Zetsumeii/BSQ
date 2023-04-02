/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** ouais
*/

char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    for (i = 0; src[i] != '\0'; i = i + 1) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
