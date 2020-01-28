/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** shell_manage.c
*/

#include "my.h"

int built_in_functions(char **test, char ***opt, char ***env)
{
    if (my_cd(*opt, *test, *env) == 1) {
        return 1;
    }
    if (my_strcmp(*test, "setenv") == 0) {
        *env = set_env(*env, *opt);
        return 1;
    }
    if (my_strcmp(*test, "unsetenv") == 0) {
        *env = unset_env(*env, *opt);
        return 1;
    }
    if (my_strlen(*test) == 4 && (*test)[0] == 'e' && (*test)[1] == 'x' &&
        (*test)[2] == 'i' && (*test)[3] == 't' && (*test)[4] == 0)
        return 0;
    return 2;
}

int manage_shell(char **test, char ***opt, char ***env, char ***tab)
{
    size_t s = 100;
    int tmp = 0;

    *tab = get_path(*env);
    my_putstr("$>");
    if (getline(test, &s, stdin) == -1)
        return 0;
    *test = clean_str(*test);
    *opt = get_opt(*test);
    *test = rm_n(*test);
    if ((*test)[0] != 0) {
        tmp = built_in_functions(test, opt, env);
        if (tmp != 2)
            return tmp;
        *test = is_good_bin(*test, *tab);
        *opt[0] = *test;
        return 2;
    }
    return 1;
}

void my_sig_trap(pid_t pid, int status)
{
    waitpid(pid, &status, 0);
    if (status == 11)
        write(1, "Segmentation fault\n", 19);
    if (status == 139)
        write(1, "Segmentation fault (core dumped)\n", 33);
}

int my_shell(char **tab, char **old_env)
{
    char *test = NULL;
    int tmp = 0;
    int status = 0;
    pid_t pid;
    char **opt = NULL;
    static char **env = NULL;

    env = (env == NULL) ? cpy_env(old_env) : env;
    tmp = manage_shell(&test, &opt, &env, &tab);
    if (tmp != 2)
        return tmp;
    if (test != NULL) {
        pid = fork();
        if (pid == 0)
            execve(test, opt, env);
        else
            my_sig_trap(pid, status);
    }
    free(opt);
    free(test);
    return 1;
}