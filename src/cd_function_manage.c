/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd_function_manage.c
*/

#include "my.h"

char *get_old_pdw_bis(int true, char *tmp, char **op, int *cmp)
{
    size_t size = 1000;

    if (tmp == NULL && true == 1) {
        tmp = getcwd(tmp, size);
        my_putstr("cd : No such file or directory.\n");
    }
    if (true == 0 && *cmp != 1 && (op[1] == NULL || op[1][0] == '~'))
        tmp = getcwd(tmp, size);
    return tmp;
}

char *get_old_pdw(int true, char *test, char **op)
{
    static char *tmp = NULL;
    char *result = malloc(sizeof(char) * 1000);
    size_t size = 1000;
    static int cmp = 0;

    tmp = get_old_pdw_bis(true, tmp, op, &cmp);
    if (true == 0 && cmp != 1 && access(test, F_OK) != -1)
        tmp = getcwd(tmp, size);
    if (true == 1) {
        result = my_strcpy(result, tmp);
        tmp = getcwd(tmp, size);
        cmp = 1;
        chdir(result);
        return "p";
    }
    cmp = 0;
    return NULL;
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
    env[i] = 0;
    env[i] = my_strcat(tmp, new);
    return env;
}

char *cd_options(char **op)
{
    char *tmp = NULL;
    char *buf = NULL;
    size_t size = 1000;

    if (op[1] != 0 && op[1][0] != '/' && op[1][0] != '~' && op[1][0] != '-') {
        buf = getcwd(buf, size);
        buf = add_n(buf);
        tmp = malloc(sizeof(char) * my_strlen(buf) * 5);
        tmp[0] = 0;
        buf = my_strcat(buf, my_strcpy(tmp, op[1]));
    } else if (op[1] != NULL && op[1][0] != '~' && op[1][0] != '-') {
        tmp = malloc(sizeof(char) * my_strlen(op[1]) * 2);
        tmp = my_strcpy(tmp, op[1]);
    }
    if (op[1] != NULL && op[1][0] == '-' && op[1][1] == 0)
        tmp = get_old_pdw(1, tmp, op);
    get_old_pdw(0, tmp, op);
    if (buf != NULL)
        tmp = my_strcpy(tmp, buf);
    free(buf);
    return tmp;
}

int my_cd(char **opt, char *str, char **env)
{
    char *tmp = NULL;

    if (str[0] == 'c' && str[1] == 'd' && str[2] == 0) {
        tmp = cd_options(opt);
        if (tmp != 0 && tmp[0] != 'p') {
            if (chdir(tmp) == -1)
                perror("cd ");
        } if (tmp == 0 || opt[1][0] == '~')
            chdir(get_home(env));
        env = change_pwdname(env);
        return 1;
    }
    return 0;
}