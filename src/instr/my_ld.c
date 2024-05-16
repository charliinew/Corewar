/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_ld.c
*/

#include "../../include/corewar.h"

void my_ld(corewar_t *corewar, champion_t *champion)
{
    char *coding_byte = NULL;

    champion->PC = (champion->PC + 1) % MEM_SIZE;
    coding_byte = int_to_bin(corewar->memory[champion->PC]);

    free(coding_byte);
    return;
}
