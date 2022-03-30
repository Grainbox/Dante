/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** generator
*/

#include "generator.h"

char **malloc_map(vector_t dims)
{
    char **map;

    map = malloc(sizeof(char *) * (dims.y + 1));
    for (int i = 0; i < dims.y; i++)
        map[i] = malloc(sizeof(char) * (dims.x + 1));
    return map;
}

vector_t get_maze_dims(char **av)
{
    vector_t vector;

    vector.x = my_getnbr(av[1]);
    vector.y = my_getnbr(av[2]);
    return vector;
}

void display_maze(char **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        my_printf("%s", map[y]);
        if (map[y + 1] != NULL)
            my_printf("\n");
    }
}

int main(int argc, char **argv)
{
    char **map = NULL;
    vector_t dims = { 0, 0 };

    if (error_handling(argc, argv) == ERROR)
        return ERROR;
    dims = get_maze_dims(argv);
    map = malloc_map(dims);
    if (argc == 3) {
        fill_perfect_map(map, dims);
        fill_imperfect_map(map, dims);
    } else if (my_strcmp(argv[3], "imperfect") == true) {
        fill_perfect_map(map, dims);
        fill_imperfect_map(map, dims);
    }
    if (argc == 4)
        if (my_strcmp(argv[3], "perfect") == true)
            fill_perfect_map(map, dims);
    display_maze(map);
    return 0;
}
