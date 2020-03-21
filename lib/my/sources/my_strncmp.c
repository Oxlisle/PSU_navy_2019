/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    return 1;
}