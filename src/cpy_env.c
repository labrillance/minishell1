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

    while (env[i][0] != 'H' || env[i][1] != 'O' ||
        env[i][2] != 'M' || env[i][3] != 'E')
        i++;
    while (env[i][y] != 0) {
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

int my_cd(char **opt, char *str, char **env)
{
    char *tmp = NULL;
    char *buf = NULL;
    size_t size = 1000;

    if (str[0] == 'c' && str[1] == 'd' && str[2] == 0) {
        if (opt[1] != 0 && opt[1][0] != '/' && opt[1][0] != '~') {
            buf = getcwd(buf, size);
            buf = add_n(buf);
            tmp = malloc(sizeof(char) * my_strlen(buf) * 2);
            tmp[0] = 0;
            buf = my_strcat(buf, my_strcpy(tmp, opt[1]));
        } else if (opt[1] != NULL && opt[1][0] != '~') {
            tmp = malloc(sizeof(char) * my_strlen(opt[1]) * 2);
            tmp = my_strcpy(tmp, opt[1]);
        }
        if (buf != NULL)
            tmp = my_strcpy(tmp, buf);
        free(buf);
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