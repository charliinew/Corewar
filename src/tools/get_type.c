/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** get_type.c
*/

#include "../../include/corewar.h"

int get_type(char *cdb, int idx)
{
    int i = (idx - 1) * 2;

    if (cdb[i] == '0' && cdb[i + 1] == '1')
        return 1;
    if (cdb[i] == '1' && cdb[i + 1] == '0')
        return DIR_SIZE;
    if (cdb[i] == '1' && cdb[i + 1] == '1')
        return IND_SIZE;
    return 0;
}
