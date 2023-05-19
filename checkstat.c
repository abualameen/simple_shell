#include "main.h"

/**
 * checkstat - check if program exist
 * @command: name of the program
 * Return: 1 on success else 0
 */
int checkstat(char *command)
{
	struct stat st;

	if (stat(command, &st) == 0)
	{
		printf("found\n");
		return (1);
	}
	else
	{
		printf("notfound\n");
		return (0);
	}
}
