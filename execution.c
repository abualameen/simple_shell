#include "main.h"

/**
 * execution - execute a command
 * @cpy: copy of the string of arguments
 * @arguments: number of arguments passed
 * Return: -1 on failure
 */
int execution(char *cpy, int arguments)
{
	char *tokeeen, **argv;
	int j = 0, k = 0;
	pid_t pid;

	tokeeen = strtok(cpy, " \n");
	argv = (char **)malloc(arguments * sizeof(char *));
	if (!argv)
		return (-1);
	if (tokeeen != NULL)
	{
		while (tokeeen)
		{
			argv[j] = (char *)malloc(strlen(tokeeen) * sizeof(char));
			argv[j] = tokeeen;
			j++;
			tokeeen = strtok(NULL, " \n");
		}
		argv[j] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("child not born\n");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("./shell");
				exit(1);
			}
			for (; k != j - 1; k++)
				free(argv[k]);
			free(argv);
		}
		else
		{
			wait(NULL);
		}
	}
}
