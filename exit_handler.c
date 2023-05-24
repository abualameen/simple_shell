#include "main.h"
/**
 * exit_handler - handles exit status
 * @tks: tokens passed
 * Return: 0
 */

void exit_handler(char *tks[])
{
	int exitcode;

	if (tks[1] == NULL)
	{
		if (_strcom(tks[0], "exit") == 0)
		{
			exit(0);
		}
	}
	else
	{
		if (_strcom(tks[0], "exit") == 0)
		{
			if (tks[1] != NULL)
			{
				exitcode = _atoi(tks[1]);
				exit(exitcode);
			}
		}
	}
}
