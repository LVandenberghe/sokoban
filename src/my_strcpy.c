/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-ludwig.vandenberghe
** File description:
** my_strcpy
*/

#include <stdio.h>

char *my_strcpy (char *dest, char const *src)
{
    int i = 0;
    if (src == NULL)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

char *my_strncpy (char *dest, char const *src, unsigned int n)
{
    unsigned int i = 0;
    if (src == NULL)
        return NULL;
    while (src[i] != '\0' && i != n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
