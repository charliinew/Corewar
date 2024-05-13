/*
** EPITECH PROJECT, 2024
** MY_PUTSTRERROR
** File description:
** strerror
*/

#include "../include/include.h"
#include <unistd.h>

int my_putstrerror(char *str)
{
    int n = 0;

    while (str[n] != '\0') {
        my_puterror(str[n]);
        n += 1;
    }
}
