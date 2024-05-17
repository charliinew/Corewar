/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_champion.c
*/

#include "../../include/corewar.h"

static void find_nb_id(corewar_t *corewar)
{
    champion_t *tmp = *corewar->champion;

    for (int i = 0; tmp != NULL; tmp = tmp->next) {
        if (tmp != NULL) {
            corewar->nb_champion ++;
            tmp->id = i + 1;
            i++;
        } else
            break;
    }
}

int check_champion(corewar_t *corewar)
{
    champion_t *tmp = *corewar->champion;

    find_nb_id(corewar);
    if (corewar->nb_champion < 2)
        return 84;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->flags->prog_name == NULL)
            return 84;
        if (tmp->flags->a >= MEM_SIZE)
            return 84;
    }
    set_n_flags(corewar->champion);
    set_position(corewar);
    set_champion_next(corewar);
    return 0;
}
