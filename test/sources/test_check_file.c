/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_check_file.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
void redirect_all_stdout(void);
int check_file(char *file_path);

Test(check_file, fd_no_exist, .init=redirect_all_stdout)
{
    char **file = malloc(sizeof(char *) * 2);

    file[0] = "ressources/no";
    check_file(file[0]);
    cr_assert_stdout_eq_str("This file doesn't exist.\n");
    free(file);
}

Test(check_file, invald_file, .init=redirect_all_stdout)
{
    char **file = malloc(sizeof(char *) * 2);

    file[0] = "ressources/invalid_positions";
    check_file(file[0]);
    cr_assert_stdout_eq_str("You're file is invalid.\n");
    free(file);
}

Test(check_boat_size, invald_file)
{
    char **file = malloc(sizeof(char *) * 2);

    file[0] = "ressources/invalid_boat_size_first";
    cr_assert_eq(check_boat_size(file[0]), 0);
    free(file);
}

Test(check_boat_size, vald_file)
{
    char **file = malloc(sizeof(char *) * 2);

    file[0] = "ressources/valid_positions";
    cr_assert_eq(check_boat_size(file[0]), 0);
    free(file);
}