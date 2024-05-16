/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** get_type.c
*/

#include "../../include/corewar.h"

int get_type(char *cdb, int idx)
{
    if (cdb[idx + idx] == '0' && cdb[idx + 1] == '1')
        return 1;
    if (cdb[idx + idx] == '1' && cdb[idx + 1] == '0')
        return DIR_SIZE;
    if (cdb[idx + idx] == '1' && cdb[idx + 1] == '1')
        return IND_SIZE;
    return 0;
}
