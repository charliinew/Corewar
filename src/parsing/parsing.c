/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** parsing.c
*/

#include "../../include/corewar.h"


static int recup_instrucions(int fd, champion_t *champion, u_int8_t *memory)
{
    static int pos = 0;
    printf("%d\n", champion->header->prog_size);
    unsigned char *body = malloc(sizeof(char) *
            champion->header->prog_size);
    read(fd, body, champion->header->prog_size);
    body[champion->header->prog_size - 1] = '\0';
    add_to_memory(memory, body, champion);
    free(body);
    pos ++;
}

static int verif_open(champion_t *champion, u_int8_t *memory)
{
    int fd;

    fd = open(champion->flags->prog_name, O_RDONLY);
    if (fd == -1)
        return 84;
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
    champion->header->prog_size = ((champion->header->prog_size >> 24) & 0xFF) |
                       ((champion->header->prog_size << 8) & 0xFF0000) |
                       ((champion->header->prog_size >> 8) & 0xFF00) |
                       ((champion->header->prog_size << 24) & 0xFF000000);
    recup_instrucions(fd, champion, memory);
    close(fd);
    return 0;
}

int parsing(corewar_t *corewar, u_int8_t *memory)
{
    for (int i = 0; i < corewar->nb_champion; i++) {
        if (verif_open(corewar->champion[i], memory) == 84)
            return 84;
    }
    return 0;
}
