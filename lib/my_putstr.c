/*
** EPITECH PROJECT, 2023
** myputstr
** File description:
** displays, one-by-one, the characters of a string.
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return my_strlen(str);
}

int my_puteror(char const *str)
{
    write(2, str, my_strlen(str));
    return 84;
}
