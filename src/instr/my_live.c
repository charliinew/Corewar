/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_live.c
*/

#include "../../include/corewar.h"

void my_live(corewar_t *corewar, champion_t *champion)
{
    int id = reconstruct_int(corewar->memory, (champion->PC + 1) % MEM_SIZE,
        4);
    champion_t *tmp = *corewar->champion;

    corewar->nb_live++;
    champion->cycle_instruction = 9;
    champion->PC = (champion->PC + 5) % MEM_SIZE;
    for (; tmp != NULL; tmp = tmp->next) {
        tmp->last_live = 0;
        if (tmp->reg[0] == id) {
            tmp->live++;
            tmp->last_live = 1;
        }
    }
    my_putstr("The player ");
    my_put_nbr(id);
    my_putstr("(");
    my_putstr(champion->header->prog_name);
    my_putstr(") is alive.\n");
}
