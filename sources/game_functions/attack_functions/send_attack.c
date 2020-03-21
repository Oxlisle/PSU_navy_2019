/*
** EPITECH PROJECT, 2020
** send_attack.c
** File description:
** send_attack
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "functions.h"
#include "struct.h"

int check_attack(char *buffer)
{
    if (buffer[0] < 'A' || buffer[0] > 'F')
        return 0;
    if (my_getnbr(&buffer[1]) > 8 || my_getnbr(&buffer[1]) == 0)
        return 0;
    return 1;
}

char *get_attack(void)
{
    char *buffer = NULL;
    size_t size = 0;
    while (1) {
        if (getline(&buffer, &size, stdin) == -1)
            return NULL;
        if (my_strlen(buffer) == 3 && check_attack(buffer))
            break;
        my_putstr("wrong position\nattack: ");
    }
    buffer[my_strlen(buffer) - 1] = '\0';
    return (buffer);
}

void send_attack(char *pos)
{
    game.letter = pos[0];
    for (char i = ('A' - 1); i != pos[0]; i++) {
        kill(game.enemy_pid, SIGUSR1);
        usleep(1000);
    }
    kill(game.enemy_pid, SIGUSR2);
    usleep(1000);
    game.nb = pos[1];
    for (int i = 0; i != my_getnbr(&pos[1]); i++) {
        kill(game.enemy_pid, SIGUSR1);
        usleep(1000);
    }
    kill(game.enemy_pid, SIGUSR2);
}