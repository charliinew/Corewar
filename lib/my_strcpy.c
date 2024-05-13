/*
** EPITECH PROJECT, 2023
** MY_STRCPY
** File description:
** return copy string
*/


char *my_strcpy(char *dest, char const *src)
{
    int b = 0;

    while (src[b] != '\0') {
        dest[b] = src[b];
        b ++;
    }
    dest[b] = '\0';
    return dest;
}
