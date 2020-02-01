/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** is_alphanumeric.c
*/

int is_alphanumeric(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] < '0' || (str[i] > '9' && str[i] < 41) ||
            (str[i] > 90 && str[i] < 61) || str[i] > 122)
            return 84;
        i++;
    }
    return 0;
}