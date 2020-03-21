/*
** EPITECH PROJECT, 2020
** check_touched.c
** File description:
** check_touched
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "functions.h"
#include "struct.h"

void return_handler(int sig, siginfo_t *siginfo, void *context)
{
    game.letter -= '@';
    if (sig == SIGUSR1) {
        game.enemy_map[game.nb - 1][(game.letter - 1) * 2] = 'o';
        my_putstr("missed");
    } if (sig == SIGUSR2) {
        my_putstr("hit");
        game.enemy_map[game.nb - 1][(game.letter - 1) * 2] = 'x';
        game.enemy_lives--;
    }
}

void get_return(void)
{
    struct sigaction act;

    my_putstr(": ");
    act.sa_sigaction = &return_handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR2, &act, NULL);
    sigaction(SIGUSR1, &act, NULL);
    pause();
}

void touched(void)
{
    usleep(1000);
    kill(game.enemy_pid, SIGUSR2);
    my_putchar(game.letter + ('A' - 1));
    my_put_nbr(game.nb);
    my_putstr(": hit");
    game.player_lives--;
}

void missed(void)
{
    usleep(1000);
    kill(game.enemy_pid, SIGUSR1);
    my_putchar(game.letter + ('A' - 1));
    my_put_nbr(game.nb);
    my_putstr(": missed");
}

int check_touched(void)
{
    int y = game.nb - 1;
    int x = (game.letter - 1) * 2;

    if (game.player_map[y][x] != '.') {
        game.player_map[y][x] = 'x';
        touched();
    } else {
        game.player_map[y][x] = 'o';
        missed();
    } return 1;
}