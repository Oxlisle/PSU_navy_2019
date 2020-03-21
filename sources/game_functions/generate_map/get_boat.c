/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** get_boat.c
*/

#include <stdlib.h>
#include "functions.h"

char **vertical_boat(char **map, char *boat)
{
    int nb = 0;

    for (int i = 0; i < my_getnbr(boat); i++) {
        map[boat[3] - '1' + nb][(boat[2] - 'A') * 2] = boat[0];
        nb++;
    }
    return map;
}

char **horizontal_boat(char **map, char *boat)
{
    int nb = 0;

    for (int i = 0; i < my_getnbr(boat); i++) {
        map[boat[3] - '1'][(boat[2] - 'A' + nb) * 2] = boat[0];
        nb++;
    }
    return map;
}

char **draw_boat(char **map, char **boat)
{
    for (int i = 0; boat[i] != NULL; i++) {
        if (boat[i][2] == boat[i][5])
            map = vertical_boat(map, boat[i]);
        if (boat[i][3] == boat[i][6])
            map = horizontal_boat(map, boat[i]);
    }
    return map;
}