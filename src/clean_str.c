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
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            str[i] = 0;
    }
    return str;
}

char *clean_str(char *str)
{
    char *res = malloc(sizeof(char) * my_strlen(str));
    int x = 0;
    int y = 0;

    for (; str[y] == ' ' || str[y] == '\t'; y++);
    for (; str[y] != 0;) {
        if (y != 0 && ((str[y] == ' ' &&
            (str[y - 1] == ' ' || str[y - 1] == '\t'))
            || (str[y] == '\t' && (str[y - 1] == ' ' || str[y - 1] == '\t'))))
            y++;
        else if (str[y] == '\n')
            y++;
        else {
            res[x] = str[y];
            x++;
            y++;
        }
    }
    res[x - 1] = (res[x - 1] == '\t' || res[x - 1] == ' ') ? 0 : res[x - 1];
    res[x] = 0;
    return res;
}