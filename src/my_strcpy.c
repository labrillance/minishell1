/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** copies a string into another
*/

#include <stdlib.h>
#include <sys/wait.h>
#include "my.h"

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

char *bin_transform(char *str)
{
    int i = 2;
    int y = 0;
    char *new = malloc(sizeof(char) * my_strlen(str));

    if (str[0] == '.' && str[1] == '/') {
        while (str[i] != 0) {
            new[y] = str[i];
            i++;
            y++;
        }
        new[y] = 0;
    }
    new[y] = 0;
    return new;
}

int get_first_opt(char *str)
{
    int x = 0;

    while (str[x] != 0 && str[x] != ' ')
        x++;
    if (str[x] != 0)
        x++;
    return x;
}

char **get_opt(char *str)
{
    int i = 1;
    int y = 0;
    char **opt = malloc(sizeof(char *) * (i + 10));

    opt[i] = malloc(sizeof(char) * my_strlen(str));
    opt[1][0] = 0;
    for (int x = get_first_opt(str); str[x] != 0; x++) {
        if (str[x] != ' ' && str[x] != '\n') {
            opt[i][y] = str[x];
            y++;
        } if (str[x] == ' ') {
            opt[i][y] = 0;
            i++;
            opt[i] = malloc(sizeof(char) * my_strlen(str));
            y = 0;
        }
    } if (opt[1][0] != 0) {
        opt[i][y] = 0;
        i++;
    }
    opt[i] = 0;
    return opt;
}
