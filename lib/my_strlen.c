/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** counts and returns the number of characters found
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

int tablen(char const **str)
{
    int i = 0;

    for (i = 0; str[i] != NULL; i++);
    return i;
}
