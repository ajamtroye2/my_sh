/*
** EPITECH PROJECT, 2024
** cd
** File description:
** cd command
*/

#include "my.h"

char **freee(char **arg)
{
    for (int i = 0; arg[i] != NULL; i++)
        free(arg[i]);
    return arg;
}

static int iscd(char **arg)
{
    if (arg[0][0] != 'c' || arg[0][1] != 'd' || arg[0][2] != '\0') {
        return 0;
    }
    return 84;
}

static int pwdcd(char *env, env_t *envinfo)
{
    chdir(env);
    envinfo->env = add_totab(envinfo->env, my_envdup(env, "PWD="));
    return 84;
}

int my_cd(char **arg, env_t *envinfo)
{
    size_t i = 0;
    char path[1000];

    if (iscd(arg) == 0)
        return 0;
    for (i = 0; arg[i] != NULL; i++);
    if (i == 1)
        return pwdcd(getpwd(my_getenv(envinfo->env, "HOME")), envinfo);
    if (i > 2)
        return my_puteror("bash: cd: too many arguments\n");
    if (chdir(arg[1]) == -1) {
        my_puteror(arg[1]);
        return my_puteror(": Not a directory.\n");
    }
    getcwd(path, 1000);
    return pwdcd(path, envinfo);
}
