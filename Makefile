##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC	=	lib/my_putchar.c	\
		lib/my_putstr.c		\
		lib/my_putnbr.c		\
		lib/my_strlen.c 	\
		lib/my_getnbr.c		\
		lib/my_strdup.c 	\
		lib/getpwd.c 		\
		lib/my_str_to_word_array.c 	\
		lib/my_strcat.c 	\
		lib/test_str.c 		\
		isthere.c 			\
		cd_command.c 		\
		shell.c 			\
		env.c 				\
		main.c				\
		tree.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CPPFLAGS	=	-g3 -I./include/ -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY:	fclean
fclean: clean
	$(RM) $(NAME)

.PHONY:	re
re:	fclean all
