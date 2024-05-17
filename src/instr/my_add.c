/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** add.c
*/

#include "../../include/corewar.h"

static void exect_add(corewar_t *corewar, champion_t *champion, int32_t arg[3])
{
    int sum;

    if ((arg[0] < 1 || arg[0] > 16) || (arg[1] < 1 || arg[1] > 16) ||
        (arg[2] < 1 || arg[2] > 16)) {
        champion->carry = 1;
        return;
    }
    sum = champion->reg[arg[0] - 1] + champion->reg[arg[1] - 1];
    champion->reg[arg[2] - 1] = sum;
    if (sum == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
}

void my_add(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg1;
    int32_t arg2;
    int32_t arg3;

    champion->PC = (champion->PC + 1) % MEM_SIZE;
    coding_byte = int_to_bin(corewar->memory[champion->PC]);
    if (check_coding_byte(coding_byte, 3) == 84) {
        free(coding_byte);
        return;
    }
    champion->cycle_instruction = 9;
    arg1 = get_arg(corewar, champion, 1);
    arg2 = get_arg(corewar, champion, 1);
    arg3 = get_arg(corewar, champion, 1);
    exect_add(corewar, champion, (int32_t[3]){arg1, arg2, arg3});
    free(coding_byte);
    return;
}
