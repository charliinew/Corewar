##
## EPITECH PROJECT, 2024
## MAKEFILE
## File description:
## makefile
##

OBJ	=	$(SRC:.c=.o)

NAME	= corewar


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
		lib/my_getnbr_doop.c \
		src/main.c \
		src/parsing/parsing.c \
		src/op.c \
		src/memory/memory.c \
		src/corewar_struct.c \
		src/fetch_flags/check_champion.c \
		src/fetch_flags/fetch_flags.c \
		src/fetch_flags/set_champion.c \
		src/fetch_flags/set_dump.c \
		src/fetch_flags/set_load_address.c \
		src/fetch_flags/set_prog_name.c \
		src/fetch_flags/set_prog_number.c \
		src/memory/add_to_memory.c \
		src/fetch_flags/set_positions.c \
		src/free/free_struct.c

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME)  $(OBJ) -g -I./include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
