/*
** EPITECH PROJECT, 2022
** B-PSU-200-REN-2-1-mysokoban-ludwig.vandenberghe
** File description:
** conditions
*/

#include "my.h"

int count_X(char **map, int i)
{
    int count = 0;

    for(int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] != 'X')
            count++;
    }
    return (count);
}

int nb_of_x(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i++) {
        count = count + count_X(map, i);
    }
    return (count);
}

void check_x(char **map, int *index, position_t *co, position_t *all_x)
{
    if (map[co->y][co->x] == 'X') {
        all_x[*index].x = co->x;
        all_x[*index].y = co->y;
        *index = *index + 1;
    }
}

static void p_map_X(char **map, int *index, position_t *co, position_t *all_x)
{
    for (; map[co->y] != NULL; co->y++) {
        for (; map[co->y][co->x] != '\0'; co->x++) {
            check_x(map, index, co, all_x);
        }
    }
}

position_t *where_X(char **map)
{
    int nbx = nb_of_x(map);
    position_t *all_x;
    position_t co;
    co.x = 0;
    co.y = 0;
    int index = 0;

    for (index = 0; index != nbx;) {
        p_map_X(map, &index, &co, all_x);
    }
    return all_x;
}
