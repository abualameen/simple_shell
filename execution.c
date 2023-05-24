#include "main.h"

/**
 * execution - execute a command
 * @cpy: copy of the string of arguments
 * @arguments: number of arguments passed
 * Return: -1 on failure
 */
int execution(char *cpy)
{
	char *tokeeen;
	char *argv[32], *ptr[5];
	char store[125];
	int j = 0;

	tokeeen = strtok(cpy, " \n");
	if (tokeeen != NULL)
	{
		while (tokeeen)
		{
			argv[j] = tokeeen;
			j++;
			tokeeen = strtok(NULL, " \n");
		}
		argv[j] = NULL;
		if (checkstat(argv[0]) == 0)
		{
			if (pathfinder(ptr, store, argv[0]) == NULL)
                        {
                                perror("./hsh");
                                return (-1);
                        }
                        else
                        {
                                forknow(ptr[0], argv);
                        }
		}
		else
		{
			forknow(argv[0], argv);
		}
	}
	return (0);
}
