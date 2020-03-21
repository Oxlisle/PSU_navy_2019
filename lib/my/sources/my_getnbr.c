/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Task05
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int neg = 1;
    int i = 0;
    int nb = 0;

    for (; str[i] == '-' || str[i] == '+'; i++){
        if (str[i] == '-')
            neg = neg * (-1);
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb = nb * 10;
        nb = nb + (str[i] - '0');
    }
    return (nb * neg);
}
