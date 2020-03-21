##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compiling the library
##

SRC		=	sources/my_getnbr.c\
			sources/my_is_prime.c\
			sources/my_isneg.c\
			sources/my_put_nbr.c\
			sources/my_putchar.c\
			sources/my_putstr.c\
			sources/my_str_isalpha.c\
			sources/my_str_islower.c\
			sources/my_str_isnum.c\
			sources/my_str_isprintable.c\
			sources/my_str_isupper.c\
			sources/my_strcat.c\
			sources/my_strlen.c\
			sources/my_str_to_word_array.c\
			sources/my_strcmp.c\
			sources/my_strncmp.c\
			sources/my_free_array.c\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wshadow -Wextra -Iinclude/

CC		=	gcc

all 	:	$(NAME) clean

$(NAME)	:	$(OBJ)
			$(AR) rcs $(NAME) $(OBJ)

clean	:
			$(RM) -f $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re 		: 	fclean all

.PHONY	:	clean fclean re