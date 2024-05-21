/*
** EPITECH PROJECT, 2024
** test str
** File description:
** testing str
*/

#include "my.h"

int teststr(char *str1, char *str2)
{
    int res = 0;

    if (str1 == NULL)
        return 2;
    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] == str2[i])
            res++;
    if (res == my_strlen(str1) && res == my_strlen(str2))
        return 1;
    return 0;
}
