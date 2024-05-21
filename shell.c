/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** main function
*/

#include "my.h"

int my_env(char **env, char *arg)
{
    if (teststr(arg, "env") == 0)
        return -1;
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return 0;
}

static char **pathhand(char **env)
{
    char **paths = NULL;

    if (teststr(my_getenv(env, "PATH="), "PATH=") == 1) {
        paths = malloc(sizeof(char *));
        paths[0] = NULL;
    } else if (my_getenv(env, "PATH=") == NULL) {
        paths = malloc(sizeof(char *) * 2);
        paths[0] = "/bin";
        paths[1] = NULL;
    } else
        paths = path_to_array(my_getenv(env, "PATH"));
    return paths;
}

static void childf(char **arg, char *line, char **env, int *pipefd)
{
    char *new = NULL;
    char **paths = NULL;

    close(pipefd[0]);
    execve(arg[0], arg, env);
    paths = pathhand(env);
    for (int i = 0; paths[i] != NULL; i++) {
        new = my_linedup(line, paths[i]);
        execve(new, arg, env);
        free(new);
    }
    my_puteror(arg[0]);
    arg = freee(arg);
    free(arg);
    free(paths);
    return;
}

void restatus(int status)
{
    if (status == 139)
        my_puteror("Segmentation fault\n");
    if (status == 256)
        my_puteror(": Command not found.\n");
    return;
}

int my_exec(char **arg, env_t *envinfo, int *pipefd)
{
    int save = dup(1);
    int status = 0;
    pid_t childPID = fork();
    char *line = arg[0];

    if (childPID == -1)
        exit(EXIT_FAILURE);
    if (childPID == 0) {
        childf(arg, line, envinfo->env, pipefd);
        dup2(save, STDOUT_FILENO);
        close(pipefd[1]);
        exit(EXIT_FAILURE);
    } else
        wait(&status);
    restatus(status);
    return status;
}

int execution(env_t *envinfo, char *line)
{
    char **argi = str_to_choisie(line, "|><");
    char **arg = str_to_array(argi[0]);
    int pipefd[2];

    pipe(pipefd);
    if (my_setenv(envinfo, arg) == 0 || my_unsetenv(envinfo, arg) == 0)
        return 0;
    if (my_cd(arg, envinfo) != 0 || my_env(envinfo->env, arg[0]) == 0)
        return 0;
    my_exec(arg, envinfo, pipefd);
    free(line);
    return 0;
}

static int isred(char pre)
{
    if ((pre == ' ' || pre == '\t') && pre != '\n')
        return 1;
    if ((pre == '<' || pre == '>' || pre == '|') && pre != '\n')
        return 1;
    return 0;
}

static int noinput(char *str)
{
    int i = 0;

    for (; isred(str[i]); i++);
    if (str[i - 1] == '|' && str[i] == '\n') {
        my_puteror("Invalid null command.\n");
        free(str);
        return 0;
    }
    if (str[i - 1] == '>' || str[i - 1] == '<')
        if (str[i] == '\n') {
            my_puteror("Missing name for redirect.\n");
            free(str);
            return 0;
        }
    if (str[i] == '\n') {
        free(str);
        return 0;
    }
    return 1;
}

static void controlc(void)
{
    my_putstr("\n$> ");
}

int shell(env_t *envinfo)
{
    int ret = 0;
    char *line = NULL;
    size_t len = 0;
    struct tree **coma;

    signal(SIGINT, controlc);
    if (getline(&line, &len, stdin) == -1 || teststr(line, "exit\n") == 1) {
        my_putstr("exit\n");
        exit(EXIT_SUCCESS);
    }
    if (noinput(line) == 0)
        return 0;
    coma = init_tree(line);
    for (int i = 0; coma[i] != NULL; i++)
        ret = execution(envinfo, coma[i]->arg);
    return ret;
}
// valgrind
// faire le return
// error handling
/*
static int parent(char **argi, int i, int *pipefd, env_t *envinfo)
{
    int save2 = dup(0);
    char **arg = str_to_array(argi[i]);

    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    if (argi[i] != NULL) {
        pipe(pipefd);
        arg = str_to_array(argi[i]);
        if (my_setenv(envinfo, arg) == 0 || my_unsetenv(envinfo, arg) == 0)
            return 0;
        if (my_cd(arg, envinfo) != 0 || my_env(envinfo->env, arg[0]) == 0)
            return 0;
        //my_exec(arg, argi, envinfo, pipefd);
        dup2(save2, STDIN_FILENO);
        close(pipefd[1]);
    }
    return 0;
}
*/
