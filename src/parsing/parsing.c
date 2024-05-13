/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** parsing.c
*/

#include "../../include/src.h"

static int verif_open(char *av, header_t **tab_robot, int i)
{
    int fd;

    fd = open(av, O_RDONLY);
    if (fd == -1)
        return 84;
    if (tab_robot[i] == NULL) {
        tab_robot[i] = (header_t *)malloc(sizeof(header_t));
        if (tab_robot[i] == NULL) {
            close(fd);
            return 84;
        }
    }
    if (read(fd, tab_robot[i], sizeof(header_t)) != sizeof(header_t)) {
        close(fd);
        free(tab_robot[i]);
        return 84;
    }
    close(fd);
    printf("je suis %s\n", tab_robot[i]->prog_name);
    return 0;
}

int parsing(char **av, header_t **tab_robot)
{
    int nb_tab = 0;

    for (int i = 1; av[i] != NULL; i++) {
        printf("%s\n", av[i]);
        if (verif_open(av[i], tab_robot, nb_tab) == 84)
            return 84;
        nb_tab ++;
    }
}
