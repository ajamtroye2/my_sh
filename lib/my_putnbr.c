/*
** EPITECH PROJECT, 2023
** lollol
** File description:
** c moi qi ai fai
*/

#include "my.h"

int my_put_nbr(long long nb)
{
    int i = 0;

    if (nb >= 10){
        i += my_put_nbr(nb / 10);
    }
    if (nb < 0){
        nb = -nb;
        my_putchar('-');
        i++;
        i += my_put_nbr(nb);
    } else {
        my_putchar((nb % 10) + 48);
        i++;
    }
    my_putchar('\n');
    return i;
}
