/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my.h
*/


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