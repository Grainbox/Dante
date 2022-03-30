/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** solver
*/

#include "solver.h"

void go_to(int *x, int *y, int direction)
{
    if (direction == 1)
        (*y)--;
    if (direction == 2)
        (*y)++;
    if (direction == 3)
        (*x)++;
    if (direction == 4)
        (*x)--;
}

int check_return(int end)
{
    if (end == 1)
        return 84;
    return 0;
}

int solve(solver *content)
{
    int y = 0;
    int x = 0;
    int to_write = 0;
    int direction = 0;
    int end = 0;

    srand(time(NULL));
    while ((x != (content->size.width - 1) ||
            y != (content->size.height - 1)) && end == 0) {
        content->maze[y][x] = 'o';
        content->point = get_inter(content->maze, y, x, content->size);
        direction = choose_direction(content, &to_write);
        if (direction == 0) {
            back_last_inter(content, &x, &y, &end);
            to_write = 1;
        } else
            go_to(&x, &y, direction);
    }
    return check_return(end);
}
