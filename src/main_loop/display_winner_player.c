/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** display_winner_player.c
*/

#include "../../include/corewar.h"


void display_winner_player(corewar_t *corewar)
{
    champion_t *tmp = *corewar->champion;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->last_live == 1) {
            my_putstr("The player ");
            my_put_nbr(tmp->reg[0]);
            my_putstr("(");
            my_putstr(tmp->header->prog_name);
            my_putstr(") has won.\n");
            return;
        }
    }
}
