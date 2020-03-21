##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compilating unit tests
##

SRCTEST	=	sources/redirect.c\
			sources/test_display_help.c\
			sources/test_main_error.c\
			sources/test_check_file.c\
			sources/test_error_boat.c\
			sources/test_get_map.c\

SRC		=	../sources/main_functions/check_file.c\
			../sources/main_functions/display_help.c\
			../sources/main_functions/main_error.c\
			../sources/game_functions/generate_map/error_boat.c\
			../sources/game_functions/generate_map/get_boat.c\
			../sources/game_functions/generate_map/get_map.c\


OBJTEST	=	$(SRCTEST:%.c=%.o)

OBJ     =       $(SRC:%.c=%.o)

NAME    =       unit_test

CC      =       gcc

CFLAGS  =       -Wall --coverage -I ../include/

LDFLAGS =       -L../lib/my -lmy -lcriterion -lgcov

all     :       $(NAME)

$(NAME) :       $(OBJTEST) $(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(OBJTEST) $(LDFLAGS)

clean   :
		$(RM) -f $(OBJTEST)
		$(RM) -f $(OBJ)
		$(RM) -f sources/*.gc*
		$(RM) -f ../sources/main_functions/*.gc*
		$(RM) -f ../sources/game_functions/*.gc*
		$(RM) -f ../sources/game_functions/attack_functions/*.gc*
		$(RM) -f ../sources/game_functions/creating_game/*.gc*
		$(RM) -f ../sources/game_functions/generate_map/*.gc*

fclean  :       clean
		$(RM) -f $(NAME)

re      :   fclean all

.PHONY  : 	re fclean clean all
