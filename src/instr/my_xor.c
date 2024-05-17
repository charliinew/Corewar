/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_xor.c
*/

#include "../../include/corewar.h"

static int exec_xor(champion_t *champion, int32_t arg[3], char *cdb)
{
    if (get_type(cdb, 1) == 1 && (arg[0] >= 1 && arg[0] <= 16)) {
        arg[0] = champion->reg[arg[0] - 1];
    } else if (get_type(cdb, 1) == 1 && !(arg[0] >= 1 && arg[0] <= 16)) {
        champion->carry = 1;
        return 84;
    }
    if (get_type(cdb, 2) == 1 && (arg[1] >= 1 && arg[1] <= 16)) {
        arg[1] = champion->reg[arg[1] - 1];
    } else if (get_type(cdb, 2) == 1 && !(arg[1] >= 1 && arg[1] <= 16)) {
        champion->carry = 1;
        return 84;
    }
    if (arg[2] < 1 || arg[2] > 16) {
        champion->carry = 1;
        return 84;
    }
    champion->reg[arg[2] - 1] = arg[0] ^ arg[1];
    champion->carry = (champion->reg[arg[2] - 1] == 0) ? 1 : 0;
    return 0;
}

void my_xor(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg[3];
    int pos = (champion->PC + 1) % MEM_SIZE;

    coding_byte = int_to_bin(corewar->memory[pos]);
    if (check_coding_byte(coding_byte, 7) == 84) {
        free(coding_byte);
        return;
    }
    pos = (pos + 1) % MEM_SIZE;
    arg[0] = get_arg(corewar, &pos, get_type(coding_byte, 1));
    arg[1] = get_arg(corewar, &pos, get_type(coding_byte, 2));
    arg[2] = get_arg(corewar, &pos, 1);
    if (exec_xor(champion, arg, coding_byte) != 84) {
        champion->cycle_instruction = 5;
        champion->PC = pos;
    } else
        champion->PC = (champion->PC + 1) % MEM_SIZE;
    free(coding_byte);
}
