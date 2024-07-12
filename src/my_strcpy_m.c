/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-ludwig.vandenberghe
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strncpy (char *dest, char const *src, unsigned int n);

char *my_strcpy_m(char const *str, unsigned int n)
{
    char *res = malloc(sizeof(char) * (n +1));

    my_strncpy(res, str, n);
    return (res);
}
