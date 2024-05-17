/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_ldi.c
*/

#include "../../include/corewar.h"

static void exec_ldi_next(corewar_t *corewar, champion_t *champion,
    int32_t arg[3])
{
    int32_t sum = reconstruct_int(corewar->memory, (champion->PC + arg[0]
        % IDX_MOD) % MEM_SIZE, 2);
    int32_t copy;

    sum += arg[1];
    copy = reconstruct_int(corewar->memory, (champion->PC + sum % IDX_MOD)
        % MEM_SIZE, 4);
    champion->reg[arg[2] - 1] = copy;
    if (champion->reg[arg[2] - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
}

static void exec_ldi(corewar_t *corewar, champion_t *champion,
                     int32_t arg[3], char *cdb)
{
    if (get_type(cdb, 1) == 1 && (arg[0] >= 1 && arg[0] <= 16)) {
        arg[0] = champion->reg[arg[0] - 1];
    } else {
        champion->carry = 1;
        return;
    }
    if (get_type(cdb, 2) == 1 && (arg[1] >= 1 && arg[1] <= 16)) {
        arg[1] = champion->reg[arg[1] - 1];
    } else {
        champion->carry = 1;
        return;
    }
    if (arg[2] < 1 || arg[2] > 16) {
        champion->carry = 1;
        return;
    }
    exec_ldi_next(corewar, champion, arg);
}

void my_ldi(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg1;
    int32_t arg2;
    int32_t arg3;

    champion->PC = (champion->PC + 1) % MEM_SIZE;
    coding_byte = int_to_bin(corewar->memory[champion->PC]);
    if (check_coding_byte(coding_byte, 9) == 84) {
        free(coding_byte);
        return;
    }
    champion->cycle_instruction = 24;
    arg1 = get_arg(corewar, champion, get_type_index(coding_byte, 1));
    arg2 = get_arg(corewar, champion, get_type_index(coding_byte, 2));
    arg3 = get_arg(corewar, champion, 1);
    exec_ldi(corewar, champion,
             (int32_t[3]){arg1, arg2, arg3}, coding_byte);
    free(coding_byte);
}
