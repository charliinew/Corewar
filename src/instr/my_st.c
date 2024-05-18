/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_st.c
*/

#include "../../include/corewar.h"

static void st_copy(champion_t *champion, int32_t arg1, int32_t arg2, int pos)
{
    if ((arg1 < 1 || arg1 > 16) || (arg2 < 1 || arg2 > 16))
        return;
    champion->reg[arg2 - 1] = champion->reg[arg1 - 1];
    champion->PC = pos;
    champion->cycle_instruction = 4;
}

static void st_store(corewar_t *corewar, champion_t *champion, int32_t arg1,
    int32_t arg2, int pos)
{
    if (arg1 < 1 || arg1 > 16)
        return;
    write_into_memory(corewar->memory, (champion->PC + arg2 % IDX_MOD) %
        MEM_SIZE, champion->reg[arg1 - 1]);
    champion->PC = pos;
    champion->cycle_instruction = 4;
}

void my_st(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;
    int32_t arg[2];
    int pos = (champion->PC + 1) % MEM_SIZE;

    coding_byte = int_to_bin(corewar->memory[pos]);
    if (check_coding_byte(coding_byte, 2) == 84) {
        free(coding_byte);
        return;
    }
    pos = (pos + 1) % MEM_SIZE;
    arg[0] = get_arg(corewar, &pos, 1);
    arg[1] = get_arg(corewar, &pos, get_type(coding_byte, 2));
    if (get_type(coding_byte, 2) == 1)
        st_copy(champion, arg[0], arg[1], pos);
    else
        st_store(corewar, champion, arg[0], arg[1], pos);
    free(coding_byte);
}
