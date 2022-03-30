/*
** EPITECH PROJECT, 2022
** read_way.c
** File description:
** Dante project: interpret way char* and change map.
*/

#include "solver.h"

vector2i get_first_pos(void)
{
    vector2i pos;

    pos.x = 0;
    pos.y = 0;
    return pos;
}

static int read_str_way(char direction)
{
    if (direction == 't')
        return 1;
    if (direction == 'b')
        return 2;
    if (direction == 'r')
        return 3;
    if (direction == 'l')
        return 4;
    return 0;
}

static void end_process(char **maze, solver *content, vector2i pos)
{
    maze[pos.y][pos.x] = 'o';
    maze[content->size.height - 1][content->size.width - 1] = 'o';
}

void write_solved(char **maze, char *way, maze_size size, solver *c)
{
    vector2i pos = get_first_pos();
    inter point = get_inter(maze, pos.y, pos.x, size);
    int direction = 0;
    int i = 0;

    while (pos.x != (c->size.width - 1) || pos.y != (c->size.height - 1)) {
        maze[pos.y][pos.x] = 'o';
        if (get_one_direction(point) == 0 && i != my_strlen(way)) {
            direction = read_str_way(way[i]);
            i++;
        } else
            direction = get_one_direction(point);
        go_to(&pos.x, &pos.y, direction);
        if ((pos.x == (c->size.width - 2) && pos.y == (c->size.height - 1)) ||
            (pos.x == (c->size.width - 1) && pos.y == (c->size.height - 2))) {
            end_process(maze, c, pos);
            break;
        }
        point = get_inter(maze, pos.y, pos.x, size);
    }
}
