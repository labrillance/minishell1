/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** parting_options.c
*/

#include "my.h"

char **my_str_to_tab(char *str, char s)
{
    char **tab = malloc(sizeof(char *) * my_strlen(str));
    int i = 0;
    int y = 0;

    for (int x = 5; str[x] != 0; x++, y++) {
        if (y == 0)
            tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
        if (str[x] != s && str[x] != '\n')
            tab[i][y] = str[x];
        else {
            tab[i][y] = '/';
            tab[i][y + 1] = 0;
            y = -1;
            i++;
        }
    }
    tab[i][y] = '/';
    tab[i + 1] = 0;
    return tab;
}

void fix_end_opt(char ***opt, int *i, int y)
{
    if ((*opt)[1][0] != 0) {
        (*opt)[*i][y] = 0;
        (*i)++;
    }
    (*opt)[*i] = 0;
}

char **get_opt(char *str)
{
    int i = 1;
    int y = 0;
    char **opt = malloc(sizeof(char *) * (i + 10));

    opt[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int x = get_first_opt(str); str[x] != 0; x++) {
        if (str[x] != ' ' && str[x] != '"') {
            opt[i][y] = str[x];
            y++;
        } if (str[x] == ' ') {
            opt[i][y] = 0;
            i++;
            opt[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
            y = 0;
        } else if (str[x] == '"') {
            for (x++; str[x] != '"' && str[x] != 0 ; x++, y++)
                opt[i][y] = str[x];
        }
    }
    fix_end_opt(&opt, &i, y);
    return opt;
}