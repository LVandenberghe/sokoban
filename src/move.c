/*
** EPITECH PROJECT, 2022
** B-PSU-200-REN-2-1-mysokoban-ludwig.vandenberghe
** File description:
** move
*/

#include "my.h"

void move_up(char **map, position_t *position, char **map_dup)
{
    if (map[position->y - 1][position->x] == '#')
        return;
    if (map[position->y - 1][position->x] == 'X') {
        if (map[position->y - 2][position->x] == '#')
            return;
        if (map[position->y - 2][position->x] == 'X')
            return;
        map[position->y][position->x] = ' ';
        map[position->y - 1][position->x] = 'P';
        map[position->y - 2][position->x] = 'X';
        return;
    }
    if (map_dup[position->y][position->x] == 'O') {
        map[position->y][position->x] = 'O';
        map[position->y - 1][position->x] = 'P';
        return;
    }
    map[position->y][position->x] = ' ';
    map[position->y - 1][position->x] = 'P';
}

void move_down(char **map, position_t *position, char **map_dup)
{
    if (map[position->y + 1][position->x] == '#')
        return;
    if (map[position->y + 1][position->x] == 'X') {
        if (map[position->y + 2][position->x] == '#')
            return;
        if (map[position->y + 2][position->x] == 'X')
            return;
        map[position->y][position->x] = ' ';
        map[position->y + 1][position->x] = 'P';
        map[position->y + 2][position->x] = 'X';
        return;
    }
    if (map_dup[position->y][position->x] == 'O') {
        map[position->y][position->x] = 'O';
        map[position->y + 1][position->x] = 'P';
        return;
    }
    map[position->y][position->x] = ' ';
    map[position->y + 1][position->x] = 'P';
}

void move_right(char **map, position_t *position, char **map_dup)
{
    if (map[position->y][position->x + 1] == '#')
        return;
    if (map[position->y][position->x + 1] == 'X') {
        if (map[position->y][position->x + 2] == '#')
            return;
        if (map[position->y][position->x + 2] == 'X')
            return;
        map[position->y][position->x] = ' ';
        map[position->y][position->x + 1] = 'P';
        map[position->y][position->x + 2] = 'X';
        return;
    }
    if (map_dup[position->y][position->x] == 'O') {
        map[position->y][position->x] = 'O';
        map[position->y][position->x + 1] = 'P';
        return;
    }
    map[position->y][position->x] = ' ';
    map[position->y][position->x + 1] = 'P';
}

void move_left(char **map, position_t *position, char **map_dup)
{
    if (map[position->y][position->x - 1] == '#')
        return;
    if (map[position->y][position->x - 1] == 'X') {
        if (map[position->y][position->x - 2] == '#')
            return;
        if (map[position->y][position->x - 2] == 'X')
            return;
        map[position->y][position->x] = ' ';
        map[position->y][position->x - 1] = 'P';
        map[position->y][position->x - 2] = 'X';
        return;
    }
    if (map_dup[position->y][position->x] == 'O') {
        map[position->y][position->x] = 'O';
        map[position->y][position->x - 1] = 'P';
        return;
    }
    map[position->y][position->x] = ' ';
    map[position->y][position->x - 1] = 'P';
}

void moveP(int key, position_t *coordp, char **map, char **map_dup)
{
    switch (key) {
    case KEY_UP:
        move_up(map, coordp, map_dup);
        break;
    case KEY_DOWN:
        move_down(map, coordp, map_dup);
        break;
    case KEY_LEFT:
        move_left(map, coordp, map_dup);
        break;
    case KEY_RIGHT:
        move_right(map, coordp, map_dup);
        break;
    default:
        break;
    }
}
