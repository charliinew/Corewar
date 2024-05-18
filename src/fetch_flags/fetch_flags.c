/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** fetch_flags.c
*/

#include "../../include/corewar.h"

static int check_flags(char **av, int *pos, champion_t **champion, int *dump)
{
    if (my_strcmp(av[*pos], "-dump") == 0)
        return set_dump(av, pos, dump);
    if (my_strcmp(av[*pos], "-n") == 0)
        return set_prog_number(av, pos, *champion);
    if (my_strcmp(av[*pos], "-a") == 0)
        return set_load_address(av, pos, *champion);
    return set_prog_name(av, *pos, *champion);
}

static void add_champion(champion_t **begin, champion_t *tmp)
{
    champion_t *add = *begin;

    if (*begin == NULL) {
        *begin = tmp;
        return;
    }
    for (; add->next != NULL; add = add->next);
    add->next = tmp;
}

static int champion_flags(int *dump, champion_t **begin,
    int *pos, char **av)
{
    int status;
    champion_t *tmp;

    if (av[*pos] == NULL)
        return 1;
    tmp = set_champion();
    if (tmp == NULL)
        return 84;
    for (; av[*pos] != NULL; (*pos)++) {
        status = check_flags(av, pos, &tmp, dump);
        if (status != 0)
            break;
    }
    if (status == 84)
        return 84;
    if (status == 1) {
        *pos += 1;
    }
    add_champion(begin, tmp);
    return 0;
}

int fetch_flags(char **av, corewar_t *corewar)
{
    int i = 0;
    int pos = 1;
    int status;

    for (; i < 4; i++) {
        status = champion_flags(&corewar->dump,
            corewar->champion, &pos, av);
        if (status != 0)
            break;
    }
    if (status == 84 || av[pos] != NULL)
        return 84;
    if (check_champion(corewar) == 84)
        return 84;
    return 0;
}
