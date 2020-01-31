/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd_function_manage.c
*/

#include "my.h"

char **change_oldpdw(char **env, int y)
{
    int i = 0;
    int tmp = 0;
    int x = 7;

    for (; tmp == 0 && env != NULL && env[i] != NULL; i++) {
        if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' &&
            env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D' &&
            env[i][6] == '=')
            tmp = 1;
    }
    i = (i > 0) ? i - 1 : i;
    for (int cmp = 4; tmp != 0 && env[i] != NULL && env[y] != NULL && env[y][cmp] != 0; cmp++, x++)
        env[i][x] = env[y][cmp];
    if (i != 0 && tmp != 0)
        env[i][x] = 0;
    return env;
}

char *get_old_pdw(char **env)
{
    int i = 0;
    int tmp = 0;
    int x = 0;
    int y = 0;
    char *result = 0;

    for (; tmp == 0 && env != NULL && env[i] != NULL; i++) {
        if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' &&
            env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D' &&
            env[i][6] == '=')
            tmp = 1;
    }
    i--;
    result = malloc(sizeof(char) * my_strlen(env[i]));
    for (; env[i][x] != '='; x++);
    x++;
    for (; env[i][x] != 0; x++, y++)
        result[y] = env[i][x];
    result[y] = '/';
    result[y+ 1] = 0;
    return result;
}

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
    while (env[i] != NULL && (env[i][0] != 'P' ||   
        env[i][1] != 'W' || env[i][2] != 'D'))
        i++;
    env = change_oldpdw(env, i);
    env[i] = 0;
    env[i] = my_strcat(tmp, new);
    free(tmp);
    return env;
}

char *cd_options(char **opt, char **env)
{
    char *tmp = NULL;
    char *buf = NULL;
    size_t size = 1000;

    if (opt[1] != 0 && opt[1][0] != '/' && opt[1][0] != '~' && opt[1][0] != '-') {
        buf = getcwd(buf, size);
        buf = add_n(buf);
        tmp = malloc(sizeof(char) * my_strlen(buf) * 5);
        tmp[0] = 0;
        buf = my_strcat(buf, my_strcpy(tmp, opt[1]));
    } else if (opt[1] != NULL && opt[1][0] != '~' && opt[1][0] != '-') {
        tmp = malloc(sizeof(char) * my_strlen(opt[1]) * 2);
        tmp = my_strcpy(tmp, opt[1]);
    }
    if (opt[1] != NULL && opt[1][0] == '-' && opt[1][1] == 0)
        tmp = get_old_pdw(env);
    if (buf != NULL)
        tmp = my_strcpy(tmp, buf);
    free(buf);
    return tmp;
}

int my_cd(char **opt, char *str, char **env)
{
    char *tmp = NULL;

    if (str[0] == 'c' && str[1] == 'd' && str[2] == 0) {
        tmp = cd_options(opt, env);
        if (tmp != 0) {
            if (chdir(tmp) == -1)
                perror("cd ");
        } if (tmp == 0 || opt[1][0] == '~')
            chdir(get_home(env));
        env = change_pwdname(env);
        return 1;
    }
    return 0;
}