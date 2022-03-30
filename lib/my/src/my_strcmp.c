/*
** EPITECH PROJECT, 2021
** my_str_cmp
** File description:
** |
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int length = my_strlen(s1);
    int length2 = my_strlen(s2);
    int i = 0;

    if (length != length2)
        return 0;
    while (i != length) {
        if (s1[i] != s2[i])
            break;
        i++;
    }
    if (i == length)
        return 1;
    else
        return 0;
}
