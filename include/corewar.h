/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** src.h
*/


#ifndef COREWAR
    #define COREWAR

    #include "lib.h"
    #include "stdio.h"
    #include <string.h>
    #include "op.h"
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "stdlib.h"
    #include "champions.h"

typedef struct corewar_s {
    int dump;
    int nb_champion;
    champion_t *champion[4];
} corewar_t;

void set_position(corewar_t *corewar);

int parsing(corewar_t *corewar, u_int8_t *memory);
corewar_t *init_corewar_struct(void);

void display_memory(u_int8_t *memoire, int taille);
void add_to_memory(u_int8_t *memory, champion_t *champion);
u_int8_t *init_memory(void);
void uint8_to_hex(u_int8_t value, char *hex_buffer);
#endif /* COREWAR */
