/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** ecrire une string avec comme espace des caractere non-alphanumeric
*/

#include "my.h"

int size_array(char const *str)
{
    int counter = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            counter++;
    }
    return (counter);
}

int index_of(char *str, char i)
{
    (void) i;
    int a = 0;

    for (;str[a] != '\0'; a++) {
        if (str[a] == '\n')
            return (a);
    }
    return (-1);
}

char **str_to_word_array(char *str, char delim)
{
    char **word_array = malloc(sizeof(char *) * (size_array(str) + 1));
    int i = 0;
    int index = 0;

    if (str == NULL || word_array == NULL)
        return NULL;
    while (*str != '\0') {
        index = index_of(str, delim);
        if (index == -1 || index == 0) {
            word_array[i++] = my_strdup(str);
            break;
        }
        word_array[i] = my_strcpy_m(str, index);
        i++;
        str += index + 1;
    }
    word_array[i] = NULL;
    return (word_array);
}
