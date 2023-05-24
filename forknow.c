#include "main.h"

/**
 * forknow - fork a command and execute it
 * @argument: name of the command
 * @arguments: rest of arguments
 */
void forknow(char *argument, char **arguments)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("./hsh");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(argument, arguments, environ) == -1)
		{
			perror("./hsh");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
