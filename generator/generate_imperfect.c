/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** generate_imperfect
*/

#include "generator.h"

void fill_imperfect_map(char **map, vector_t dims)
{
    int todo = 0;
    int x = 0;
    int y = 0;

    if (dims.x < dims.y)
        todo = dims.x;
    else
        todo = dims.y;
    srand(time(NULL));
    for (int i = 0; i < todo; i++) {
        x = rand() % dims.x;
        y = rand() % dims.y;
        if (map[y][x] == 'X')
            map[y][x] = '*';
        else
            i--;
    }
}
