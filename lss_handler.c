#include "main.h"
int extend(void);
/**
 * lsss_handler - handles ls and env cases
 * @pts: paths frm PATH ENV VARIABLES
 * @tks: tokens tokenised
 * @k: int
 * @state: state in the logic 0 or 1
 * Return: void
 */

void lsss_handler(char *pts[], char *tks[], int k, int state)
{
	char *cpy_path;
	int e;
	/*extern char **environ;*/
	int status;
	pid_t pid;

	for (e = 0; e < k; e++)
	{
		cpy_path = malloc(_strlen(pts[e]) + _strlen(tks[0]) + 5);
		if (cpy_path == NULL)
		{
			perror("malloc error for cpy_path");
			exit(1);
		}
		_strcpy(cpy_path, pts[e]);
		_strcat(cpy_path, "/");
		_strcat(cpy_path, tks[0]);
		if (access(cpy_path, X_OK) == 0)
		{
			state = 1;
			break;
		}
	}
	if (state == 1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("child not born");
			exit(1);
		}
		else if (pid == 0)
		{
			if ((_strcom(tks[0], "ls") == 0))
			{
				if (tks[1] != NULL && (_strcom(tks[1], "-l") == 0))
				{
					execve(cpy_path, tks, environ);
					perror("execve error for token,path\n");
					exit(1);
				}
				else
				{
					execve(cpy_path, tks, environ);
					perror("execve error for token,path\n");
					exit(1);
				}
			}
			else if (_strcom(tks[0], "env") == 0)
			{
				execve(cpy_path, tks, environ);
				perror("execve error for token,path\n");
				exit(1);
			}
		}
		waitpid(pid, &status, 0);
	}
	free(cpy_path);
}

/**
 * extend - extends line
 * Return: 0
 */

int extend(void)
{
	return (0);
}
