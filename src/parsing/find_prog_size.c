/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** find_prog_size.c
*/

#include "../../include/corewar.h"

void find_good_prog_size(champion_t *champion)
{
    champion->header->prog_size =
            ((champion->header->prog_size >> 24) & 0xFF) |
            ((champion->header->prog_size << 8) & 0xFF0000) |
            ((champion->header->prog_size >> 8) & 0xFF00) |
            ((champion->header->prog_size << 24) & 0xFF000000);
}
