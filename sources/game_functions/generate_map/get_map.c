/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** get_map.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "functions.h"

void print_map(char **map)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0, nb = 1; map[i] != NULL; nb++, i++) {
        my_put_nbr(nb);
        my_putchar('|');
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

char *fill_line(char *map, char *line)
{
    int i = 0;
    for (; line[i] != '\0'; i++) {
        map[i] = line[i];
    }
    map[i] = '\0';
    return (map);
}

char **init_empty_map(void)
{
    char **empty_map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        empty_map[i] = malloc(sizeof(char) * 16);
        empty_map[i] = fill_line(empty_map[i], ". . . . . . . .");
    }
    empty_map[8] = NULL;
    return (empty_map);
}

char **get_map(void)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 16);
        map[i] = fill_line(map[i], ". . . . . . . .");
    }
    map[8] = NULL;
    return (map);
}

char **draw_map(char *pos)
{
    int fd = 0;
    char *buffer = malloc(sizeof(char) * 32);
    char **boats;
    char **map = get_map();

    fd = open(pos, O_RDONLY);
    if (buffer == NULL || fd == -1)
        return NULL;
    if (read(fd, buffer, 32) == -1)
        return NULL;
    boats = my_str_to_word_array(buffer);
    if (error_boat_location(boats) == 84) {
        return NULL;
    }
    map = draw_boat(map, boats);
    for (int i = 0; boats[i] != NULL; i++)
        free(boats[i]);
    free(boats);
    free(buffer);
    close(fd);
    return map;
}