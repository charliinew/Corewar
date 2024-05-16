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
    #include "instruction.h"
    #include <stdint.h>

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

static void (*instr_tab[16])(corewar_t *, champion_t *) = {&my_live,
    &my_ld, &my_st, &my_add, &my_sub, &my_and, &my_or,
    &my_xor, &my_zjmp, &my_ldi, &my_sti, &my_fork,
    &my_lld, &my_lldi, &my_lfork, &my_aff};

void set_position(corewar_t *corewar);
int parsing(corewar_t *corewar, u_int8_t *memory);
corewar_t *init_corewar_struct(void);

void display_memory(u_int8_t *memoire, int taille);
void add_to_memory(u_int8_t *memory, unsigned char *champ, champion_t
    *champion);
u_int8_t *init_memory(void);
int32_t reconstruct_int(uint8_t *memory, int index, int num_bytes);
void launch_corewar(corewar_t *corewar);
void purshase_execution(corewar_t *corewar, champion_t *champion);

void uint8_to_hex(u_int8_t value, char *hex_buffer);
void free_struct(corewar_t *corewar, u_int8_t *memory);

char *int_to_bin(int nb);
#endif /* COREWAR */
