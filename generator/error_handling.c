/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** error_handling
*/

#include "generator.h"

int error_handling(int argc, char **argv)
{
    if (argc < 3) {
        my_printf("Wrong argument\n");
        return ERROR;
    }
    if (argc == 4)
        if (my_strcmp(argv[3], "perfect") == false &&
            my_strcmp(argv[3], "imperfect") == false) {
            my_printf("Wrong maze format\n");
            return ERROR;
        }
    return OK;
}
