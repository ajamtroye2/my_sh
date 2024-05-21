/*
** EPITECH PROJECT, 2024
** env
** File description:
** set en un env
*/

#include "my.h"

int envstr(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '=' && str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return 1;
    return 0;
}

char *my_getenv(char **env, char *str)
{
    for (int i = 0; env[i] != NULL; i++)
        if (envstr(env[i], str) == 0)
            return env[i];
    return NULL;
}

int my_setenv(env_t *envinfo, char **arg)
{
    char *toadd;

    if (teststr(arg[0], "setenv") == 0)
        return 1;
    if (tablen(arg) == 1) {
        my_env(envinfo->env, "env");
        return 0;
    }
    if (tablen(arg) > 3) {
        my_puteror("setenv: Too many arguments.\n");
        return 0;
    }
    if (cacaserreur(arg[1]) != 0)
        return 0;
    toadd = my_envdup("=", arg[1]);
    if (tablen(arg) == 3)
        toadd = my_envdup(arg[2], toadd);
    envinfo->env = add_totab(envinfo->env, toadd);
    return 0;
}

static char **rmtotab(char **env, char *torm)
{
    int i = 0;
    int y = 0;
    char **ret = malloc(sizeof(char *) * (tablen(env) + 1));

    for (i = 0; env[i] != NULL; i++)
        if (envstr(env[i], torm) == 1) {
            ret[y] = env[i];
            y++;
        }
    if (i == y)
        ret[tablen(env)] = NULL;
    else {
        for (int c = 0; c < (i - y); c++)
            free(ret[tablen(env) - c]);
        ret[tablen(env) - (i - y)] = NULL;
    }
    return ret;
}

int my_unsetenv(env_t *envinfo, char **arg)
{
    char **env = envinfo->env;
    char *torm;

    if (teststr(arg[0], "unsetenv") == 0)
        return 1;
    if (tablen(arg) < 2) {
        my_puteror("setenv: Too few arguments.\n");
        return 0;
    }
    if (arg[1][0] == '*' && arg[1][1] == '\0') {
        envinfo->env = NULL;
        return 0;
    }
    for (int i = 1; arg[i] != NULL; i++) {
        torm = my_envdup("=", arg[i]);
        env = rmtotab(env, torm);
        free(torm);
    }
    envinfo->env = env;
    return 0;
}
