/*
** EPITECH PROJECT, 2024
** str to array
** File description:
** str to array
*/

#include "my.h"

static int nbrofwords(char *str)
{
    char *count = my_strdup(str);
    int res = 0;

    count = strtok(count, " \n\t");
    res++;
    while (count != NULL) {
        res++;
        count = strtok(NULL, " \n\t");
    }
    free(count);
    return res;
}

char **str_to_array(char *str)
{
    int len = nbrofwords(str);
    char *strd = my_strdup(str);
    char **tabl = malloc(sizeof(char *) * (len + 1));
    int x = 0;

    strd = strtok(strd, " \t\n");
    while (strd != NULL) {
        tabl[x] = my_strdup(strd);
        x++;
        strd = strtok(NULL, " \n\t");
    }
    tabl[x] = NULL;
    free(strd);
    return tabl;
}

char **path_to_array(char *str)
{
    int len = nbrofwords(str);
    char **tabl = malloc(sizeof(char *) * (len + 1));
    int x = 0;

    str = strtok(str, "PATH= ");
    tabl[x] = my_strdup(str);
    x++;
    str = strtok(str, ": ");
    while (str != NULL) {
        tabl[x] = my_strdup(str);
        x++;
        str = strtok(NULL, ": ");
    }
    tabl[x] = NULL;
    return tabl;
}

char **add_totab(char **tab, char *str)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (envstr(tab[i], str) == 0) {
            tab[i] = my_strdup(str);
            return tab;
        }
    }
    return my_tabdup(tab, str);
}

char **str_to_choisie(char *str, char *sep)
{
    int len = nbrofwords(str);
    char *strd = my_strdup(str);
    char **tabl = malloc(sizeof(char *) * (len + 1));
    int x = 0;

    strd = strtok(strd, sep);
    while (strd != NULL) {
        tabl[x] = my_strdup(strd);
        x++;
        strd = strtok(NULL, sep);
    }
    tabl[x] = NULL;
    free(strd);
    return tabl;
}
