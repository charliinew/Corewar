/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_coding_byte.c
*/

#include "../../include/corewar.h"

static int check_part_cdb(char cdb_1, char cdb_2, args_type_t type)
{
    if (cdb_1 == '0' && cdb_2 == '1' && !(type & T_REG))
        return 84;
    if (cdb_1 == '1' && cdb_2 == '0' && !(type & T_DIR))
        return 84;
    if (cdb_1 == '1' && cdb_2 == '1' && !(type & T_IND))
        return 84;
    return 0;
}

static int check_no_param_cdb(char cdb_1, char cdb_2)
{
    if (cdb_1 != '0' || cdb_2 != '0')
        return 84;
    return 0;
}

int check_coding_byte(char *cdb, int index)
{
    int i;

    for (i = 0; i < op_tab[index].nbr_args; i++) {
        if (check_part_cdb(cdb[i + i], cdb[i + i + 1],
            op_tab[index].type[i]) == 84)
            return 84;
    }
    for (; i < 4; i++) {
        if (check_no_param_cdb(cdb[i + i], cdb[i + i + 1]) == 84)
            return 84;
    }
    return 0;
}
