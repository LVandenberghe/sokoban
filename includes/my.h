/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** game
*/


#ifndef GAME_H_
    #define GAME_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <ncurses.h>

typedef struct position_s {
    int x;
    int y;
} position_t;

int my_strlen(char const *str);
char *my_strncpy (char *dest, char const *src, unsigned int n);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *str);
char *my_strcpy_m(char const *str, unsigned int n);
char *my_strdup(char const *str);
char **str_to_word_array(char *str, char delim);
char **read_file(char *filepath);
position_t check_P(position_t *coord, char **map);
position_t *fill_value(position_t *pos);
position_t where_P(char **map);
void move_up(char **map, position_t *position, char **map_dup);
void move_down(char **map, position_t *position, char **map_dup);
void move_left(char **map, position_t *position, char **map_dup);
void move_right(char **map, position_t *position, char **map_dup);
void moveP(int key, position_t *coordp, char **map, char **map_dup);
void check_getch(int key, position_t *coordp, char **map, char **map_dup);
int count_X(char **map, int i);
int nb_of_x(char **map);
void check_x(char **map, int *index, position_t *co, position_t *all_x);
void p_map(char **map, int *index, position_t *co, position_t *all_x);
position_t *where_X(char **map);
int count_O(char **map, int i);
int nb_of_O(char **map);
position_t *where_O(char **map);

#endif
