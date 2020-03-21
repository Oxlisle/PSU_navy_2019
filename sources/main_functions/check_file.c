/*
** EPITECH PROJECT, 2020
** check_file.c
** File description:
** check_file
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void my_putstr(char *str);
int my_getnbr(char const *str);

int check_boat_size(char *file)
{
    int boat_size = 2;
    int i = 0;

    if ((file[0] - '0') != boat_size) {
        my_putstr("You're file is invalid.\n");
        return 0;
    }
    while (1) {
        for (; file[i] != '\n' && file[i] != '\0'; i++);
        i++;
        boat_size += 1;
        if (file[i - 1] == '\0')
            return 1;
        if ((file[i] - '0') != boat_size) {
            my_putstr("You're file is invalid.\n");
            return 0;
        }
    }
}

int check_file(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char *file = malloc(sizeof(char) * 31);

    if (fd < 0) {
        my_putstr("This file doesn't exist.\n");
        free(file);
        close(fd);
        return 0;
    } else {
        read(fd, file, 31);
        if (!check_boat_size(file)) {
            free(file);
            close(fd);
            return 0;
        }
    } return 1;
}