/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** coucou
*/

#include "my.h"

int my_strcmp(char const *nb1, char const *nb2)
{
    int i = 0;
    int j = 0;

    if (nb1[i] == '-')
        i++;
    else if (nb2[j] == '-')
        j++;
    if (my_strlen(nb1) < my_strlen(nb2))
        return (-1);
    if (my_strlen(nb1) > my_strlen(nb2))
        return (1);
    while ((nb1[i] != '\0' || nb2[j] != '\0') && nb1[i] == nb2[j]) {
        j++;
        i++;
    }
    if (nb1[i] < nb2[j])
        return (-1);
    else if (nb1[i] > nb2[j])
        return (1);
    else
        return (0);
}
