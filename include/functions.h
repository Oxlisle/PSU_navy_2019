/*
** EPITECH PROJECT, 2020
** function.h
** File description:
** functions
*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int check_touched(void);
char *get_attack(void);
void get_return(void);
int recieve_attack(void);
void send_attack(char *pos);
void print_map(char **map);
int player_two(void);
int player_one(void);
char **draw_boat(char **map, char **boat);
int error_boat_location(char **boats);
char **init_empty_map(void);
char **draw_map(char *pos);
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
int main_error(int ac, char **av);

#endif /* !FUNCTIONS_H_ */