/*
** EPITECH PROJECT, 2020
** try_connection.c
** File description:
** try_connection
*/

#include "struct.h"
#include "functions.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int try_connection(char *first_pid, char *map_path)
{
    if (kill(my_getnbr(first_pid), SIGUSR2) < 0)
        return 84;
    my_putstr("my pid: ");
    my_put_nbr(getpid());
    my_putstr("\nsuccessfully connected");
    game.enemy_pid = my_getnbr(first_pid);
    game.player_map = draw_map(map_path);
    game.enemy_map = init_empty_map();
    player_two();
    return 1;
}