/*
** EPITECH PROJECT, 2022
** generate_perfect.c
** File description:
** Dante project : Perfect maze generation
*/

#include "generator.h"

int get_nb_spaces(vector_t dims)
{
    int nb = 0;
    int lines_w_spaces = dims.x / 2;
    int cols_w_spaces = dims.y / 2;

    if (dims.x % 2 != 0)
        lines_w_spaces++;
    if (dims.y % 2 != 0)
        cols_w_spaces++;
    nb = lines_w_spaces * cols_w_spaces;
    return nb;
}

void remove_lil_ints(int **map, int lil_int, int biggest_int, vector_t dims)
{
    int x = 0;
    int y = 0;

    for (; y != dims.y && x != dims.x;) {
        if (map[y][x] == lil_int)
            map[y][x] = biggest_int;
        x++;
        if (x == dims.x && y != dims.y) {
            x = 0;
            y++;
        }
    }
}

void write_map(char **map, int **map_ints, vector_t dims)
{
    int x = 0;
    int y = 0;

    for (; y != dims.y && x != dims.x;) {
        if (map_ints[y][x] == -1)
            map[y][x] = 'X';
        else
            map[y][x] = '*';
        x++;
        if (x == dims.x && y != dims.y) {
            x = 0;
            y++;
        }
    }
    map[dims.y - 1][dims.x - 1] = '*';
    if (dims.x % 2 == 0 && dims.y % 2 == 0)
        map[dims.y - 2][dims.x - 1] = '*';
}

void fill_perfect_map(char **map, vector_t dims)
{
    int **map_ints;

    map_ints = malloc(sizeof(int *) * dims.y + 1);
    for (int y = 0; y != dims.y; y++)
        map_ints[y] = malloc(sizeof(int) * dims.x + 1);
    get_framing_map(map, dims);
    get_map_ints(map_ints, dims);
    open_walls(map_ints, dims);
    write_map(map, map_ints, dims);
}
