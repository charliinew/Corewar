/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_sub.c
*/

#include "../../include/corewar.h"

static int exec_sub(champion_t *champion, int32_t arg[3])
{
    int sub;

    if ((arg[0] < 1 || arg[0] > 16) || (arg[1] < 1 || arg[1] > 16) ||
        (arg[2] < 1 || arg[2] > 16)) {
        champion->carry = 1;
        return 84;
    }
    sub = champion->reg[arg[0] - 1] - champion->reg[arg[1] - 1];
    champion->reg[arg[2] - 1] = sub;
    if (sub == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    return 0;
}

void my_sub(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg[3];
    int pos = (champion->PC + 1) % MEM_SIZE;

    coding_byte = int_to_bin(corewar->memory[pos]);
    if (check_coding_byte(coding_byte, 4) == 84) {
        free(coding_byte);
        return;
    }
    pos = (pos + 1) % MEM_SIZE;
    arg[0] = get_arg(corewar, &pos, 1);
    arg[1] = get_arg(corewar, &pos, 1);
    arg[2] = get_arg(corewar, &pos, 1);
    if (exec_sub(champion, arg) != 84) {
        champion->cycle_instruction = 9;
        champion->PC = pos;
    } else
        champion->PC = (champion->PC + 1) % MEM_SIZE;
    free(coding_byte);
}
