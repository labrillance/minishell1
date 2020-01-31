/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** no_path_parting.c
*/

#include "my.h"
#include <sys/stat.h>

void transform_str(char **test, char ***opt)
{
    *test = clean_str(*test);
    *opt = get_opt(*test);
    *test = rm_n(*test);
}

char *binary_manage(char *str, char *tmp)
{
    struct stat st;
    char *buf = malloc(sizeof(char) * 100);
    size_t size = 1000;

    getcwd(buf, size);
    buf = my_strcat(buf, "/");
    stat(my_strcat(buf, tmp), &st);
    if (st.st_mode & S_IFDIR) {
        my_putstr(tmp);
        my_putstr(": Permission denied.\n");
        return NULL;
    }
    if (str == NULL && access(tmp, X_OK) == -1) {
        my_putstr(my_strcat(tmp, ": Command not found.\n"));
        return NULL;
    } else if (access(tmp, X_OK) != -1)
        return tmp;
    else
        return str;
}