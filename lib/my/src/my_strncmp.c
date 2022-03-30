/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** |
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int sig = 0;
    int i = 0;

    while (i != n) {
        if (s1[i] != s2[i])
            sig++;
        i++;
    }
    if (sig == 0)
        return 1;
    else
        return 0;
}
