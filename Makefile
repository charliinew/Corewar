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
		lib/my_getnbr_doop.c \
		src/fetch_flags/check_champion.c \
		src/fetch_flags/fetch_flags.c \
		src/fetch_flags/set_champion.c \
		src/fetch_flags/set_dump.c \
		src/fetch_flags/set_load_address.c \
		src/fetch_flags/set_prog_name.c \
		src/fetch_flags/set_prog_number.c \
		src/fetch_flags/set_positions.c \
		src/instr/my_live.c \
		src/instr/my_add.c \
		src/instr/my_aff.c \
		src/instr/my_and.c \
		src/instr/my_fork.c \
		src/instr/my_ld.c \
		src/instr/my_ldi.c \
		src/instr/my_lfork.c \
		src/instr/my_lld.c \
		src/instr/my_lldi.c \
		src/instr/my_or.c \
		src/instr/my_st.c \
		src/instr/my_sti.c \
		src/instr/my_sub.c \
		src/instr/my_xor.c \
		src/instr/my_zjmp.c \
		src/tools/int_to_bin.c \
		src/tools/reconstruct_int.c \
		src/tools/check_coding_byte.c \
		src/tools/get_type.c \
		src/tools/get_arg.c \
		src/tools/write_into_memory.c \
		src/execution/execution.c \
		src/memory/add_to_memory.c \
		src/free/free_struct.c \
		src/main.c \
		src/parsing/parsing.c \
		src/op.c \
		src/memory/memory.c \
		src/corewar_struct.c \
		src/main_loop.c \

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
