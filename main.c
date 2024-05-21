/*
** EPITECH PROJECT, 2024
** mainc
** File description:
** main function
*/

#include "my.h"

int main(int ac, char **, char **env)
{
    env_t envinfo;
    int x = 0;

    if (ac != 1)
        return 84;
    envinfo.env = env;
    envinfo.home = my_getenv(env, "HOME");
    while (x == 0) {
        my_putstr("$> ");
        x = shell(&envinfo);
    }
    if (x == 1) {
        free(envinfo.home);
        envinfo.env = freee(envinfo.env);
        free(envinfo.env);
    }
    return x;
}
