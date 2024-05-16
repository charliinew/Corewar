/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** open_file.c
*/

#include "../../include/corewar.h"

int verif_open(champion_t *champion, u_int8_t *memory)
{
    int fd;

    fd = open(champion->flags->prog_name, O_RDONLY);
    if (fd == -1)
        return 84;
    if (find_header(champion, fd) == 84)
        return 84;
    if (verif_magic_number(champion) == 84)
        return 84;
    find_good_prog_size(champion);
    recup_instrucions(fd, champion, memory);
    close(fd);
    return 0;
}

