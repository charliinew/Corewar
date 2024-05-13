##
## EPITECH PROJECT, 2024
## MAKEFILE
## File description:
## makefile
##

SRC = 	lib/my_put_nbr.c \
		lib/my_putchar.c \
		lib/my_putstr.c \
		lib/my_strcat.c \
		lib/my_strlen.c \
		lib/my_getnbr.c \
		lib/my_strcmp.c \
		lib/my_str_to_word_array.c \
		lib/my_strcpy.c \
		lib/my_strdup.c \
		lib/my_puterror.c \
		lib/my_putsterror.c \
		lib/copy_tab_tab.c \
		src/main.c \

OBJ	=	$(SRC:.c=.o)

NAME	= corewar

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME)  $(OBJ) -g -I./include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
