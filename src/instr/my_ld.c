/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_ld.c
*/

#include "../../include/corewar.h"

static void exec_ld(corewar_t *corewar, champion_t *champion, int32_t arg[2])
{
    if (arg[1] < 1 || arg[1] > 16) {
        champion->carry = 1;
        return;
    }
    champion->reg[arg[1] - 1] = reconstruct_int(corewar->memory,
        (champion->PC + arg[0] % IDX_MOD) % MEM_SIZE, 4);
    if (champion->reg[arg[1] - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
}

void my_ld(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg1;
    int32_t arg2;

    champion->PC = (champion->PC + 1) % MEM_SIZE;
    coding_byte = int_to_bin(corewar->memory[champion->PC]);
    if (check_coding_byte(coding_byte, 1) == 84) {
        free(coding_byte);
        return;
    }
    champion->cycle_instruction = 4;
    champion->PC = (champion->PC + 1) % MEM_SIZE;
    arg1 = get_arg(corewar, champion, get_type(coding_byte, 1));
    arg2 = get_arg(corewar, champion, 1);
    exec_ld(corewar, champion, (int32_t[2]){arg1, arg2});
    free(coding_byte);
}
