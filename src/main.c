/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** main.c
*/

#include "../include/src.h"

int main(int ac, char **av)
{
    header_t *tab_robot[4];

    if (parsing(av, tab_robot) == 84)
        return 84;
    return 0;
}
