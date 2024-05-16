/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** parsing.h
*/



#ifndef PARSING
    #define PARSING
    #include "corewar.h"

int parsing(champion_t **champion, corewar_t *corewar);
void find_good_prog_size(champion_t *champion);
int verif_magic_number(champion_t *champion);
int find_header(champion_t *champion, int fd);
int recup_instrucions(int fd, champion_t *champion, u_int8_t *memory);
int verif_open(champion_t *champion, u_int8_t *memory);

#endif /* PARSING */
