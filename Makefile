##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	sources/main_functions/main.c\
			sources/main_functions/main_error.c\
			sources/main_functions/display_help.c\
			sources/main_functions/check_file.c\
			sources/game_functions/creating_game/wait_connection.c\
			sources/game_functions/creating_game/try_connection.c\
			sources/game_functions/generate_map/error_boat.c\
			sources/game_functions/generate_map/get_boat.c\
			sources/game_functions/generate_map/get_map.c\
			sources/game_functions/loop.c\
			sources/game_functions/attack_functions/send_attack.c\
			sources/game_functions/attack_functions/recieve_attack.c\
			sources/game_functions/attack_functions/check_touched.c\

OBJ		=	$(SRC:.c=.o)

NAME	=	navy

LDFLAGS	=	-Llib/my -lmy

CFLAGS	=	-Wall -Wshadow -Wextra -Iinclude/ -g

CC		=	gcc

all		:	lib_all $(NAME) clean

lib_cl	:
			make fclean -C lib/my

lib_all	:
			make -C lib/my

test_fcl	:	
			make fclean -C test

tests_run:	lib_all
			make -C test/
			$(RM) -f test/sources/*.gc*
			./test/unit_test

$(NAME)	:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
			$(RM) $(OBJ)
			make clean -C lib/my

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C lib/my
			make fclean -C test

re		:	fclean all clean

.PHONY	:	all clean fclean re