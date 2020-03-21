/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_get_map.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
void redirect_all_stdout(void);

Test(print_map, print, .init=redirect_all_stdout)
{
    char *map[] = {". . . . . . . .", ". . . . . . . .", ". . . . . . . .", \
        ". . . . . . . .", ". . . . . . . .", ". . . . . . . .", \
        ". . . . . . . .", ". . . . . . . ." };
    print_map(map);
    cr_assert_stdout_eq_str(" |A B C D E F G H\n-+---------------\n\
1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n\
4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n\
7|. . . . . . . .\n8|. . . . . . . .\n");
}