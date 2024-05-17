/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** copy_champ.c
*/

#include "../../include/corewar.h"

header_t *copy_header(header_t *header)
{
    header_t *new_header = malloc(sizeof(header_t));
    int i;

    new_header->magic = header->magic;
    for (i = 0; header->prog_name[i] != '\0'; i++)
        new_header->prog_name[i] = header->prog_name[i];
    new_header->prog_name[i] = '\0';
    for (i = 0; header->comment[i] != '\0'; i++)
        new_header->comment[i] = header->comment[i];
    new_header->comment[i] = '\0';
    new_header->prog_size = header->prog_size;
    return new_header;
}

flags_t *copy_flags(flags_t *flags)
{
    flags_t *new_flags = malloc(sizeof(flags_t));

    new_flags->prog_name = my_strdup(flags->prog_name);
    new_flags->n = flags->n;
    new_flags->a = flags->a;
    return new_flags;
}
