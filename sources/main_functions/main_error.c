/*
** EPITECH PROJECT, 2020
** main_error.c
** File description:
** main_error
*/

void my_putstr(char *str);
int my_strcmp(char *s1, char *s2);
int display_help(void);
int check_file(char *file_path);

int check_arguments(int ac, char **arg)
{
    if (ac == 2)
        return (check_file(arg[1]));
    return 1;
}

int main_error(int ac, char **av)
{
    if (ac == 1) {
        my_putstr("Not enough arguments. Please type -h for help.\n");
        return 84;
    }
    if (ac == 2) {
        if (!my_strcmp(av[1], "-h"))
            return (check_arguments(ac, av));
        else {
            return (display_help());
        }
    }
    if (ac == 3)
        return (check_arguments(ac, av));
    if (ac > 3) {
        my_putstr("Too much arguments. Please type -h for help.\n");
        return 84;
    }
    return 84;
}