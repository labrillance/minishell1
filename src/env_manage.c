/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_manage.c
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char **print_env(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
    return env;
}

char **cpy_env_realloc(char **env, int i)
{
    char **new = malloc(sizeof(char *) * (i + 2));

    for (int y = 0; env[y] != 0; y++) {
        new[y] = malloc(sizeof(char) * my_strlen(env[y]));
        new[y] = env[y];
    }
    new[i] = 0;
    return new;
}

char **unset_env(char **env, char **opt)
{
    int tmp = 0;
    int cmp = 0;
    int i = 0;

    for (int y = 0; env[i] != 0 && cmp != 1; i++, y = 0, tmp = 0) {
        for (; env[i][y] != '=' && opt[1][y] != 0; y++) {
            if (opt[1][y] != env[i][y])
                tmp = -1;
        }
        if (tmp == 0) {
            cmp = 1;
        }
    }
    if (cmp == 1) {
        for (int x = i - 1; env[i] != 0; i++) {
            env[x] = env[i]; 
        }
    }
    env[i - 1] = 0;
    return env;
}

char **set_new_env(char **env, char **opt)
{
    int i = 0;
    int y = 0;

    for (; env[i] != 0; i++);
    env = cpy_env_realloc(env, i);
    if (opt[2] != NULL)
        env[i] = malloc(sizeof(char) * my_strlen(opt[1]) * my_strlen(opt[2]));
    else
        env[i] = malloc(sizeof(char) * my_strlen(opt[1]) + 2);
    for (; opt[1][y] != 0; y++)
        env[i][y] = opt[1][y];
    env[i][y] = '=';
    y++;
    if (opt[2] != NULL) {
        for (int x = 0; opt[2][x] != 0; x++, y++)
            env[i][y] = opt[2][x];
    }
    env[i][y] = 0;
    env[i + 1] = 0;
    return env;
}

char **set_env(char **env, char **opt)
{
    int tmp = 0;
    int cmp = 0;

    for (int i = 0, y = 0; env[i] != 0; i++, y = 0, tmp = 0) {
        for (; env[i][y] != '=' && opt[1][y] != 0; y++) {
            if (opt[1][y] != env[i][y] || (opt[1][y + 1] == 0 && env[i][y + 1] != '=') || (opt[1][y + 1] != 0 && env[i][y + 1] == '='))
                tmp = -1;
        }
        y++;
        if (tmp == 0) {
            for (int u = 0; opt[2] != NULL && opt[2][u] != 0; y++, u++)
                env[i][y] = opt[2][u];
            env[i][y] = 0;
            cmp = 1;
        }
    }
    if (cmp != 1) {
        env = set_new_env(env, opt);
    }
    return env;
}

