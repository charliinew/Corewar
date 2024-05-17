/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_lld.c
*/

#include "../../include/corewar.h"

static int exec_lld(corewar_t *corewar, champion_t *champion, int32_t arg[2])
{
    if (arg[1] < 1 || arg[1] > 16) {
        champion->carry = 1;
        return 84;
    }
    champion->reg[arg[1] - 1] = reconstruct_int(corewar->memory,
        (champion->PC + 2 + arg[0]) % MEM_SIZE, 4);
    if (champion->reg[arg[1] - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    return 0;
}

void my_lld(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg[2];
    int pos = (champion->PC + 1) % MEM_SIZE;

    coding_byte = int_to_bin(corewar->memory[pos]);
    if (check_coding_byte(coding_byte, 12) == 84) {
        free(coding_byte);
        return;
    }
    pos = (pos + 1) % MEM_SIZE;
    arg[0] = get_arg(corewar, &pos, get_type(coding_byte, 1));
    arg[1] = get_arg(corewar, &pos, 1);
    if (exec_lld(corewar, champion, arg) != 84) {
        champion->cycle_instruction = 9;
        champion->PC = pos;
    } else
        champion->PC = (champion->PC + 1) % MEM_SIZE;
    free(coding_byte);
}
