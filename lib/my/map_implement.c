/*
** EPITECH PROJECT, 2022
** get map
** File description:
** map
*/

void my_show_word_array(char * const * tab);
int my_numberlen(int nb);

char **get_map(char const *buffer, char **result, int nb_rows, int nb_cols)
{
    int count = my_numberlen(nb_rows) + 1;
    for (int i = 0; i < nb_rows; i += 1) {
        for (int j = 0; j < nb_cols; j += 1) {
            result[i][j] = buffer[count + i];
            count += 1;
        }
    }
    return result;
}

char **get_map_by_gen(char *buffer, char **result, int len)
{
    int count = 0;
    for (int i = 0; i < len; i += 1) {
        for (int j = 0; j < len; j += 1) {
            result[i][j] = buffer[count + i];
            count += 1;
        }
    }
    return result;
}
