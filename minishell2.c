/*
** EPITECH PROJECT, 2024
** minishell.c
** File description:
** try to make clean
*/

#include "my.h"

int nbrofarguments(char *str)
{
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|' || str[i] == ';')
            y++;
        if (str[i] == '<' && str[i + 1] != '<')
            y++;
        if (str[i] == '>' && str[i + 1] != '>')
            y++;
    }
    return y;
}

static int spacec(char *str)
{
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '|' || str[i] == ';') &&
            str[i + 1] != ' ' && str[i - 1] != ' ')
            y++;
        if (str[i] == '<' && str[i + 1] != '<' &&
            str[i + 1] != ' ' && str[i - 1] != ' ')
            y++;
        if (str[i] == '>' && str[i + 1] != '>' &&
            str[i + 1] != ' ' && str[i - 1] != ' ')
            y++;
    }
    return y;
}

char *separate(char *todup)
{
    int x = 0;
    char *str;
    int len = my_strlen(todup) + spacec(str);

    str = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; todup[i] != '\0'; i++) {
        if (todup[i] != ' ' && todup[i + 1] == separator())
        str[i] = todup[i];
    }
    str[len] = '\0';
    return (str);
}
