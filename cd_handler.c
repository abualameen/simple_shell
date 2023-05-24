#include "main.h"
int defend_line(void);
/**
 * cd_handler - handles changing directory case
 * @tks: tokens
 * @cwdd: previous dir
 * Return: 0
 */

int cd_handler(char *tks[], char cwdd[])
{
	int cd_r_val;
	char prev_dir[1025];

	if (_strcom(tks[0], "cd") == 0)
	{
		if (tks[1] == NULL)
		{
			cd_r_val =  chdir("/home/abu");
			if (cd_r_val != 0)
			{
				perror("cd 2command error");
				exit(1);
			}
			setenv("PWD", getcwd(NULL, 0), 1);
			_strcpy(prev_dir, cwdd);
			return (0);
		}
		else if (tks[1] != NULL && (_strcom(tks[1], "-") != 0))
		{
			cd_r_val = chdir(tks[1]);
			if (cd_r_val != 0)
			{
				perror("cd 3command error\n");
				exit(1);
			}
			setenv("PWD", getcwd(NULL, 0), 1);
			_strcpy(prev_dir, cwdd);
			return (0);
		}
		else if (tks[1] != NULL && _strcom(tks[1], "-") == 0)
		{
			if (_strlen(prev_dir) == 0)
			{
				perror("cd - error: you have not visited a prev dir\n");
				exit(1);
			}
			else
			{
				cd_r_val = chdir(prev_dir);
				if (cd_r_val != 0)
				{
					perror("cd command error 5\n");
					exit(1);
				}
				setenv("PWD", getcwd(NULL, 0), 1);
				_strcpy(prev_dir, cwdd);
				return (0);
			}
		}
	}
	_strcpy(prev_dir, cwdd);
	return (-1);
}

/**
 * defend_line - enxtends line
 * Return: 0
 */

int defend_line(void)
{
	return (0);
}
