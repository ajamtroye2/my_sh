/*
** EPITECH PROJECT, 2023
** MY.H
** File description:
** my.h
*/

#include <string.h>
#include <fcntl.h>
#include "struct.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef MY_H
    #define MY_H

void my_putchar(char c);
int my_put_nbr(long long nb);
int my_putstr(char const *str);
int my_puteror(char const *str);
int my_strlen(char const *str);
int tablen(char **str);
char *my_strdup(char *todup);
char *my_strdups(char *todup);
int my_getnbr(char const *str);
char **str_to_array(char *str);
int teststr(char *str1, char *str2);
char **my_tabdup(char **tab, char *ligne);
char *my_envdup(char *todup, char *path);
char **add_totab(char **tab, char *str);
char *str_cat(char *str1, char *str2);
char **path_to_array(char *str);
char *my_linedup(char *todup, char *path);
char *getpwd(char *todup);
char *my_getenv(char **env, char *str);
int my_env(char **env, char *arg);
int cacaserreur(char *arg);
int my_setenv(env_t *envinfo, char **arg);
int my_unsetenv(env_t *env, char **arg);
int envstr(char *str1, char *str2);
int my_cd(char **arg, env_t *envinfo);
char **freee(char **arg);
int shell(env_t *envinfo);
int isthere(char *str, char *alpha);
tree_t **init_tree(char *args);
char **str_to_choisie(char *str, char *sep);
int my_exec(char **arg, env_t *envinfo, int *pipefd);
#endif /* MY_H */
