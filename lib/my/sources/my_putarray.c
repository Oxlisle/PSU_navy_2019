/*
** EPITECH PROJECT, 2020
** my_putarray.c
** File description:
** my_putarray
*/

#include <stddef.h>

void my_putstr(char *str);

void my_putarray(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        my_putstr(array[i]);
}