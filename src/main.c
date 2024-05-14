/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** main.c
*/

#include "../include/src.h"

static int print_h(void)
{
    my_putstr("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] [-a "
        "load_address] prog_name] ...\nDESCRIPTION\n-dump nbr_cycle "
        "dumps the memory after the nbr_cycle execution (if the round "
        "isn't\nalready over) with the following format: 32 bytes/line "
        "in hexadecimal (A0BCDEFE1DD3...)\n-n prog_number sets the next"
        " program's number. By default, the first free number in the\n"
        "parameter order\n-a load_adress sets the next program's "
        "loading address. When no address is specifided,\noptimize the "
        "adresses so that the processes are as far away from each other"
        " as\npossible"
        ". The addresses are MEM_SIZE modulo.\n");
    return 0;
}

int main(int ac, char **av)
{
    header_t *tab_robot[4];
    u_int8_t *memory = init_memory();

    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0)
            return print_h();
        return 84;
    }
    if (parsing(av, tab_robot) == 84)
        return 84;
    display_memory(memory, MEM_SIZE);
    return 0;
}
