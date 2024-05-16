/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** write_into_memory.c
*/

#include "../../include/corewar.h"

void write_into_memory(uint8_t *memory, int index, int32_t value)
{
    memory[index % MEM_SIZE] = (value >> 24) & 0xFF;
    memory[(index + 1) % MEM_SIZE] = (value >> 16) & 0xFF;
    memory[(index + 2) % MEM_SIZE] = (value >> 8) & 0xFF;
    memory[(index + 3) % MEM_SIZE] = value & 0xFF;
}
