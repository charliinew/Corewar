/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_live.c
*/

#include "../../include/corewar.h"

void my_live(corewar_t *corewar, champion_t *champion)
{
    corewar->nb_live++;
    champion->live++;
    champion->cycle_instruction = 9;
    champion->PC += 5;
    my_putstr("The player ");
    my_put_nbr(champion->reg[0]);
    my_putstr("(");
    my_putstr(champion->flags->prog_name);
    my_putstr(") is alive.\n");
}
