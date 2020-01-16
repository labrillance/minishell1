/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int x = 0;
    int y = 0;

    for (x; dest[x] != '\0'; x++);
    for (y; src[y] != '\0'; y++) {
        dest [x] = src[y];
        x++;
    }
    return (dest);
}
