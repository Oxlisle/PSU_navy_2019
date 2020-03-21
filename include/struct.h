/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct map_s {
    char **player_map;
    char **enemy_map;
    int player_lives;
    int enemy_lives;
    int enemy_pid;
    int actual_sign;
    int letter;
    int nb;
    int type;
} map_t;

map_t game;

#endif /* !STRUCT_H_ */