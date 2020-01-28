/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_manage.c
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char **change_pwdname(char **env)
{
    int i = 0;
    char *new = NULL;
    size_t size = 1000;
    char *tmp = malloc(sizeof(char) * 100);

    tmp[0] = 'P';
    tmp[1] = 'W';
    tmp[2] = 'D';
    tmp[3] = '=';
    tmp[4] = 0;
    new = getcwd(new, size);
    while (env[i][0] != 'P' || env[i][1] != 'W' || env[i][2] != 'D')
        i++;
    env[i] = 0;
    env[i] = my_strcat(tmp, new);
    return env;
}

char **cpy_env_realloc(char **env, int i)
{
    char **new = malloc(sizeof(char *) * i + 2);

    for (int y = 0; env[y] != 0; y++) {
        new[y] = malloc(sizeof(char) * my_strlen(env[y]));
        new[y] = env[y];
    }
    new[i] = 0;
    return new;
}

char **set_new_env(char **env, char **opt)
{
    int i = 0;
    int y = 0;

    for (; env[i] != 0; i++);
    env = cpy_env_realloc(env, i);
    env[i] = malloc(sizeof(char) * my_strlen(opt[1]) * my_strlen(opt[2]));
    for (; opt[1][y] != 0; y++)
        env[i][y] = opt[1][y];
    env[i][y] = '=';
    y++;
    for (int x = 0; opt[2][x] != 0; x++, y++)
        env[i][y] = opt[2][x];
    env[i][y] = 0;
    env[i + 1] = 0;
    return env;
}

char **set_env(char **env, char **opt)
{
    int tmp = 0;
    int u = 0;
    int cmp = 0;

    for (int i = 0, y = 1; env[i] != 0; i++, y = 1, tmp = 0) {
        for (; env[i][y - 1] != '='; y++) {
            if (opt[1][y - 1] != env[i][y - 1])
                tmp = -1;
        }
        if (tmp == 0) {
            for (int u = 0; opt[2][u] != 0; y++, u++)
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

