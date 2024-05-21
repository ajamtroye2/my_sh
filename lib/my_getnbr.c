/*
** EPITECH PROJECT, 2023
** lollol
** File description:
** take a number from string
*/

#include <stdio.h>
#include "my.h"

int calcul_negative(char const *str, int max, int negative)
{
    int i;

    for (i = 0; i < max; i++){
        if (str[i] == '-'){
            negative = -negative;
        }
    }
    return negative;
}

int calcul_number(char const *str, int number, int i)
{
    if (str[i] >= 48 && str[i] <= 58){
        number = number * 10;
        number = number + str[i] - '0';
    }
    return number;
}

int my_getnbr(char const *str)
{
    int number = 0;
    int i;
    int negative = 1;
    int max = 0;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] >= '0' && str[i] <= '9'){
            number = calcul_number(str, number, i);
            max = i;
        }
    }
    negative = calcul_negative(str, max, negative);
    return (number * negative);
}
