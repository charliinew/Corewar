/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** recup_instructions.c
*/

#include "../../include/corewar.h"

int recup_instrucions(int fd, champion_t *champion, u_int8_t *memory)
{
    static int pos = 0;
    unsigned char *body = malloc(sizeof(char) *
        champion->header->prog_size);

    if (read(fd, body, champion->header->prog_size) == -1)
        return 84;
    add_to_memory(memory, body, champion);
    free(body);
    pos ++;
    return 0;
}
