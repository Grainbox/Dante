/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** displays
*/

#include "solver.h"

int display_help(char *arg)
{
    if (my_strcmp("-h", arg) == false)
        return false;
    my_putstr("USAGE\n \t./solver map.txt\n");
    return true;
}

void display_map(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        my_printf("%s\n", maze[i]);
}
