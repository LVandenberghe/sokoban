/*
** EPITECH PROJECT, 2022
** B-PSU-200-REN-2-1-mysokoban-ludwig.vandenberghe
** File description:
** player
*/

#include "my.h"

position_t check_P(position_t *coord, char **map)
{
    int y = coord->y;

    for (int i = 0; map[y][i] != '\0'; i++) {
        coord->x = -1;
        if (map[y][i] == 'P') {
            coord->x = i;
            return *coord;
        }
    }
    return *coord;
}

position_t where_P(char **map)
{
    position_t coord_P;

    for (int i = 0; map[i] !=  NULL; i++) {
        coord_P.y = i;
        coord_P = check_P(&coord_P, map);
        if (coord_P.x != -1)
            return coord_P;
    }
    return (coord_P);
}
