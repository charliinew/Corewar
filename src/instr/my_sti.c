/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_sti.c
*/

#include "../../include/corewar.h"

static void exec_sti_next(corewar_t *corewar, champion_t *champion,
    int32_t arg[3])
{
    write_into_memory(corewar->memory, (champion->PC + (arg[1] + arg[2])
        % IDX_MOD) % MEM_SIZE, arg[0]);
}

static int exec_sti(corewar_t *corewar, champion_t *champion,
    int32_t arg[3], char *cdb)
{
    if (arg[0] < 1 || arg[0] > 16)
        return 84;
    else
        arg[0] = champion->reg[arg[0] - 1];
    if (get_type(cdb, 2) == 1 && (arg[1] >= 1 && arg[1] <= 16))
        arg[1] = champion->reg[arg[1] - 1];
    else if (get_type(cdb, 2) == 1 && !(arg[1] >= 1 && arg[1] <= 16))
        return 84;
    if (get_type(cdb, 3) == 1 && (arg[2] >= 1 && arg[2] <= 16))
        arg[2] = champion->reg[arg[2] - 1];
    else if (get_type(cdb, 3) == 1 && !(arg[2] >= 1 && arg[2] <= 16))
        return 84;
    exec_sti_next(corewar, champion, arg);
    return 0;
}

void my_sti(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg[3];
    int pos = (champion->PC + 1) % MEM_SIZE;

    coding_byte = int_to_bin(corewar->memory[pos]);
    if (check_coding_byte(coding_byte, 10) == 84) {
        free(coding_byte);
        return;
    }
    pos = (pos + 1) % MEM_SIZE;
    arg[0] = get_arg(corewar, &pos, 1);
    arg[1] = get_arg(corewar, &pos, get_type_index(coding_byte, 2));
    arg[2] = get_arg(corewar, &pos, get_type_index(coding_byte, 3));
    if (exec_sti(corewar, champion, arg, coding_byte) != 84) {
        champion->cycle_instruction = 24;
        champion->PC = pos;
    } else
        champion->PC = (champion->PC + 1) % MEM_SIZE;
    free(coding_byte);
}
