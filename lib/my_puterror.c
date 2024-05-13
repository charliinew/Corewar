/*
** EPITECH PROJECT, 2024
** MY_PUTERROR
** File description:
** my_puterror
*/

#include <unistd.h>

int my_puterror(char c)
{
    write(2, &c, 1);
}
