/*
** EPITECH PROJECT, 2020
** player_1.c
** File description:
** player_1
*/

#include "struct.h"
#include "functions.h"
#include <unistd.h>
#include <signal.h>

int end_game(void)
{
    if (game.enemy_lives == 0) {
        my_putstr("\nI won");
        return 0;
    } else {
        my_putstr("Enemy won");
        return 1;
    }
}

void init_turn(void)
{
    game.letter = 0;
    game.nb = 0;
    game.type = 1;
    my_putstr("\n\nmy positions:\n");
    print_map(game.player_map);
    my_putstr("\nenemy's positions:\n");
    print_map(game.enemy_map);
}

int player_two(void)
{
    char *attack;

    init_turn();
    my_putstr("\nwaiting for enemy's attack...\n");
    game.letter = 0;
    game.nb = 0;
    while (game.type != 3)
        recieve_attack();
    check_touched();
    my_putstr("\n\nattack: ");
    if ((attack = get_attack()) == NULL)
        return 1;
    send_attack(attack);
    my_putstr(attack);
    game.letter = attack[0];
    game.nb = my_getnbr(&attack[1]);
    get_return();
    if (game.enemy_lives == 0 || game.player_lives == 0)
        return (end_game());
    else
        return (player_two());
}

int player_one(void)
{
    char *attack;

    init_turn();
    my_putstr("\nattack: ");
    if ((attack = get_attack()) == NULL)
        return 1;
    send_attack(attack);
    my_putstr(attack);
    game.letter = attack[0];
    game.nb = my_getnbr(&attack[1]);
    get_return();
    my_putstr("\n\nwaiting for enemy's attack...\n");
    game.letter = 0;
    game.nb = 0;
    while (game.type != 3)
        recieve_attack();
    check_touched();
    if (game.enemy_lives == 0 || game.player_lives == 0)
        return (end_game());
    else
        return (player_one());
}