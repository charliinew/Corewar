/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** add_to_memory.c
*/

#include "../../include/corewar.h"

void add_to_memory(char *memory, champion_t *champion)
{
    static int pos = 0;

    for (int i = 0; i < MEM_SIZE; i++) {
        if (champion->robot[i]) {
            memory[pos] = champion->robot[i];
            pos ++;
        }
    }
    pos ++;
}