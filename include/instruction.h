/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** instruction.h
*/

#ifndef INSTRUCTION_H_
    #define INSTRUCTION_H_

typedef struct corewar_s corewar_t;
typedef struct champion_s champion_t;

void my_live(corewar_t *corewar, champion_t *champion);
void my_ld(corewar_t *corewar, champion_t *champion);
void my_st(corewar_t *corewar, champion_t *champion);
void my_add(corewar_t *corewar, champion_t *champion);
void my_sub(corewar_t *corewar, champion_t *champion);
void my_and(corewar_t *corewar, champion_t *champion);
void my_or(corewar_t *corewar, champion_t *champion);
void my_xor(corewar_t *corewar, champion_t *champion);
void my_zjmp(corewar_t *corewar, champion_t *champion);
void my_ldi(corewar_t *corewar, champion_t *champion);
void my_sti(corewar_t *corewar, champion_t *champion);
void my_fork(corewar_t *corewar, champion_t *champion);
void my_lld(corewar_t *corewar, champion_t *champion);
void my_lldi(corewar_t *corewar, champion_t *champion);
void my_lfork(corewar_t *corewar, champion_t *champion);
void my_aff(corewar_t *corewar, champion_t *champion);

#endif // INSTRUCTION_H_