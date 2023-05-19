#include "main.h"
/**
 * propmt - prompt user for cmd 
 * Return: 0
 */

void prompt(void)
{
	static int first_time = 1;
	const char *CLEAR_SCREEN_ANSI;
	
	if (first_time)
	{
		CLEAR_SCREEN_ANSI = CLEAR_SCREEN;
		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}
	printf (":)");
}
