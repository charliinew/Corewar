/*
** EPITECH PROJECT, 2023
** MY_STR_TO_WORD_ARRAY
** File description:
** koijhugytfrd
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/lib.h"

int verif_espace(int e, char const *ytg)
{
    while ((ytg[e] < 48) || (ytg[e] > 57 && ytg[e] < 65) ||
        (ytg[e] > 90 && ytg[e] < 97) || (ytg[e] > 122)) {
        if (ytg[e] != '\0') {
            e++;
        } else {
            return e;
        }
    }
    return e;
}

int avance(int h, char const *pol)
{
    while (pol[h] < 48 || pol[h] > 57 && pol[h] < 65 ||
        pol[h] > 90 && pol[h] < 97 || pol[h] > 122) {
        if (pol[h] == '\0') {
            return h;
        }
        h++;
    }
    return h;
}

int compte_nb_mot(char const *lon)
{
    int w = 0;
    int nb = 0;

    w = avance(w, lon);
    while (lon[w] != '\0') {
        if ((lon[w] < 48) || (lon[w] > 57 && lon[w] < 65) ||
            (lon[w] > 90 && lon[w] < 97) || (lon[w] > 122)) {
            w = verif_espace(w, lon);
            nb ++;
        } else {
            w ++;
        }
    }
    w = w- 1;
    if ((lon[w] < 48) || (lon[w] > 57 && lon[w] < 65) ||
        (lon[w] > 90 && lon[w] < 97) || (lon[w] > 122)) {
        return nb;
    } else {
        return nb + 1;
    }
}

char **div_tableau(int q, char const *gpt, char **zer)
{
    int i = 0;
    int a = 0;

    while (gpt[q] != '\0') {
        if ((gpt[q] >= 'A' && gpt[q] <= 'Z') || (gpt[q] >= 'a' &&
            gpt[q] <= 'z') || (gpt[q] >= 48 && gpt[q] <= 57)) {
            zer[i][a] = gpt[q];
            a ++;
            q++;
        } else {
            q = verif_espace(q, gpt);
            zer[i][a] = '\0';
            a = 0;
            i ++;
        }
    }
    if (a != 0) {
        zer[i][a] = '\0';
    }
    return zer;
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int c = 0;

    tab = malloc((compte_nb_mot(str)+ 1) * sizeof(char *));
    for (int u = 0; u < compte_nb_mot(str); u++) {
            tab[u] = malloc(my_strlen(str) - 1);
    }
    tab[compte_nb_mot(str)] = NULL;
    c = avance(c, str);
    if (compte_nb_mot(str) != 0) {
        tab = div_tableau(c, str, tab);
    }
    return tab;
}
