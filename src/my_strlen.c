/*
** EPITECH PROJECT, 2022
** strlen.c
** File description:
** count the number o character in the string
*/


#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    for(i = 0; str[i] != '\0'; i++);

    return i;
}
