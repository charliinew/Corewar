/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** parsing.c
*/

#include "../../include/corewar.h"

static int verif_open(champion_t *champion)
{
    int fd;

    fd = open(champion->flags->prog_name, O_RDONLY);
    if (fd == -1)
        return 84;
    if (champion->header == NULL) {
        champion->header = (header_t *)malloc(sizeof(header_t));
        if (champion->header == NULL) {
            close(fd);
            return 84;
        }
    }
    if (read(fd, champion->header, sizeof(header_t)) != sizeof(header_t)) {
        close(fd);
        free(champion->header);
        return 84;
    }
    close(fd);
    return 0;
}

int parsing(corewar_t *corewar)
{
    for (int i = 0; i < corewar->nb_champion; i++) {
        if (verif_open(corewar->champion[i]) == 84)
            return 84;
    }
    return 0;
}
