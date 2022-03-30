/*
** EPITECH PROJECT, 2022
** intersection.c
** File description:
** Dante project: functions relative to intersections
*/

#include "solver.h"

static void get_inter_ways(char **map, inter *point, maze_size size)
{
    if (point->pos.x != 0 && map[point->pos.y][point->pos.x - 1] == '*')
        point->left = 1;
    else
        point->left = 0;
    if (point->pos.x != size.width - 1 &&
        map[point->pos.y][point->pos.x + 1] == '*')
        point->right = 1;
    else
        point->right = 0;
    if (point->pos.y != 0 && map[point->pos.y - 1][point->pos.x] == '*')
        point->top = 1;
    else
        point->top = 0;
    if (point->pos.y != (size.height - 1) &&
        map[point->pos.y + 1][point->pos.x] == '*')
        point->bot = 1;
    else
        point->bot = 0;
}

inter init_point(int x, int y)
{
    vector2i pos = { x, y };
    inter point = { pos, 0, 0, 0, 0, 0 };

    return point;
}

inter get_inter(char **map, int y, int x, maze_size size)
{
    inter point = init_point(x, y);

    get_inter_ways(map, &point, size);
    point.waze = point.left + point.right + point.top + point.bot;
    return point;
}
