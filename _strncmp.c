#include "main.h"
/**
 * _strncmp - compares n number of character
 * @str1: string 1
 * @str2: string 2
 * @n: numb range
 * Return: 0
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t r;

	for (r = 0; r < n; r++)
	{
		if (str1[r] != str2[r])
		{
			return (str1[r] - str2[r]);
		}
		if (str1[r] == '\0' || str2[r] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
