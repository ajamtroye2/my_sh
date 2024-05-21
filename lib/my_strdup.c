/*
** EPITECH PROJECT, 2024
** str dup
** File description:
** dup str
*/

#include "my.h"

char *my_strdup(char *todup)
{
    char *str;
    int len = my_strlen(todup);

    str = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; todup[i] != '\0'; i++)
        str[i] = todup[i];
    str[len] = '\0';
    return (str);
}

char *my_linedup(char *todup, char *path)
{
    int i = 0;
    int y = 0;
    char *str;
    int len = my_strlen(todup);
    int lenstr = len + my_strlen(path);

    str = malloc(sizeof(char *) * (lenstr + 2));
    for (int x = 0; path[x] != '\0'; x++)
        str[x] = path[x];
    str[my_strlen(path)] = '/';
    while (todup[y] == ' ' || todup[y] == '\t')
        y++;
    for (; todup[y] != '\0'; y++) {
        str[i + my_strlen(path) + 1] = todup[y];
        i++;
    }
    str[i + my_strlen(path) + 1] = '\0';
    return (str);
}

char **my_tabdup(char **tab, char *ligne)
{
    char **ret = malloc(sizeof(char *) * (tablen(tab) + 2));

    for (int i = 0; tab[i] != NULL; i++)
        ret[i] = my_strdup(tab[i]);
    if (ligne != NULL) {
        ret[tablen(tab)] = my_strdup(ligne);
        ret[tablen(tab) + 1] = NULL;
    } else
        ret[tablen(tab)] = NULL;
    return ret;
}

char *my_envdup(char *todup, char *paths)
{
    char *str = NULL;
    char *path = my_strdup(paths);
    int len = my_strlen(todup);
    int lenstr = len + my_strlen(path);

    str = malloc(sizeof(char *) * (lenstr + 2));
    for (int i = 0; path[i] != '\0'; i++)
        str[i] = path[i];
    for (int i = 0; todup[i] != '\0'; i++)
        str[i + my_strlen(path)] = todup[i];
    str[lenstr] = '\0';
    return (str);
}
