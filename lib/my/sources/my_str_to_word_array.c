/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** my_str_to_word_array.c
*/

#include "my.h"
#include <stdlib.h>

int check_caract(char c)
{
    if (c >= 33 && c <= 126)
        return (1);
    else
        return (0);
}

int count_word(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check_caract(str[i + 1]) != 1 && check_caract(str[i]) == 1)
            nb++;
    }
    return (nb);
}

int mod_strlen(char const *str)
{
    int a = 0;

    while (check_caract(str[a]) == 1) {
        a++;
    }
    return (a);
}

char **my_str_to_word_array(char const *str)
{
    int word = count_word(str);
    char **result = malloc(sizeof(char *) * (word + 1));
    int nb = 0;
    int j = 0;

    for (int i = 0; i < word; i++) {
        result[i] = malloc(sizeof(char) * ((mod_strlen(&str[nb]) + 1)));
        while (check_caract(str[nb]) != 1) {
            nb++;
        }
        for (j = 0; check_caract(str[nb]) == 1; j++, nb++) {
            result[i][j] = str[nb];
        }
        result[i][j] = '\0';
        nb++;
    }
    result[word] = NULL;
    return (result);
}