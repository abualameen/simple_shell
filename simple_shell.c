#include "main.h"
/**
* main - entry point
*
* Return: 0
*/
int main(void)
{
	char *lineptr;
	size_t n = 32;
	ssize_t read_line;
	char *token;
	char *argv[1025];
	const char *delim;
	int j;
	int t;
	pid_t pid;
	delim = " \n";
	while (1)
	{
		j = 0;
		printf("$ ");
		lineptr = malloc(sizeof(char) * n);
		read_line = getline(&lineptr, &n, stdin);
		if (read_line == -1)
		{
			perror("readline failed");
			exit(1);
		}
		token = strtok(lineptr, delim);
		while (token)
		{
			argv[j++] = token;
			/*printf("%s", token);*/
			token = strtok(NULL, delim);
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
			t = execve(argv[0], argv, NULL);
			if (t = -1)
			{
				perror("execve error");
				exit(1);
			}
		}	
		else
		{
			wait(NULL);
		}
		free(lineptr);
	}
	return (0);
}
