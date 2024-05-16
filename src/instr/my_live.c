/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_live.c
*/

#include "../../include/corewar.h"

void my_live(corewar_t *corewar, champion_t *champion)
{
    int id = reconstruct_int(corewar->memory, champion->PC + 1, 4);
    int i;

    corewar->nb_live++;
    champion->cycle_instruction = 9;
    champion->PC = (champion->PC + 5) % MEM_SIZE;
    for (i = 0; i < corewar->nb_champion; i++) {
        if (corewar->champion[i]->reg[0] == id)
            corewar->champion[i]->live++;
    }
    my_putstr("The player ");
    my_put_nbr(id);
    my_putstr("(");
    my_putstr(champion->flags->prog_name);
    my_putstr(") is alive.\n");
}
