/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** solver
*/

#ifndef SOLVER_H_
    #define SOLVER_H_

    #include "my.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <time.h>

    #define GET_INTER_ARG content->maze, pos.y, pos.x, content->size

    struct vector2i {
        int x;
        int y;
    };
    typedef struct vector2i vector2i;

    struct intersection {
        vector2i pos;
        int top;
        int bot;
        int right;
        int left;
        int waze;
    };
    typedef struct intersection inter;

    struct maze_size {
        int width;
        int height;
    };
    typedef struct maze_size maze_size;

    struct solver {
        inter *inters;
        char *path;
        int i_inters;
        int i_path;
        inter point;
        char **maze;
        maze_size size;
    };
    typedef struct solver solver;

    char *read_map(char *path);

    char **parse_buffer(char *buffer, char parse);

    int display_help(char *arg);

    void display_map(char **maze);

    int solve(solver *content);

    inter get_inter(char **map, int y, int x, maze_size size);

    maze_size get_maze_size(char **maze);

    vector2i get_first_pos(void);

    void write_solved(char **maze, char *way, maze_size size, solver *content);

    void go_to(int *x, int *y, int direction);

    int get_one_direction(inter point);

    int choose_direction(solver *content, int *to_write);

    void add_inter(solver *content, char c);

    void back_last_inter(solver *content, int *x, int *y, int *end);

#endif
