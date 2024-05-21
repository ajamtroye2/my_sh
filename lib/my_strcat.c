/*
** EPITECH PROJECT, 2024
** lol
** File description:
** idk
*/

#include "my.h"

char *str_cat(char *str1, char *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *str3 = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++) {
        if (i < my_strlen(str1))
            str3[i] = str1[i];
        else
            str3[i] = str2[i - my_strlen(str1)];
    }
    my_putstr(str3);
    my_putstr("\n");
    return str3;
}
