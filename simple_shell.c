#include "main.h"
/**
 * main - entry point
 * @argc: arg count
 * @argc: arg vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *paths = _getenv("PATH");
	char *paths_dir[1025];
	char *toks[4000];
	int k = 0;
	char *path_dir; 
	pid_t pid1;
	int state;
	int status1;
	extern char **environ;
	(void)argc;
	(void)argv;

	path_dir = strtok(paths, ":");
	while(path_dir != NULL)
	{
		paths_dir[k] = path_dir;
		k++;
		path_dir = strtok(NULL, ":");
	}
	while (1)
	{
		prompt();
		fflush(stdout);
		read_lin(toks);
		if (_strcom(toks[0], "exit") == 0)
		{
			break;
		}
		state = 0;
		if (toks[0][0] =='/')
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
	
	free(paths);
	return (0);
}
