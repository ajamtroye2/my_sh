/*
** EPITECH PROJECT, 2024
** test str
** File description:
** testing str
*/

#include "my.h"

char *getpwd(char *todup)
{
    int i;
    char *str;
    int len = my_strlen(todup);

    for (i = len; todup[i] != '='; i--);
    i++;
    str = malloc(sizeof(char *) * (len - i + 1));
    for (int y = 0; todup[y + i] != '\0'; y++) {
        str[y] = todup[y + i];
    }
    str[len - i] = '\0';
    return (str);
}
