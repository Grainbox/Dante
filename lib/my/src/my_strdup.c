/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** duplicate an str into another
*/

#include "my.h"

char *my_strdup(char *str)
{
    char *str2 = malloc(sizeof(char) * my_strlen(str));

    str2 = my_strcpy(str2, str);
    return str2;
}
