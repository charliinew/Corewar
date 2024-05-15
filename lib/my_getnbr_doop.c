/*
** EPITECH PROJECT, 2023
** getbrn
** File description:
** getnbr
*/

int nbre(int i, int nombre, char const *str)
{
    nombre = nombre * 10 + (str[i] - 48);
    return (nombre);
}

int my_getnbr_doop(char *str)
{
    int i = 0;
    int nombre = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return (-1);
        }
        if (str[i] >= '0' && str[i] <= '9')
            nombre = nbre(i, nombre, str);
        i++;
    }
    return (nombre);
}
