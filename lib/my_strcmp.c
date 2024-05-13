/*
** EPITECH PROJECT, 2023
** MY_STRMP
** File description:
** differnce ascii between 2 letters
*/

int my_strcmp(char const *s1, char const *s2)
{
    int compteur = 0;
    int resultat;

    while (s1[compteur] == s2[compteur]) {
        compteur += 1;
        if (s1[compteur] == '\0' && s2[compteur] == '\0') {
            return 0;
        }
    }
    return 1;
}
