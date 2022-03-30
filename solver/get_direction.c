/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** get_direction
*/

#include "solver.h"

int check_direction_x(solver *content, int direction)
{
    if (direction == 3 && content->point.right == 1) {
        add_inter(content, 'r');
        return 3;
    }
    if (direction == 4 && content->point.left == 1) {
        add_inter(content, 'l');
        return 4;
    }
    return 0;
}

int get_direction(solver *content)
{
    int direction = 0;

    if (content->point.waze == 0)
        return 0;
    while (1) {
        direction = rand() % 5;
        if ((direction == 1 || direction == 0) && content->point.top == 1) {
            add_inter(content, 't');
            return 1;
        }
        if (direction == 2 && content->point.bot == 1) {
            add_inter(content, 'b');
            return 2;
        }
        direction = check_direction_x(content, direction);
        if (direction != 0)
            return direction;
    }
    return 0;
}

int get_one_direction(inter point)
{
    if (point.waze == 1 && point.top == 1)
        return 1;
    if (point.waze == 1 && point.bot == 1)
        return 2;
    if (point.waze == 1 && point.right == 1)
        return 3;
    if (point.waze == 1 && point.left == 1)
        return 4;
    return 0;
}

int choose_direction(solver *content, int *to_write)
{
    int direction = 0;

    if (get_one_direction(content->point) == 0 || *to_write == 1) {
        direction = get_direction(content);
        *to_write = 0;
    } else
        direction = get_one_direction(content->point);
    return direction;
}
