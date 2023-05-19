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
	int j = 0;
	char *ptr[32];
	char store[256];

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
		if (checkstat(argv[0]) == 0)
		{
			printf("before entering pathfinder with %s\n", argv[0]);
			if (pathfinder(ptr, store, argv[0]) == NULL)
			{
				perror("./shhhhhell");
				return (-1);
			}
			else
			{
				forknow(ptr[0], argv, j);
			}
		}
		else
		{
			forknow(argv[0], argv, j);
		}
	}
	return (1);
}
