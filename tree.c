/*
** EPITECH PROJECT, 2024
** tree.c
** File description:
** initialise the treee
*/

#include "my.h"

int countcoma(char *args)
{
    int y = 0;

    for (int i = 0; args[i] != '\0'; i++)
        if (args[i] == ';')
            y++;
    return y;
}

tree_t *init_branche(char *str)
{
    struct tree *ret = malloc(sizeof(tree_t));

    ret->next = NULL;
    ret->arg = str;
    return ret;
}

tree_t **init_tree(char *args)
{
    char **argsi = str_to_choisie(args, ";\n");
    int nbr = tablen(argsi);
    struct tree **ret = malloc(sizeof(tree_t) * (nbr + 1));

    for (int i = 0; i < nbr; i++)
        ret[i] = init_branche(argsi[i]);
    ret[nbr] = NULL;
    return ret;
}
