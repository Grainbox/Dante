/*
** EPITECH PROJECT, 2022
** create_tabs.c
** File description:
** Dante project : perfect gen : function to create char and int tabs.
*/

#include "generator.h"

void frame_line(char **map, int x, int y)
{
    if (x % 2 != 0)
        map[y][x] = 'X';
    else
        map[y][x] = '*';
}

void get_framing_map(char **map, vector_t dims)
{
    int x = 0;

    for (int y = 0; x != dims.x && y != dims.y;) {
        if (y % 2 != 0) {
            map[y][x] = 'X';
            x++;
        } else {
            frame_line(map, x, y);
            x++;
        }
        if (x == dims.x && y != dims.y) {
            y++;
            x = 0;
        }
    }
}

int frame_line_int(int **map_ints, int x, int y, int nb)
{
    if (x % 2 != 0) {
        map_ints[y][x] = -1;
        return 0;
    } else {
        map_ints[y][x] = nb;
        return 1;
    }
}

void get_map_ints(int **map_ints, vector_t dims)
{
    int nb = 0;
    int x = 0;

    for (int y = 0; x != dims.x && y != dims.y;) {
        if (y % 2 != 0) {
            map_ints[y][x] = -1;
            x++;
        } else {
            nb += frame_line_int(map_ints, x, y, nb);
            x++;
        }
        if (x == dims.x && y != dims.y) {
            y++;
            x = 0;
        }
    }
}
