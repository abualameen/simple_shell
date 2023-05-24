#include "main.h"
/**
 * s_u_env_handler - handles setenv and unsetenv cases
 * @tks: tokens
 * Return: 0
 */

void s_u_env_handler(char *tks[])
{
	int setenv_r_val, unsetenv_r_val;

	if (_strcom(tks[0], "setenv") == 0)
	{
		setenv_r_val = setenv(tks[1], tks[2], 0);
		if (setenv_r_val != 0)
		{
			perror("setevnv error");
			exit(1);
		}
	}
	else
	{
		if (_strcom(tks[0], "unsetenv") == 0)
		{
			unsetenv_r_val = unsetenv(tks[1]);
			if (unsetenv_r_val != 0)
			{
				perror("setevnv error");
				exit(1);
			}
		}
	}
}
