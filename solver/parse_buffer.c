/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.daniel
** File description:
** parse_buffer
*/

#include "solver.h"

char **parse_buffer(char *buffer, char parse)
{
    char **buffer2d = malloc(sizeof(char *) * (my_strlen(buffer) + 1));
    char *word = malloc(sizeof(char) * my_strlen(buffer) + 1);
    int l = 0;
    int j = 0;

    for (int i = 0; i < my_strlen(buffer) + 1; i++) {
        if (buffer[i] == parse || buffer[i] == '\0') {
            buffer2d[j] = malloc(sizeof(char) * my_strlen(buffer));
            my_strcpy(buffer2d[j], word);
            j++;
            l = 0;
            i++;
        }
        word[l] = buffer[i];
        l++;
        word[l] = '\0';
    }
    buffer2d[j] = NULL;
    free(word);
    return buffer2d;
}

char *read_map(char *path)
{
    struct stat *buf = malloc(sizeof(struct stat));
    char *buffer = NULL;
    int fd = 0;
    int fc = 0;

    stat(path, buf);
    if ((fd = open(path, O_RDONLY)) != 3) {
        my_printf("Cannot open map file\n");
        return NULL;
    }
    buffer = malloc(sizeof(char) * (buf->st_size + 1));
    fc = read(fd, buffer, buf->st_size);
    buffer[fc] = '\0';
    free(buf);
    close(fd);
    if (buffer[0] != '*')
        return NULL;
    return buffer;
}
