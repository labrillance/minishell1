/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** clean_str.c
*/

#include "my.h"
#include <stdlib.h>

char *rm_n(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == ' ' || str[i] == '\n')
            str[i] = 0;
    }
    return str;
}

char *clean_str(char *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str));
    int x = 0;
    int y = 0;

    while (str[y] == ' ' || str[y] == '\t')
        y++;
    for (; str[y] != 0;) {
        if (y != 0 && ((str[y] == ' ' &&
            (str[y - 1] == ' ' || str[y - 1] == '\t'))
            || (str[y] == '\t' && (str[y - 1] == ' ' || str[y - 1] == '\t'))))
            y++;
        else if (str[y] == '\n')
            y++;
        else {
            result[x] = str[y];
            x++;
            y++;
        }
    }
    result[x] = 0;
    return result;
}
