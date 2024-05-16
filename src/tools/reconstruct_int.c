/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** reconstruct_int.c
*/

#include "../../include/corewar.h"

int32_t reconstruct_int(uint8_t *memory, int index, int num_bytes)
{
    int32_t result = 0;
    int shift = (num_bytes - 1) * 8;

    for (int i = 0; i < num_bytes; i++) {
        result |= (int32_t)memory[(index + i) % MEM_SIZE] << shift;
        shift -= 8;
    }
    return result;
}
