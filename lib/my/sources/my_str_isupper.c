/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** task15
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 65 || str[i] > 90)
            return (0);
    }
    return (1);
}
