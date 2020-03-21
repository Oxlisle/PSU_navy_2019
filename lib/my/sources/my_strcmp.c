/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** task06
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int one = my_strlen(s1);
    int two = my_strlen(s2);

    if (one != two)
        return 0;
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}
