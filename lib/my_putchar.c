/*
** EPITECH PROJECT, 2023
** Day 3
** File description:
** c file
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
