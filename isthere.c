/*
** EPITECH PROJECT, 2024
** isthere.c
** File description:
** is a char in the string
*/

#include "my.h"

static int ift(char a, char b)
{
    if (a == b)
        return 1;
    return 0;
}

int isthere(char *str, char *alpha)
{
    int i = 0;
    int worng = 0;

    for (; str[i] != '\0'; i++)
        for (int y = 0; alpha[y] != '\0'; y++)
            worng += ift(str[i], alpha[y]);
    if (worng == my_strlen(str) || worng == my_strlen(alpha))
        return 0;
    return 1;
}

int cacaserreur(char *arg)
{
    int a = 0;
    char *alpah =
    "abcdefghijklmnopqrstuvwxyz._123456789AZERTYUIOPQSDFGHJKLMWXCVBN";
    char *alpha =
    "abcdefghijklmnopqrstuvwxyz_AZERTYUIOPQSDFGHJKLMWXCVBN";

    for (int i = 0; alpha[i] != '\0'; i++)
        if (alpha[i] == arg[0])
            a++;
    if (!a) {
        my_puteror("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (isthere(arg, alpah)) {
        my_puteror("setenv: Variable name must contain alphanumeric ");
        my_puteror("characters.\n");
        return 1;
    }
    return 0;
}
