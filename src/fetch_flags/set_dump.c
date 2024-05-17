/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** fetch_dump.c
*/

#include "../../include/corewar.h"

int set_dump(char **av, int *pos, int *dump)
{
    if (av[*pos + 1] == NULL || *dump != -1)
        return 84;
    *dump = my_getnbr_doop(av[*pos + 1]);
    if (*dump < 0)
        return 84;
    *pos += 1;
    return 0;
}
