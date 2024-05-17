/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** add.c
*/

#include "../../include/corewar.h"

static void exect_add(corewar_t *corewar, champion_t *champion, int32_t arg1,
    int32_t arg2)
{
    int sum = arg1 + arg2;
    int32_t arg3= get_arg(corewar, champion, 1);

    if (sum == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->reg[arg3 - 1] = sum;
}

void my_add(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg1;
    int32_t arg2;
    champion->PC = (champion->PC + 1) % MEM_SIZE;
    coding_byte = int_to_bin(corewar->memory[champion->PC]);
    if (check_coding_byte(coding_byte, 3) == 84) {
        free(coding_byte);
        return;
    }
    champion->cycle_instruction = 9;
    arg1 = get_arg(corewar, champion, 1);
    arg2 = get_arg(corewar, champion, 1);
    exect_add(corewar, champion, arg1, arg2);
    free(coding_byte);
    return;
}
