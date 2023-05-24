#include "main.h"
/*char prev_dir[1025];*/
int checker(void);
/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char **argv)
{
        char *paths = _getenv("PATH");
        char *paths_dir[1025];
        char *toks[4000];
        char c_wd[1025];
        int k = 0;
        char *path_dir;
        pid_t pid1;
        int state;
        int status1;
        int j, r;
        (void)argc;
        (void)argv;

        path_dir = _strtok(paths, ":");
        while (path_dir != NULL)
        {
                paths_dir[k] = path_dir;
                k++;
                path_dir = _strtok(NULL, ":");
        }
        while (1)
        {
                prompt();
                fflush(stdout);
                j = read_lin(toks);
                if (_strcom(toks[0], "exit") == 0)
                {
                        exit_handler(toks);
                }
                else if (_strcom(toks[0], "setenv") == 0)
                {
                        s_u_env_handler(toks);
                }
                else if (_strcom(toks[0], "cd") == 0)
                {
                        getcwd(c_wd, sizeof(c_wd));
                        cd_handler(toks, c_wd);
                }
                state = 0;
                if (toks[0][0] == '/')
                {
                        pid1 = fork();
                        if (pid1 == -1)
                        {
                                printf("second child not born");
                                exit(1);
                        }
                        else if (pid1 == 0)
                        {
                                execve(toks[0], toks, environ);
                                perror("execve error for full path not search\n");
                                exit(1);
                        }
                }
                else
                {
                        lsss_handler(paths_dir, toks, k, state);
                }
                waitpid(pid1, &status1, 0);
        }
        for (r = 0; r < j; r++)
        {
                free(toks[r]);
        }
        free(paths);
        return (0);
}

/**
 * checker - checks
 * Return: 0
 */

int checker(void)
{
        return (0);
}
