/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-ludwig.vandenberghe
** File description:
** my_strdp
*/

#include "my.h"

char *my_strdup(char const *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) +1));

    my_strncpy(res, str, my_strlen(str));
    return (res);
}
