/*
** EPITECH PROJECT, 2020
** wait_connection.c
** File description:
** wait_connection
*/

#include "struct.h"
#include "functions.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void connected(int sig, siginfo_t *siginfo, void *ucontext)
{
    (void)sig;
    my_putstr("\n\nenemy connected");
    game.enemy_pid = siginfo->si_pid;
}

int wait_connection(char *map_path)
{
    struct sigaction wait;
    int my_pid = getpid();

    wait.sa_sigaction = &connected;
    wait.sa_flags = SA_SIGINFO;
    my_putstr("my pid: ");
    my_put_nbr(my_pid);
    my_putstr("\nwaiting for enemy connection...");
    sigemptyset(&wait.sa_mask);
    sigaction(SIGUSR2, &wait, NULL);
    pause();
    game.player_map = draw_map(map_path);
    game.enemy_map = init_empty_map();
    player_one();
    return 1;
}