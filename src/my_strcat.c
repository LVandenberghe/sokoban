/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-ludwig.vandenberghe
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *str)
{
    int taille = my_strlen(str);
    int destination = my_strlen(dest);
    char *res = malloc(sizeof(char) * (taille + destination + 1));
    int i = 0;

    if (taille == 0 || destination == 0)
        return NULL;
    for (; i != destination; i++) {
        res[i] = dest[i];
    }
    for (int c = 0; i != (destination + taille); i++, c++)
        res[i] = str[c];
    res[i] = '\0';
    return (res);
}
