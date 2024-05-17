/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** add_to_memory.c
*/

#include "../../include/corewar.h"

void add_to_memory(u_int8_t *memory, unsigned char *champ,
    champion_t *champion)
{
    int pos = champion->flags->a;

    for (int i = 0; pos < MEM_SIZE; pos ++) {
        if (champ[i]) {
            memory[pos] = champ[i];
        }
        i ++;
    }
}
