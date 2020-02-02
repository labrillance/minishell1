/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** check_error.c
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void exe_error(int d, char *test)
{
    if (d == -1) {
    strerror(d);
        if (errno == 8) {
            my_putstr(test);
            my_putstr(": Exec format error. Wrong Architecture.\n");
            exit(0);
        }
    }
}

int check_error(int ac, char **av)
{
    if (ac > 1)
        return 84;
    if (av[1] != NULL)
        return 84;
    return 0;
}