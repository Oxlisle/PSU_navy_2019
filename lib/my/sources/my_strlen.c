/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Task03
*/

#include "my.h"

int my_strlen(char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return (a);
}
