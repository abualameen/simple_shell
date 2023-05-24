#include "main.h"
/**
 * _atoi - this function conv str to int
 * @s: function argument
 * Return: always 0
 */

int _atoi(char *s)
{
	int num = 0;
	int t;
	int count = 0;
	int r;
	int minus = 0;
	int i = 0;

	for (r = 0; s[r] != '\0'; r++)
	{
		count++;
	}
	for (t = 0; t < count; t++)
	{
		if (s[t] == '-')
		{
			minus = 1;
			i++;
		}
		else if (s[t] == '+')
		{
			i++;
		}
		else if (s[t] == ' ')
		{
			i++;
		}
		else if (s[t] >= 0 || s[t] <= 9)
		{
			num = num * 10 + (s[t] - 48);
			i++;
		}
	}
	if (minus == 1)
	{
		num = num * (-1);
	}

	return (num);
}
