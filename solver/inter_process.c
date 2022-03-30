/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** inter_process
*/

#include "solver.h"

void check_end(solver *content, int *end)
{
    int no_end = 0;

    for (int i = content->i_inters; i >= 0; i--) {
        if (content->inters[i].waze >= 1) {
            no_end++;
            break;
        }
    }
    if (no_end == 0)
        *end = 1;
}

void back_last_inter(solver *content, int *x, int *y, int *end)
{
    vector2i pos;

    if (content->i_inters > 0) {
        pos.x = content->inters[content->i_inters - 1].pos.x;
        pos.y = content->inters[content->i_inters - 1].pos.y;
    } else {
        pos.x = content->inters[content->i_inters].pos.x;
        pos.y = content->inters[content->i_inters].pos.y;
    }
    content->inters[content->i_inters] = get_inter(GET_INTER_ARG);
    *x = content->inters[content->i_inters].pos.x;
    *y = content->inters[content->i_inters].pos.y;
    if (content->i_path > 0)
        content->i_path--;
    if (content->inters[content->i_inters].waze < 1) {
        content->path[content->i_path] = '\0';
        content->i_inters--;
    }
    check_end(content, end);
}

void add_inter(solver *content, char c)
{
    vector2i pos = { 0, 0 };

    pos.x = content->inters[content->i_inters - 1].pos.x;
    pos.y = content->inters[content->i_inters - 1].pos.y;
    if (content->i_inters != 0) {
        if (pos.x != content->point.pos.x || pos.y != content->point.pos.y) {
            content->inters[content->i_inters] = content->point;
            content->i_inters++;
        }
    } else {
        content->inters[content->i_inters] = content->point;
        content->i_inters++;
    }
    content->path[content->i_path] = c;
    content->path[content->i_path + 1] = '\0';
    content->i_path++;
}
