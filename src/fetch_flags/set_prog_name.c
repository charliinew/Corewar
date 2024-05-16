/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_prog_name.c
*/

#include "../../include/corewar.h"

int set_prog_name(char **av, int pos, champion_t *champion)
{
    champion->flags->prog_name = my_strdup(av[pos]);
    if (champion->flags->prog_name == NULL)
        return 84;
    return 1;
}
