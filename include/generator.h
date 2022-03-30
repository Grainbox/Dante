/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** generator
*/

#ifndef GENERATOR_H_
    #define GENERATOR_H_

    #include "my.h"
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>

    #define ERROR 84
    #define OK 0

    struct vector {
        int x;
        int y;
    };

    typedef struct vector vector_t;

    int error_handling(int argc, char **argv);

    void fill_perfect_map(char **map, vector_t dims);

    void frame_line(char **map, int x, int y);

    int frame_line_int(int **map_ints, int x, int y, int nb);

    void get_framing_map(char **map, vector_t dims);

    void get_map_ints(int **map_ints, vector_t dims);

    void open_walls(int **map_ints, vector_t dims);

    void remove_lil_ints(int **map, int lil_int,
                        int biggest_int, vector_t dims);

    int get_nb_spaces(vector_t dims);

    void fill_imperfect_map(char **map, vector_t dims);

#endif
