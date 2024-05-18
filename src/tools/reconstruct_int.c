/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** reconstruct_int.c
*/

#include "../../include/corewar.h"

int32_t reconstruct_int(uint8_t *memory, int index, int num_bytes)
{
    uint32_t result = 0;
    int shift = (num_bytes - 1) * 8;

    for (int i = 0; i < num_bytes; i++) {
        result |= (uint32_t)memory[(index + i) % MEM_SIZE] << shift;
        shift -= 8;
    }
    if (result & (1 << ((num_bytes * 8) - 1)))
        result |= ~((1 << (num_bytes * 8)) - 1);
    return (int32_t)result;
}
