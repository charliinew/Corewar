/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** add_to_memory.c
*/

#include "../../include/corewar.h"

void add_to_memory(u_int8_t *memory, champion_t *champion)
{
    int pos = champion->flags->a;

    for (int i = 0; pos < MEM_SIZE; i++) {
        if (champion->robot[i]) {
            memory[pos] = champion->robot[i];
        }
        pos ++;
    }
}
