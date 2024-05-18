/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** champions.h
*/

#ifndef CHAMPIONS_H
    #define CHAMPIONS_H

    #include "corewar.h"

typedef struct header_s header_t;

typedef struct corewar_s corewar_t;

typedef struct flags_s {
    char *prog_name;
    int n;
    int a;
} flags_t;

typedef struct champion_s {
    int id;
    int cycle_instruction;
    int live;
    bool last_live;
    int PC;
    int carry;
    header_t *header;
    flags_t *flags;
    int reg[16];
    struct champion_s *next;
    struct champion_s **child
} champion_t;

int fetch_flags(char **av, corewar_t *corewar);
int set_dump(char **av, int *pos, int *dump);
int set_prog_number(char **av, int *pos, champion_t *champion);
void set_n_flags(champion_t **champion);
int set_load_address(char **av, int *pos, champion_t *champion);
int set_prog_name(char **av, int pos, champion_t *champion);
champion_t *set_champion(void);
int check_champion(corewar_t *corewar);
void set_champion_next(corewar_t *corewar);

#endif /* !CHAMPIONS_H */
