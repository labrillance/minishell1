/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/signal.h>


char *check_repo_act(char *str)
{
    DIR *src;
    struct dirent *info;
    char *cmp = NULL;
    size_t size = 100;
    int tmp = 0;

    str = bin_transform(str);
    cmp = getcwd(cmp, size);
    cmp = add_n(cmp);
    src = opendir(cmp);
    info = readdir(src);
    while (info != NULL) {
        while (str[tmp] != 0 && info->d_name[tmp] != 0 &&
            str[tmp] == info->d_name[tmp])
            tmp++;
        if (tmp == my_strlen(str) && str[tmp] == 0 && info->d_name[tmp] == 0)
            return my_strcat(cmp, info->d_name);
        info = readdir(src);
    }
    return NULL;
}

char *is_good_bin_bis(char *str, char **path, DIR *src, int i)
{
    char *cmp = malloc(sizeof(char) * 1000);
    struct dirent *info;

    info = readdir(src);
    for (int tmp = 0; info != NULL; tmp = 0, info = readdir(src)) {
        while (str[tmp] != 0 && info->d_name[tmp] != 0 &&
            str[tmp] == info->d_name[tmp])
            tmp++;
        if (tmp == my_strlen(str) && str[tmp] == 0 &&
            info->d_name[tmp] == 0) {
            cmp = my_strcpy(cmp, path[i]);
            return my_strcat(cmp, info->d_name);
        }
    }
    return NULL;
}

char *is_good_bin(char *str, char **path)
{
    DIR *src;
    char *cmp = malloc(sizeof(char) * 1000);
    char *tmp = malloc(sizeof(char) * my_strlen(str));

    tmp = my_strcpy(tmp, str);
    for (int i = 0; path != NULL && path[i] != NULL; i++) {
        src = opendir(path[i]);
        if (src != NULL) {
            cmp = is_good_bin_bis(str, path, src, i);
            if (cmp != NULL)
                return cmp;
        }
    }
    str = check_repo_act(str);
    if (str == NULL && access(tmp, X_OK) == -1) {
        my_putstr(my_strcat(tmp, ": Command not found.\n"));
        return NULL;
    } else if (access(tmp, X_OK) != -1)
        return tmp;
    else
        return str;
}

int main(int ac, char **av, char **env)
{
    char **tab;
    int i = 1;

    if (check_error(ac, av) == 84)
        return 84;
    tab = get_path(env);
    while (i == 1) {
        i = my_shell(tab, env);
    }
}