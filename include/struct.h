/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Shell Boostrap
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    typedef struct env_s {
    char **env;
    char *home;
}env_t;

    typedef struct tree {
    char *arg;
    struct tree *next;
}tree_t;
#endif /* STRUCT_H */
