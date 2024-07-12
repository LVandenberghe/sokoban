/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** my_popup
*/

#include "my.h"

void check_getch(int key, position_t *coordp, char **map, char **map_dup)
{
    if (key == 27) {
        endwin();
        exit (0);
    }
    if(key == KEY_DOWN || key == KEY_LEFT || key == KEY_UP || key == KEY_RIGHT)
        moveP(key, coordp, map, map_dup);
}

int sokoban(char **av)
{
    int key = 0;
    int rows, cols;
    int size = 0;
    char **map = NULL;
    position_t coord_P;
    char **map_dup = NULL;

    if ((map = read_file(av[1])) == NULL)
        return (-1);
    if ((map_dup = read_file(av[1])) == NULL)
        return (-1);
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    for (int i = 0; map[i] != NULL; i++)
    for (; map[size] != NULL; size++);
    for (int espace = 0; map[espace] != NULL; espace++) {
        mvprintw(LINES / 2 - 8 / 2 + espace, COLS / 2 - my_strlen(map[espace]) / 2, map[espace]);
    }
    while ((key = getch())) {
        clear();
        if (key == ' ')
            map = read_file(av[1]);
        coord_P = where_P(map);
        check_getch(key, &coord_P, map, map_dup);
        getmaxyx(stdscr, rows, cols);
        if (rows <= 5 || cols <= 35)
            printw("TTY too small");
        else {
            for (int espace = 0; map[espace] != NULL; espace++) {
                mvprintw((rows - size) / 2 + espace, (cols - my_strlen(map[espace])) / 2, map[espace]);
            }
        }
        refresh();
    }
    endwin();
    return (0);
}

int main(int ac, char **av)
{
    if (ac <= 1)
        return (84);
    sokoban(av);
    return (0);
}
