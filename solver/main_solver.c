/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** solver
*/

#include "solver.h"

int error_handling(int argc)
{
    if (argc != 2) {
        my_printf("Wrong argument\n");
        return 84;
    }
    return 0;
}

maze_size get_maze_size(char **maze)
{
    int y = 0;
    int x = 0;
    maze_size size = { 0, 0 };

    for (; maze[y] != NULL; y++)
        for (; maze[y][x] != '\0'; x++);
    size.width = x;
    size.height = y;
    return size;
}

solver init_solver(char **maze)
{
    maze_size size = get_maze_size(maze);
    inter *inters = malloc(sizeof(inter) * (size.width * size.height));
    vector2i pos = { 0, 0 };
    inter point = { pos, 0, 0, 0, 0, 0 };
    char *path = malloc(sizeof(char) * (size.width * size.height));
    solver content = { inters, path, 0, 0, point, maze, size };

    return content;
}

void clear_map(solver *content)
{
    int y = 0;
    int x = 0;

    for (; content->maze[y][x] != '\0' && content->maze[y] != NULL;) {
        if (content->maze[y][x] == 'o')
            content->maze[y][x] = '*';
        if (x == content->size.width - 1 && y != content->size.height - 1) {
            x = 0;
            y++;
        } else
            x++;
    }
}

int main(int argc, char **argv)
{
    char *buffer = NULL;
    char **maze = NULL;
    solver content;

    if (error_handling(argc) == 84)
        return 84;
    if ((buffer = read_map(argv[1])) == NULL)
        return 84;
    if (display_help(argv[1]) == true)
        return 0;
    maze = parse_buffer(buffer, '\n');
    free(buffer);
    content = init_solver(maze);
    if (solve(&content) == 84) {
        my_printf("no solution found\n");
        return 0;
    }
    write_solved(maze, content.path, content.size, &content);
    return 0;
}
