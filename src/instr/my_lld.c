/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_lld.c
*/

#include "../../include/corewar.h"

static void exec_lld(corewar_t *corewar, champion_t *champion,
                    int32_t arg1, int32_t arg2)
{
    if (arg2 < 1 || arg2 > 16) {
        champion->carry = 1;
        return;
    }
    champion->reg[arg2 - 1] = arg1;
    if (arg1 == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    write_into_memory(corewar->memory, (champion->PC + arg1) % MEM_SIZE,
        arg1);
}

void my_lld(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg1;
    int32_t arg2;

    champion->PC = (champion->PC + 1) % MEM_SIZE;
    coding_byte = int_to_bin(corewar->memory[champion->PC]);
    if (check_coding_byte(coding_byte, 12) == 84) {
        free(coding_byte);
        return;
    }
    champion->cycle_instruction = 9;
    champion->PC = (champion->PC + 1) % MEM_SIZE;
    arg1 = get_arg(corewar, champion, get_type(coding_byte, 1));
    arg2 = get_arg(corewar, champion, 1);
    exec_lld(corewar, champion, arg1, arg2);
    free(coding_byte);
}
