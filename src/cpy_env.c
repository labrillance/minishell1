/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cpy_env.c
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char *get_home(char **env)
{
    char *result = malloc(sizeof(char) * 100);
    int i = 0;
    int y = 0;
    int x = 0;
    int tmp = 0;

    while (env[i] != NULL && (env[i][0] != 'H' || env[i][1] != 'O' ||
        env[i][2] != 'M' || env[i][3] != 'E'))
        i++;
    while (env[i] != 0 && (env[i][y] != 0)) {
        while (tmp == 0 && env[i][y - 1] != '=')
            y++;
        tmp = 1;
        result[x] = env[i][y];
        y++;
        x++;
    }
    result[x] = 0;
    return result;
}

char *add_n(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        i++;
    }
    if (str[i - 1] != '/') {
        str[i] = '/';
        str[i + 1] = 0;
    }
    return str;
}

char **cpy_env(char **env)
{
    int i = 0;
    char **result = malloc(sizeof(char *) * 100);

    while (env[i] != 0) {
        result[i] = env[i];
        i++;
    }
    result[i] = 0;
    return result;
}