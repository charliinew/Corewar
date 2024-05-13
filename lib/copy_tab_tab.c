/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell2-luca.dekyndt
** File description:
** copy_tab_tab.c
*/

#include "../include/lib.h"

#include <stddef.h>
#include <stdlib.h>

char **copy_string_array(char **source)
{
    int size = 0;
    char **destination;

    while (source[size] != NULL)
        size++;
    destination = (char **)malloc((size + 1) * sizeof(char *));
    for (int i = 0; i < size; i++) {
        destination[i] = (char *)malloc((my_strlen(source[i]) + 1) * sizeof
                (char));
        my_strcpy(destination[i], source[i]);
    }
    destination[size] = NULL;
    return destination;
}
