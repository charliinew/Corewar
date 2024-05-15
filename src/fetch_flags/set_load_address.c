/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_load_address.c
*/

#include "../../include/corewar.h"

int set_load_address(char **av, int *pos, champion_t *champion)
{
    if (av[*pos + 1] == NULL || champion->flags->a != -1)
        return 84;
    champion->flags->a = my_getnbr_doop(av[*pos + 1]);
    if (champion->flags->a == -1)
        return 84;
    *pos += 1;
    return 0;
}
