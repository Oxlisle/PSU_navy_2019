/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** error_boat.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "functions.h"

int vertical_check(char *boat)
{
    if (((boat[6]-'0') - (boat[3]-'0') + 1) != my_getnbr(boat))
        return 84;
    return 0;
}

int horizontal_check(char *boat)
{
    if (((boat[5]-'A') - (boat[2]-'A') + 1) != my_getnbr(boat))
        return 84;
    return 0;
}

int error_boat_location(char **boats)
{
    for (int i = 0; boats[i] != NULL; i++) {
        if (boats[i][3] - '0' < 1 || boats[i][3] - '0' > 8 \
|| boats[i][6] - '0' < 1 || boats[i][6] - '0' > 8) {
            return 84;
        }
        if (boats[i][2] < 'A' || boats[i][2] > 'H' \
|| boats[i][5] < 'A' || boats[i][5] > 'H') {
            return 84;
        }
        if (boats[i][3] > boats[i][6] || boats[i][2] > boats[i][5]) {
            return 84;
        }
        if (boats[i][2] == boats[i][5] && vertical_check(boats[i]) == 84) {
            return 84;
        }
        if (boats[i][3] == boats[i][6] && horizontal_check(boats[i]) == 84) {
            return 84;
        }
    }
    return 0;
}