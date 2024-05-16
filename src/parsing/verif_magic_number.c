/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** verif_magic_number.c
*/

#include "../../include/corewar.h"

int verif_magic_number(champion_t *champion)
{
    champion->header->magic = ((champion->header->magic >> 24) & 0xFF) |
        ((champion->header->magic << 8) & 0xFF0000) |
            ((champion->header->magic >> 8) & 0xFF00) |
            ((champion->header->magic << 24) & 0xFF000000);
    if (champion->header->magic != COREWAR_EXEC_MAGIC)
        return 84;
    return 0;
}
