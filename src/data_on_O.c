/*
** EPITECH PROJECT, 2022
** B-PSU-200-REN-2-1-mysokoban-ludwig.vandenberghe
** File description:
** conditions
*/

#include "my.h"

int count_O(char **map, int i)
{
    int count = 0;

    for(int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] != 'O')
            count++;
    }
    return (count);
}

int nb_of_O(char **map)
{
    int count = 0;

    for (int i = 0; map[i] !=  NULL; i++) {
        count = count + count_O(map, i);
    }
    return (count);
}

void check_O(char **map, int *index, position_t *co, position_t *all_O)
{
    if (map[co->y][co->x] == 'O') {
        all_O[*index].x = co->x;
        all_O[*index].y = co->y;
        *index = *index + 1;
    }
}

static void p_map_O(char **map, int *index, position_t *co, position_t *all_O)
{
    for (; map[co->y] != NULL; co->y++) {
        for (; map[co->y][co->x] != '\0'; co->x++) {
            check_x(map, index, co, all_O);
        }
    }
}

position_t *where_O(char **map)
{
    int nbx = nb_of_O(map);
    position_t *all_O = fill_value(all_O);
    position_t co;
    co.x = 0;
    co.y = 0;
    int index = 0;

    for (index = 0; index != nbx;) {
        printf("%i %i", all_O->x, all_O->y);
        p_map_O(map, &index, &co, all_O);
    }
    return all_O;
}
