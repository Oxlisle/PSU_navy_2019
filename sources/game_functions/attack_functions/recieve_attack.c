/*
** EPITECH PROJECT, 2020
** receive_attack.c
** File description:
** recieve_attack
*/

#include "functions.h"
#include "struct.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int handler(int sig, siginfo_t *siginfo, void *context)
{
    (void)siginfo;
    (void)context;
    if (sig == SIGUSR2)
        game.type++;
    if (sig == SIGUSR1 && game.type == 1)
        game.letter++;
    else if (sig == SIGUSR1 && game.type == 2)
        game.nb++;
    return 1;
}

int recieve_attack(void)
{
    struct sigaction att;

    att.sa_sigaction = &handler;
    att.sa_flags = SA_SIGINFO;
    sigemptyset(&att.sa_mask);
    sigaction(SIGUSR1, &att, NULL);
    sigaction(SIGUSR2, &att, NULL);
    pause();
    return 1;
}