/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** put_nbr
*/

#include "../include/lib.h"

int my_put_nbr(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return 0;
}
