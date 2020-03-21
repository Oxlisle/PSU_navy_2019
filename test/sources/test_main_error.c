/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_check_arguments.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
void redirect_all_stdout(void);
int main_error(int ac, char **av);

Test(main_error, nothing)
{
    char **av = malloc(sizeof(char *) * 1);

    cr_assert_eq(main_error(0, av), 84);
    free(av);
}

Test(main_error, too_much_arg, .init=redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 1);

    main_error(5, av);
    cr_assert_stdout_eq_str("Too much arguments. Please type -h for help.\n");
    free(av);
}

Test(main_error, too_much_arg_return)
{
    char **av = malloc(sizeof(char *) * 1);

    cr_assert_eq(main_error(5, av), 84);
    free(av);
}

Test(main_error, not_enough_arg_return, .init=redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 1);

    main_error(1, av);
    cr_assert_stdout_eq_str("Not enough arguments. Please type -h for help.\n");
    free(av);
}

Test(main_error, not_enough_arg)
{
    char **av = malloc(sizeof(char *) * 1);

    cr_assert_eq(main_error(1, av), 84);
    free(av);
}

Test(main_error, call_help, .init=redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 3);

    av[0] = "./navy";
    av[1] = "-h";
    main_error(2, av);
    cr_assert_stdout_eq_str("USAGE\n\t./navy [first_player_pid] navy_positio\
ns\nDESCRIPTION\n\tfirst_player_pid: only for the 2nd player. pid of the first \
player.\n\tnavy_positions: file representing the positions \
of the ships.\n");
    free(av);
}

Test(main_error, check_arg)
{
    char **av = malloc(sizeof(char *) * 3);

    av[0] = "./navy";
    av[1] = "ressources/valid_positions";

    cr_assert_eq(main_error(2, av), 1);
    free(av);
}