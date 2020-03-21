/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Task02
*/

#include "my.h"

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return 0;
}
