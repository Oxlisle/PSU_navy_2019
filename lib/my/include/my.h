/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Headers of library
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>

void my_free_array(char **array);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
char **my_str_to_word_array(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);

#endif /* !MY_H */
