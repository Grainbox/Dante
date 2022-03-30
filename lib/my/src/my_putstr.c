/*
** EPITECH PROJECT, 2021
** My_PutSTR
** File description:
** |
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = my_strlen(str);

    write(1, str, i);
    return 0;
}
