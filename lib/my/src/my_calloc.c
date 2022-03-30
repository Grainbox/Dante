/*
** EPITECH PROJECT, 2022
** my_calloc.c
** File description:
** calloc function
*/

#include <stdlib.h>

void *my_calloc(size_t size)
{
    unsigned char *alloc = malloc(size);

    for (size_t i = 0; i < size; i++)
        alloc[i] = 0;
    return (void *) alloc;
}
