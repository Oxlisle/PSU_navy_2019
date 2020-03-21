/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Task06
*/

#include "my.h"

int my_is_prime(int nb)
{
    int n = 1;

    if (nb == 2)
        return 1;
    while (n < nb/2) {
        n++;
        if (nb %n == 0)
            return (0);
    }
    return (1);
}
