/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "struct.h"
int main_error(int ac, char **av);
int wait_connection(char *map_path);
int try_connection(char *first_pid, char *map_path);

int main(int ac, char **av)
{
    int check = main_error(ac, av);

    if (check == 84 || check == 0)
        return check;
    game.player_lives = 14;
    game.enemy_lives = 14;
    game.nb = 0;
    game.letter = 0;
    game.type = 1;
    if (ac == 2)
        wait_connection(av[1]);
    if (ac == 3)
        try_connection(av[1], av[2]);
}