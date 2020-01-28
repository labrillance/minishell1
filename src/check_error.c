/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** check_error.c
*/

#include "my.h"

int check_error(int ac, char **av)
{
    if (ac > 1)
        return 84;
    if (av[1] != NULL)
        return 84;
    return 0;
}