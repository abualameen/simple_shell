#include "main.h"

/**
 * pathfinder - find path of command if exist
 * @ptr: array of arguments
 * @storage: store the new command path
 * @command: old command
 * Return: pointer to full path of command or NULL
 */
char *pathfinder(char **ptr, char *storage, char *command)
{
	char *path, *dir;
<<<<<<< HEAD
	char copy[600];
=======
	char copy[256];
>>>>>>> 89ece25 (test files)
	int i = 0, j;

	path = _getenv("PATH");
	_strcpy(copy, path);
	printf("copy of path%s\n", copy);
	dir = strtok(copy, ":");
	while (dir != NULL)
	{
		ptr[i] = _strcat(dir, command, storage);
		printf("before check stat of %s\n", ptr[i]);
		j = checkstat(ptr[i]);
		if (j == 1)
		{
			return (ptr[i]);
		}
		dir = strtok(NULL, ":");
		i++;
	}
	return (NULL);
}
