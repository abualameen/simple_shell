#include "main.h"

/**
 * _getenv - search for key in current env
 * @name: name of the key
 * Return: pointer to value of the key
 */
char *_getenv(const char *name)
{
	int i, j, k;

	i = 0;
	while (environ[i] != NULL)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] == environ[i][j])
			{
				if (k != 1)
				{
					k = 1;
				}
				continue;
			}
			if (name[j] != environ[i][j] && environ[i][j] == '=')
			{
				break;
			}
			k = 0;
			break;
		}
		if (k == 1)
		{
			return (&environ[i][j + 1]);
		}
		i++;
	}
	return (NULL);
}
