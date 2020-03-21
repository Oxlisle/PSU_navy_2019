/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_display_help.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
void redirect_all_stdout(void);
int display_help(void);

Test(display_help, help_message, .init=redirect_all_stdout)
{
    display_help();
    cr_assert_stdout_eq_str("USAGE\n\t./navy [first_player_pid] \
navy_positions\nDESCRIPTION\n\tfirst_player_pid: only for the \
2nd player. pid of the first player.\n\tnavy_positions: file \
representing the positions of the ships.\n", "");
}

Test(display_help, help_return)
{
    cr_assert_eq(display_help(), 0);
}