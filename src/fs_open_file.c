/*
** EPITECH PROJECT, 2022
** open_file.c
** File description:
** open the file
*/

#include "my.h"

static int fs_open_file(char const *filepath)
{
    int i = open(filepath, O_RDONLY);

    if (i == -1)
        return (84);
    return i;
}

char **read_file(char *filepath)
{
    int file = fs_open_file(filepath);
    struct stat buf;
    stat(filepath, &buf);
    int size = buf.st_size;
    char *str = malloc(sizeof(char) * (size + 1));
    char **buffer = NULL;

    read(file, str, size);
    str[size] = '\0';
    buffer = str_to_word_array(str, '\n');
    if (str == NULL || buffer == NULL)
        return NULL;
    close(file);
    return (buffer);
}
