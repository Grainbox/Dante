/*
** EPITECH PROJECT, 2022
** open_walls.c
** File description:
** Dante project : functions to create perfect maze
*/

#include "generator.h"

static void vertical_open(int **map, vector_t pt, vector_t dims)
{
    int biggest_int = 0;
    int lil_int = 0;

    if (map[pt.y - 1][pt.x] > map[pt.y + 1][pt.x]) {
        biggest_int = map[pt.y - 1][pt.x];
        lil_int = map[pt.y + 1][pt.x];
    } else {
        biggest_int = map[pt.y + 1][pt.x];
        lil_int = map[pt.y - 1][pt.x];
    }
    map[pt.y][pt.x] = biggest_int;
    map[pt.y - 1][pt.x] = biggest_int;
    map[pt.y + 1][pt.x] = biggest_int;
    remove_lil_ints(map, lil_int, biggest_int, dims);
}

static void horizontal_open(int **map, vector_t pt, vector_t dims)
{
    int biggest_int = 0;
    int lil_int = 0;

    if (map[pt.y][pt.x - 1] > map[pt.y][pt.x + 1]) {
        biggest_int = map[pt.y][pt.x - 1];
        lil_int = map[pt.y][pt.x + 1];
    } else {
        biggest_int = map[pt.y][pt.x + 1];
        lil_int = map[pt.y][pt.x - 1];
    }
    map[pt.y][pt.x] = biggest_int;
    map[pt.y][pt.x - 1] = biggest_int;
    map[pt.y][pt.x + 1] = biggest_int;
    remove_lil_ints(map, lil_int, biggest_int, dims);
}

static void open_process(int **map, vector_t pt, int dir, vector_t dims)
{
    if (dir < 50 && pt.y != 0 && pt.y != dims.y - 1)
        vertical_open(map, pt, dims);
    if (dir >= 50 && pt.x != 0 && pt.x != dims.x - 1)
        horizontal_open(map, pt, dims);
}

static int check_opening(int **map, vector_t pt, int dir, vector_t dims)
{
    if (map[pt.y][pt.x] == -1 &&
    ((dir < 50 && pt.y != 0 && pt.y != dims.y - 1 &&
    map[pt.y - 1][pt.x] != -1 && map[pt.y + 1][pt.x] != -1 &&
    map[pt.y - 1][pt.x] != map[pt.y + 1][pt.x]) ||
    (dir >= 50 && pt.x != 0 && pt.x != dims.x - 1 &&
    map[pt.y][pt.x - 1] != -1 && map[pt.y][pt.x + 1] != -1 &&
    map[pt.y][pt.x - 1] != map[pt.y][pt.x + 1])))
        return 1;
    else
        return 0;
}

void open_walls(int **map_ints, vector_t dims)
{
    int nb_spaces = get_nb_spaces(dims);
    vector_t pt;
    int dir = 0;
    srand(time(NULL));

    for (; nb_spaces > 1;) {
        dir = rand() % 100;
        pt.x = rand() % dims.x;
        pt.y = rand() % dims.y;
        if (check_opening(map_ints, pt, dir, dims) == 1) {
            open_process(map_ints, pt, dir, dims);
            nb_spaces--;
        }
    }
}
