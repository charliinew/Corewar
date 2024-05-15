/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_prog_number.c
*/

#include "../../include/corewar.h"

int set_prog_number(char **av, int *pos, champion_t *champion)
{
    if (av[*pos + 1] == NULL || champion->flags->n != -1)
        return 84;
    champion->flags->n = my_getnbr_doop(av[*pos + 1]);
    if (champion->flags->n == -1)
        return 84;
    *pos += 1;
    return 0;
}
