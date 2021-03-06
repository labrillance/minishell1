/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my.h
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

char *my_strcat(char *dest, char const *src);
char **change_pwdname(char **env);
char *get_home(char **env);
char *add_n(char *str);
int my_cd(char **opt, char *str, char **env);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_putstr(char const *str);
char **get_path(char **env);
char *rm_n(char *str);
char **get_opt(char *str);
char **my_str_to_tab(char *str, char s);
char **cpy_env(char **env);
char *bin_transform(char *str);
char *clean_str(char *str);
void my_putchar(char c);
int get_first_opt(char *str);
int check_error(int ac, char **av);
int my_shell(char **tab, char **old_env);
int my_strcmp(char const *nb1, char const *nb2);
char **set_env(char **env, char **opt);
char **unset_env(char **env, char **opt);
char *is_good_bin(char *str, char **path);
void exe_error(int d, char *test);
int check_env_errors(char *str, char **opt);
int check_env_errors_bis(char *str, char **opt);
char *binary_manage(char *str, char *tmp);
void transform_str(char **test, char ***opt);
int is_alphanumeric(char *str);
char **print_env(char **env);
