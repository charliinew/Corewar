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
    int max_ctd;
    int actual_ctd;
    int total_cycle;
    int nb_live;
    champion_t *champion[4];
    u_int8_t *memory;
} corewar_t;

int parsing(corewar_t *corewar);
corewar_t *init_corewar_struct(void);

void display_memory(u_int8_t *memoire, int taille);
u_int8_t *init_memory(void);
#endif /* COREWAR */
