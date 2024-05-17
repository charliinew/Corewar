/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** find_header.c
*/

#include "../../include/corewar.h"

int find_header(champion_t *champion, int fd)
{
    if (champion->header == NULL) {
        champion->header = (header_t *)malloc(sizeof(header_t));
        if (champion->header == NULL) {
            close(fd);
            return 84;
        }
    }
    if (read(fd, champion->header, sizeof(header_t)) == -1) {
        close(fd);
        free(champion->header);
        return 84;
    }
    return 0;
}
