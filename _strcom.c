#include "main.h"

/**
 * _strcom - compares two str
 * @str1: first string
 * @str2: seconde string
 * Return: 0
 */



int _strcom(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

