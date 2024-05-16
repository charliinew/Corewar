/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** memory.c
*/

#include "../../include/corewar.h"

void uint8_to_hex(char value, char *hex_buffer)
{
    const char hex_digits[] = "0123456789ABCDEF";

    hex_buffer[0] = hex_digits[(value >> 4) & 0xF];
    hex_buffer[1] = hex_digits[value & 0xF];
    hex_buffer[2] = '\0';
}

static void display_return_line(int i)
{
    if (i % 32 == 0) {
        if (i != 0) {
            my_putchar('\n');
        }
        return;
    }
    my_putchar(' ');
}

void display_memory(char *memoire, int taille)
{
    char hex_buffer[3];

    for (int i = 0; i < taille; i++) {
        display_return_line(i);
        uint8_to_hex(memoire[i], hex_buffer);
        my_putstr(hex_buffer);
    }
    my_putchar('\n');
}

char *init_memory(void)
{
    char *memory = malloc(MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
    return memory;
}
