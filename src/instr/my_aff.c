/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_aff.c
*/

#include "../../include/corewar.h"

static int exec_aff(champion_t *champion, int32_t arg1)
{
    if (arg1 < 1 || arg1 > 16)
        return 84;
    arg1 = champion->reg[arg1 - 1] % 256;
    my_putchar(arg1);
    return 0;
}

void my_aff(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg1;
    int pos = (champion->PC + 1) % MEM_SIZE;

    coding_byte = int_to_bin(corewar->memory[pos]);
    if (check_coding_byte(coding_byte, 15) == 84) {
        free(coding_byte);
        return;
    }
    pos = (pos + 1) % MEM_SIZE;
    arg1 = get_arg(corewar, &pos, 1);
    if (exec_aff(champion, arg1) != 84) {
        champion->cycle_instruction = 1;
        champion->PC = pos;
    } else
        champion->PC = (champion->PC + 1) % MEM_SIZE;
    free(coding_byte);
}
