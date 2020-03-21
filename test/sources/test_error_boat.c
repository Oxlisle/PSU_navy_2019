/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_error_boat.c
*/

/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_check_file.c
*/

#include <criterion/criterion.h>

Test(vertical_check, error)
{
    char *boat = "2:C2:C6";

    cr_assert_eq(vertical_check(boat), 84);
}

Test(vertical_check, passed)
{
    char *boat = "2:C2:C3";

    cr_assert_eq(vertical_check(boat), 0);
}

Test(horizontal_check, error)
{
    char *boat = "2:A2:C2";

    cr_assert_eq(horizontal_check(boat), 84);
}

Test(horizontal_check, passed)
{
    char *boat = "2:A2:B2";

    cr_assert_eq(horizontal_check(boat), 0);
}