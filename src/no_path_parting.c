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
    if ((*test)[0] == '\n')
        *test = NULL;
    else {
        *test = clean_str(*test);
        *opt = get_opt(*test);
        *test = rm_n(*test);
    }
}

char *binary_manage_bis(char *str, char *tmp, struct stat st, char *buf)
{
    if (str == NULL && access(tmp, X_OK) == -1) {
        my_putstr(my_strcat(tmp, ": Command not found.\n"));
        free(tmp);
        free(str);
        return NULL;
    } if (stat(my_strcat(buf, tmp), &st) == -1) {
        free(tmp);
        free(str);
        return NULL;
    } if (st.st_mode & S_IFDIR) {
        my_putstr(tmp);
        my_putstr(": Permission denied.\n");
        return NULL;
    } else if (access(tmp, X_OK) != -1)
        return tmp;
    else
        return str;
}

char *binary_manage(char *str, char *tmp)
{
    struct stat st;
    char *buf = NULL;
    char *cmp = malloc(sizeof(char) * 100);
    size_t size = 1000;

    buf = getcwd(buf, size);
    cmp = my_strcpy(cmp, buf);
    cmp = my_strcat(buf, "/");
    free(buf);
    return binary_manage_bis(str, tmp, st, buf);
}