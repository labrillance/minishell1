/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** copies a string into another
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char **get_path(char **env)
{
    int i = 0;
    char **tab;

    for (; env[i] != 0; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' &&
            env[i][2] == 'T' && env[i][3] == 'H') {
            tab = my_str_to_tab(env[i], ':');
        }
    }
    return tab;
}

char *rm_n(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == ' ' || str[i] == '\n')
            str[i] = 0;
    }
    return str;
}

char **get_opt(char *str)
{
    char **opt = malloc(sizeof(char *) * my_strlen(str));
    int i = 1;
    int x = 0;
    int u = 2;

    opt[0] = malloc(sizeof(char) * my_strlen(str));
    opt[0][0] = '.';
    opt[0][1] = '/';
    while (str[x] != 0 && str[x] != ' ') {
        opt[0][u] = str[x];
        x++;
        u++;
    }
    x++;
    for (int y = 0; str[x] != 0; ) {
        if (y == 0)
            opt[i] = malloc(sizeof(char) * my_strlen(str));
        if (str[x] != ' ' && str[x] != '\n')
            opt[i][y] = str[x];
        else {
            opt[i][y] = 0;
            i++;
            y = -1;
        }
        x++;
        y++;
    }
    opt[i + 1] = 0;
    return opt;
}
