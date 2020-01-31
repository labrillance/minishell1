/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** error_handling.c
*/

#include "my.h"

int check_env_errors(char *str, char **opt)
{
    if (my_strcmp(str, "setenv") == 0 && opt[3] != NULL) {
        my_putstr("setenv: Too many arguments.\n");
        return 84;
    }
    if (my_strcmp(str, "unsetenv") == 0 && opt[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 84;
    }
    if (my_strcmp(str, "setenv") == 0 && (opt[1][0] >= '0' &&
        opt[1][0] <= '9')) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 84;
    }
    if (my_strcmp(str, "setenv") == 0 && is_alphanumeric(opt[1]) == 84) {
        my_putstr("setenv: Variable name must contain");
        my_putstr(" alphanumeric characters.\n");
        return 84;
    }
    return 0;
}