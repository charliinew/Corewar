/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** memory.c
*/

#include "../../include/src.h"

static void display_return_line(int i)
{
    if (i % 32 == 0) {
        if (i != 0) {
            printf("\n");
        }
    }
}

void display_memory(u_int8_t *memoire, int taille)
{
    for (int i = 0; i < taille; i++) {
        display_return_line(i);
        printf("%02X ", memoire[i]);
    }
    printf("\n");
}

u_int8_t *init_memory(void)
{
    u_int8_t *memory = malloc(MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
    return memory;
}
