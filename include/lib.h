/*
** EPITECH PROJECT, 2024
** INCLUDE
** File description:
** include
*/

#ifndef PROTOTYPE_TEST
    #define PROTOTYPE_TEST

int my_put_nbr(long int nb);
int my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
long my_getnbr(char const *str);
int my_getnbr_doop(char *str);
int nbre(int i, int nombre, char const *str);
char **my_str_to_word_array(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char **divise_table(char *word, char separator);
char *my_strdup(char const *src);
int my_puterror(char c);
int my_putstrerror(char *str);
char **copy_string_array(char **source);

#endif /* PROTOTYPE_TEST */
