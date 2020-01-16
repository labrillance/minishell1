/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

char **my_str_to_tab(char *str, char s)
{
    char **tab = malloc(sizeof(char *) * my_strlen(str));
    int i = 0;
    int y = 0;

    for (int x = 5; str[x] != 0; x++, y++) {
        if (y == 0)
            tab[i] = malloc(sizeof(char) * my_strlen(str) + 1);
        if (str[x] != s)
            tab[i][y] = str[x];
        else {
            tab[i][y] = '/';
            tab[i][y + 1] = 0;
            y = -1;
            i++;
        }
    }
    tab[i] = 0;
    return tab;
}

char **get_path(char **env)
{
    int i = 0;
    char **tab;

    for (; env[i] != 0; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' &&
            env[i][2] == 'T' && env[i][3] == 'H') {
            tab = my_str_to_tab(env[i], ':');
        }
    }
    return tab;
}

char *rm_n(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == ' ' || str[i] == '\n')
            str[i] = 0;
    }
    return str;
}

char **get_opt(char *str)
{
    char **opt = malloc(sizeof(char *) * my_strlen(str));
    int i = 1;
    int x = 0;

    opt[0] = malloc(sizeof(char) * my_strlen(str));
    while (str[x] != 0 && str[x] != ' ') {
        opt[0][x] = str[x];
        x++;
    }
    x++;
    for (int y = 0; str[x] != 0; ) {
        if (y == 0)
            opt[i] = malloc(sizeof(char) * my_strlen(str));
        if (str[x] != ' ' && str[x] != '\n')
            opt[i][y] = str[x];
        else {
            opt[i][y] = 0;
            i++;
            y = -1;
        }
        x++;
        y++;
    }
    opt[i + 1] = 0;
    return opt;
}

char *is_good_bin(char *str, char **path)
{
    DIR *src;
    struct dirent *info;
    int tmp = 0;

    for (int i = 0; path[i] != NULL; i++, tmp = 0) {
        src = opendir(path[i]);
        if (src != NULL)
            info = readdir(src);
        while (info != NULL) {
            while (str[tmp] != 0 && info->d_name[tmp] != 0 && str[tmp] == info->d_name[tmp])
                tmp++;
            if (tmp == my_strlen(str) && str[tmp] == 0 && info->d_name[tmp] == 0)
                return my_strcat(path[i], info->d_name);
            info = readdir(src);
            tmp = 0;
        }
    }
    return NULL;
}

int my_shell(char **tab, char **env, char **av)
{
    char *test = NULL;
    ssize_t s = 10;
    int status;
    pid_t pid;
    char **opt = NULL;

    my_putstr("$>");
    getline(&test, &s, stdin);
    opt = get_opt(test);
    test = rm_n(test);
    if (test[0] == 'e' && test[1] == 'x' && test[2] == 'i' && test[3] == 't' && test[4] == 0)
        return 0;
    test = is_good_bin(test, tab);
    if (test != NULL) {
        pid = fork();
        if (pid == 0)
            execve(test, opt, env);
        else
            wait(&status);
    }
    return 1;
}

int main(int ac, char **av, char **env)
{
    char **tab;
    int i = 1;
    char *test = NULL;

    tab = get_path(env);
    while (i == 1) {
        i = my_shell(tab, env, av);
    }
}