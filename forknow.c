#include "main.h"

/**
 * forknow - fork a command and execute it
 * @argument: name of the command
 * @arguments: rest of arguments
 * @index: arguments count
 */
void forknow(char *argument, char **arguments, int index)
{
	int k = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("child not born\n");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(argument, arguments, NULL) == -1)
		{
			perror("./shell");
			exit(1);
		}
		for (; k != index - 1; k++)
			free(arguments[k]);
		free(arguments);
	}
	else
	{
		wait(NULL);
	}
}
