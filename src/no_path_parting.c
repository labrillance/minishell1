/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** no_path_parting.c
*/

void transform_str(char **test, char ***opt)
{
    *test = clean_str(*test);
    *opt = get_opt(*test);
    *test = rm_n(*test);
}